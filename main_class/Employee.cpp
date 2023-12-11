#include "Employee.h"

int Employee::INT = 1;

Employee::Employee()
{
    this->index = INT;
    INT++;
    setName("undefined");
    setSurname("undefined");
    setPosition("undefined");
    //this->status = true;
}

Employee::Employee(string name, string surname, string position)
{
    this->index = INT;
    INT++;
    setName(name);
    setSurname(surname);
    setPosition(position);
    //this->status = true;
}

Employee::~Employee()
{
}

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setSurname(string surname)
{
    this->surname = surname;
}

void Employee::setPosition(string position)
{
    this->position = position;
}


//void Employee::changeStatus()
//{
//    if (status)
//        this->status = false;
//    else
//        this->status = true;
//}


void Employee::setStaticCounter(int ind)
{
    INT = ind;
}

const int Employee::getStaticCounter()
{
    return INT;
}

string Employee::getName() const
{
    return name;
}

string Employee::getSurname() const
{
    return surname;
}

string Employee::getPosition() const
{
    return position;
}

//bool Employee::getStatus() const
//{
//    return status;
//}


int Employee::getIndex() const
{
    return index;
}

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\u001b[31m"
#define GREEN_COLOR "\u001b[32m"

void Employee::show() const
{
    cout << "Index: #" << index << endl;
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Position: " << position << endl;
    cout << "Status: ";
//    if (status)
//    {
//        cout << GREEN_COLOR << "work" << RESET_COLOR << endl;
//    }
//    else
//    {
//        cout << RED_COLOR << "weekend" << RESET_COLOR << endl;
//    }
}

void Employee::saveBinary(ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&index), sizeof(index));

    // Записываем размер строки и саму строку, включая нулевой символ
    int nameSize = static_cast<int>(name.size());
    file.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    file.write(name.c_str(), nameSize + 1);

    int surnameSize = static_cast<int>(surname.size());
    file.write(reinterpret_cast<const char*>(&surnameSize), sizeof(surnameSize));
    file.write(surname.c_str(), surnameSize + 1);

    int positionSize = static_cast<int>(position.size());
    file.write(reinterpret_cast<const char*>(&positionSize), sizeof(positionSize));
    file.write(position.c_str(), positionSize + 1);

    //file.write(reinterpret_cast<const char*>(&status), sizeof(status));
}


void Employee::loadBinary(ifstream& file) {
    file.read(reinterpret_cast<char*>(&index), sizeof(index));

    // Читаем размер строки и саму строку
    int nameSize;
    file.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    char nameBuffer[256];
    file.read(nameBuffer, nameSize + 1);
    name = nameBuffer;

    int surnameSize;
    file.read(reinterpret_cast<char*>(&surnameSize), sizeof(surnameSize));
    char surnameBuffer[256];
    file.read(surnameBuffer, surnameSize + 1);
    surname = surnameBuffer;

    int positionSize;
    file.read(reinterpret_cast<char*>(&positionSize), sizeof(positionSize));
    char positionBuffer[256];
    file.read(positionBuffer, positionSize + 1);
    position = positionBuffer;

    //file.read(reinterpret_cast<char*>(&status), sizeof(status));
}
