#include "companywidget.h"

CompanyWidget::CompanyWidget(QWidget *parent)
    : QWidget{parent}
{
    this->company = new Company();
    setupUI();

//    this->company->addDivision(new Division("IT Division"));
//    this->company->addDivision(new Division("Book Division"));

//    shared_ptr<Employee> a1 = make_unique<ContractEmployee>("Vanya", "Bones", "It_spesialist", 120, 4);
//    shared_ptr<Employee> a2 = make_unique<ContractEmployee>("Vanya", "Bone", "It_speist", 150, 7);
//    shared_ptr<Employee> a3 = make_unique<ContractEmployee>("Vanya", "Boes", "It_", 90, 6);
//    shared_ptr<Employee> a4 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);
//    shared_ptr<Employee> a8 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);
//    shared_ptr<Employee> a9 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);
//    shared_ptr<Employee> a10 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);
//    shared_ptr<Employee> a11 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);
//    shared_ptr<Employee> a12 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);
//    shared_ptr<Employee> a13 = make_unique<ContractEmployee>("Vanya", "Ones", "Spesialist", 200, 4);

//    shared_ptr<Employee> a5 = make_unique<FullTimeEmployee>("Vanya", "Ones", "Spesialist", 25000, 150);
//    shared_ptr<Employee> a6 = make_unique<FullTimeEmployee>("Vanya", "Ones", "Nikto", 5000);
//    shared_ptr<Employee> a7 = make_unique<FullTimeEmployee>("Vanya", "Ones", "Director", 125000, 15000);

//    this->company->addEmployee(a1, 0);
//    this->company->addEmployee(a3, 0);
//    this->company->addEmployee(a5, 0);
//    this->company->addEmployee(a7, 0);

//    this->company->addEmployee(a8, 0);
//    this->company->addEmployee(a9, 0);
//    this->company->addEmployee(a10, 0);
//    this->company->addEmployee(a11, 0);
//    this->company->addEmployee(a12, 0);
//    this->company->addEmployee(a13, 0);

//    this->company->addEmployee(a4, 1);
//    this->company->addEmployee(a2, 1);
//    this->company->addEmployee(a6, 1);

//    this->company->saveDivisionToFile();
}

QString CompanyWidget::getCurrentItemText()const
{
    for (QGroupBox* groupBox : groupBoxex) {
        QListWidget* listWidget = groupBox->findChild<QListWidget *>();

        if (listWidget) {
            if (!listWidget->selectedItems().isEmpty()){
                    QListWidgetItem *selectedItem = listWidget->currentItem();

                    if (selectedItem) {
                        return selectedItem->statusTip();
                    }
            }
        }
    }

    // Если ни в одном из группбоксов нет выбранных элементов, возвращаем пустую строку
    return QString();
}

QString CompanyWidget::getCurrentItemType()const
{
    for (QGroupBox* groupBox : groupBoxex) {
        QListWidget* listWidget = groupBox->findChild<QListWidget *>();

        if (listWidget) {
            if (!listWidget->selectedItems().isEmpty()){
                    QListWidgetItem *selectedItem = listWidget->currentItem();

                    if (selectedItem) {
                        return company->getTypeObject(selectedItem->statusTip().toInt());
                    }
            }
        }
    }

    // Если ни в одном из группбоксов нет выбранных элементов, возвращаем пустую строку
    return QString();
}

std::shared_ptr<Employee> CompanyWidget::getObjWhereKey(int key)const
{
    return company->getObjWhereKey(key);
}

void CompanyWidget::removeEmployee(int ind)
{
    this->company->removeEmployee(ind);
    this->company->saveDivisionToFile();
}

void CompanyWidget::addDivison(QString name)
{
    Division* obj = new Division(name.toStdString());
    company->addDivision(obj);
}

void CompanyWidget::removeDivision(int ind)
{
    company->removeDivision(ind);
}

void CompanyWidget::save()const
{
    this->company->saveDivisionToFile();
}

void CompanyWidget::addEmployee(shared_ptr<Employee> obj, int key)
{
    company->addEmployee(obj, key);
}

QVector<QString> CompanyWidget::getNameDivison()const
{
    QVector<QString> arr;
    for(auto obj : company->getDivision())
    {
        arr.push_back(QString::fromStdString(obj->getName()));
    }
    return arr;
}

void CompanyWidget::searchItem(QString text)const
{
    for (QGroupBox* groupBox : groupBoxex) {
        QListWidget* listWidget = groupBox->findChild<QListWidget *>();

        for (int i = 1; i < listWidget->count(); ++i) {
            QListWidgetItem* item = listWidget->item(i);
            bool shouldHide = !item->text().contains(text, Qt::CaseInsensitive);
            item->setHidden(shouldHide);
        }
    }
}

void CompanyWidget::sort(Qt::SortOrder order)
{
    for (QGroupBox* groupBox : groupBoxex) {
        QListWidget* listWidget = groupBox->findChild<QListWidget *>();

        QListWidgetItem* firstItem = listWidget->item(0);
        listWidget->takeItem(0);

        listWidget->sortItems(order);

        listWidget->insertItem(0, firstItem);
    }
}
#include <QMessageBox>
#include <QFont>
void CompanyWidget::handleItemDoubleClicked(QListWidgetItem* item)
{
    //QMessageBox::information(this, "Item Double Clicked", "You double-clicked: " + item->text());

    QMessageBox messageBox;
    messageBox.setWindowTitle("Info");

    int index = getCurrentItemText().toInt();
    std::shared_ptr<Employee> obj = getObjWhereKey(index);
    QString type = QString::fromStdString(obj->type());

    if (type == QString("FullTimeEmployee"))
    {
        std::shared_ptr<FullTimeEmployee> conractempl = std::dynamic_pointer_cast<FullTimeEmployee>(obj);
        if (conractempl){
            QString name = QString::fromStdString(conractempl->getName());
            QString surName = QString::fromStdString(conractempl->getSurname());
            QString position = QString::fromStdString(conractempl->getPosition());
            QString salary = QString::number(conractempl->getSalary());
            QString bonus = QString::number(conractempl->getBonus());

            messageBox.setText("Name: "+name+"\n"+"Surname: "+surName+"\n"+"Position: "+position+"\n"+
                                          "Salary: "+salary+" $\n"+"Bonus: "+bonus+" $");
        }
        else return;
    }
    else if (type == QString("ContractEmployee"))
    {
        std::shared_ptr<ContractEmployee> conractempl = std::dynamic_pointer_cast<ContractEmployee>(obj);
        if (conractempl){
            QString name = QString::fromStdString(conractempl->getName());
            QString surName = QString::fromStdString(conractempl->getSurname());
            QString position = QString::fromStdString(conractempl->getPosition());
            QString rate = QString::number(conractempl->getHourlyRate());
            QString hourInDay = QString::number(conractempl->getHour());

            messageBox.setInformativeText("Name: "+name+"\n"+"Surname: "+surName+"\n"+"Position: "+position+"\n"+
                                          "Hour rate: "+rate+" $\n"+"Hour in day: "+hourInDay);
        }
        else return;
    }

    QFont font = messageBox.font();
    font.setPointSize(16);
    messageBox.setFont(font);

    messageBox.setFixedSize(QSize(400, 200));

    // Убираем кружок с восклицательным знаком
    messageBox.setIcon(QMessageBox::NoIcon);

    // Добавляем кнопку "ОК"
    messageBox.addButton(QMessageBox::Ok);

    // Отображаем диалоговое окно
    messageBox.exec();
}

void CompanyWidget::setupUI()
{
    QScrollArea* scrollArea = new QScrollArea(this);
    QWidget* scrollWidget = new QWidget;
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollWidget);

    for (Division* division : company->getDivision()) {
        QGroupBox* groupBox = new QGroupBox(QString::fromStdString(division->getName()));
        QVBoxLayout* groupBoxLayout = new QVBoxLayout(groupBox);

        QListWidget* listWidget = new QListWidget;
        listWidget->setFocusPolicy(Qt::ClickFocus);
        listWidget->setStyleSheet("QListWidget::item:selected { background-color: rgba(62, 113, 207, 50); color: black; }"
                                  "QListWidget::item:!selected { color: black; }");
        // Добавление сотрудников в QListWidget
        const std::map<int, std::shared_ptr<Employee>>& employees = division->getEmployees();

        QString hat = QString("Surname").leftJustified(15, ' ') + QString("Name").leftJustified(15, ' ') + QString("Position").leftJustified(15, ' ');
        listWidget->addItem(hat);
        listWidget->item(0)->setFlags(listWidget->item(0)->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEnabled);

        int i = 1;
        for (const auto& pair : employees) {
            const Employee* employee = pair.second.get();
            QString employeeInfo = QString::fromStdString(employee->getSurname()).leftJustified(15, ' ') +
                                   QString::fromStdString(employee->getName()).leftJustified(15, ' ') +
                                   QString::fromStdString(employee->getPosition()).leftJustified(15, ' ');
            listWidget->addItem(employeeInfo);
            listWidget->item(i)->setStatusTip(QString::number(employee->getIndex()));
            i++;
        }

        connect(listWidget, &QListWidget::itemDoubleClicked, this, &CompanyWidget::handleItemDoubleClicked);

        groupBoxLayout->addWidget(listWidget);
        scrollLayout->addWidget(groupBox);
        groupBoxex.push_back(groupBox);
    }

    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);

    setLayout(new QVBoxLayout(this));
    layout()->addWidget(scrollArea);
}
