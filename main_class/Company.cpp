#include "Company.h"

Company::Company()
{
    try
    {
        loadDivisionFromFile();
    }
    catch (...)
    {
        cout << "File error...\n";
    }
}

Company::~Company()
{
    for (auto& div : division) {
        delete div;
    }
}


void Company::addEmployee(shared_ptr<Employee> obj, int key)
{
    if (key >= 0 && key < division.size())
    {
        division[key]->addEmployee(move(obj));
    }
}

void Company::removeEmployee(int ind)
{
    for (auto obj: division) {
        obj->removeEmployee(ind);
    }
}

void Company::addDivision(Division* obj)
{
    division.push_back(obj);
}

void Company::removeDivision(int ind)
{
    if (ind >= 0 && ind < division.size()) {
        delete division[ind];
        division.erase(division.begin()+ind);
    }
}

QString Company::getTypeObject(int key)const
{
    for (const auto& obj : division) {
        const auto& employees = obj->getEmployees();
        std::map<int, shared_ptr<Employee>>::const_iterator it = employees.find(key);
        if (it != employees.end()) {
            //std::cout << it->second->type() << std::endl;
            return QString::fromStdString(it->second->type());
        }
    }
    return QString();
}

std::shared_ptr<Employee> Company::getObjWhereKey(int key) const
{
    for (const auto& obj : division) {
        const auto& employees = obj->getEmployees();
        auto it = employees.find(key);

        if (it != employees.end()) {
            // Элемент найден, возвращаем shared_ptr<Employee>
            return it->second;
        }
    }

    // Элемент не найден, возвращаем nullptr или другое значение по умолчанию
    return nullptr;
}

void Company::loadDivisionFromFile()
{
    std::ifstream file("Company.bin", std::ios::binary);
    if (file.is_open()) {

        int numDivision;
        file.read(reinterpret_cast<char*>(&numDivision), sizeof(numDivision));

        for (int i = 0; i < numDivision; i++)
        {
            Division* div = new Division();
            division.push_back(div);
        }

        for (int i = 0; i < numDivision; i++) {
            division[i]->loadBinary(file);
        }

        file.close();
    }
}

void Company::saveDivisionToFile()
{
    std::ofstream file("Company.bin", std::ios::binary | std::ios::trunc);
    if (file.is_open()) {

        int numDivision = static_cast<int>(division.size());
        file.write(reinterpret_cast<const char*>(&numDivision), sizeof(numDivision));

        for (int i = 0; i < numDivision; i++)
        {
            division[i]->saveBinary(file);
        }

        file.close();
    }
}

void Company::show() const
{
    for (const auto& div : division) {
        div->show();
    }
}

vector <Division*> Company::getDivision()const
{
    return division;
}

QVBoxLayout* Company::createGroupBoxesLayout()
{
    QScrollArea* scrollArea = new QScrollArea;
    QWidget* scrollWidget = new QWidget;
    QVBoxLayout* mainLayout = new QVBoxLayout(scrollWidget);

    for (Division* division1 : division)
    {
        QGroupBox* groupBox = new QGroupBox(QString::fromStdString(division1->getName()));
        QListWidget* listWidget = new QListWidget;

        // Получаем список сотрудников из Division
        const std::map<int, std::shared_ptr<Employee>>& employees = division1->getEmployees();

        // Добавляем каждого сотрудника в QListWidget
        for (const auto& pair : employees)
        {
            const Employee* employee = pair.second.get();
            QString employeeInfo = QString::fromStdString(employee->getName()) + " " + QString::fromStdString(employee->getSurname());
            listWidget->addItem(employeeInfo);
        }

        // Размещаем QListWidget внутри QGroupBox
        QVBoxLayout* groupBoxLayout = new QVBoxLayout;
        groupBoxLayout->addWidget(listWidget);
        groupBox->setLayout(groupBoxLayout);

        // Добавляем QGroupBox в основной макет
        mainLayout->addWidget(groupBox);
    }

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollWidget);

    return mainLayout;
}
