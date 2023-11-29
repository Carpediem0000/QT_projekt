#include "Division.h"

Division::Division()
{
    this->name = "Undefined";
}

Division::Division(string name)
{
    setName(name);
}

Division::~Division()
{

}

void Division::setName(string name)
{
    this->name = name;
}

string Division::getName() const
{
    return name;
}

void Division::addEmployee(shared_ptr<Employee> obj)
{
    int index = obj->getIndex();
    employees[index] = move(obj);
}

void Division::removeEmployee(int ind)
{
    auto it = employees.find(ind);
    if (it != employees.end()) {
        employees.erase(it);
    }
}

void Division::saveBinary(ofstream& file) const
{
    int nameLength = static_cast<int>(name.length());
    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    file.write(name.c_str(), nameLength);

    // Затем сохраняем количество сотрудников
    int numEmployees = static_cast<int>(employees.size());
    file.write(reinterpret_cast<const char*>(&numEmployees), sizeof(numEmployees));

    // Теперь сохраняем каждого сотрудника
    for (const auto& pair : employees) {
        // Сначала сохраняем индекс сотрудника
        int index = pair.first;
        file.write(reinterpret_cast<const char*>(&index), sizeof(index));

        // Сохраняем тип объекта
        int typeSize = static_cast<int>(pair.second->type().size());
        file.write(reinterpret_cast<const char*>(&typeSize), sizeof(typeSize));
        file.write(pair.second->type().c_str(), typeSize + 1);

        // Затем сохраняем данные сотрудника
        pair.second->saveBinary(file);
    }
}

void Division::loadBinary(ifstream& file)
{
    // Загрузка длины строки и самой строки
    int nameLength;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

    // Загрузка названия подразделения
    char* buffer = new char[nameLength + 1];  // +1 для завершающего нуля
    file.read(buffer, nameLength);
    buffer[nameLength] = '\0';  // Завершаем строку нулем
    name = buffer;
    delete[] buffer;

    // Загрузка количества сотрудников
    int numEmployees;
    file.read(reinterpret_cast<char*>(&numEmployees), sizeof(numEmployees));

    // Загрузка каждого сотрудника
    for (int i = 0; i < numEmployees; ++i) {
        // Загрузка индекса сотрудника
        int index;
        file.read(reinterpret_cast<char*>(&index), sizeof(index));

        // Создание нового сотрудника и загрузка его данных
        int typeSize;
        file.read(reinterpret_cast<char*>(&typeSize), sizeof(typeSize));
        char typeBuffer[256];
        file.read(typeBuffer, typeSize + 1);
        string type = typeBuffer;

        if (type == "FullTimeEmployee")
        {
            shared_ptr<Employee> employee1 = make_unique<FullTimeEmployee>();
            (*employee1).loadBinary(file);
            // Добавление сотрудника в map
            employees[index] = move(employee1);
        }
        else if (type == "ContractEmployee")
        {
            shared_ptr<Employee> employee2 = make_unique<ContractEmployee>();
            (*employee2).loadBinary(file);
            // Добавление сотрудника в map
            employees[index] = move(employee2);
        }
    }
}

void Division::show() const
{
    cout << "Division: " << name << endl;
    cout << "Employees:" << endl;
    for (const auto& pair : employees) {
        //cout << "  " << pair.first << ": " << pair.second->getName() << endl;
        cout << "----------------------------------\n";
        pair.second->show();
        cout << "----------------------------------\n";
    }
}

map<int, shared_ptr<Employee>> Division::getEmployees()const
{
    return employees;
}
