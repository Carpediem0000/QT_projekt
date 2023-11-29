#include "Fulltimeemployee.h"

FullTimeEmployee::FullTimeEmployee()
{
    this->salary = 0;
    this->bonus = 0;
}

FullTimeEmployee::FullTimeEmployee(string name, string surname, string position, double salary, double bonus)
    :Employee(name, surname, position)
{
    setSalary(salary);
    setBonus(bonus);
}

void FullTimeEmployee::setSalary(double salary)
{
    this->salary = salary;
}

void FullTimeEmployee::setBonus(double bonus)
{
    this->bonus = bonus;
}

double FullTimeEmployee::getSalary() const
{
    return salary;
}

double FullTimeEmployee::getBonus() const
{
    return bonus;
}

string FullTimeEmployee::type() const
{
    return "FullTimeEmployee";
}

void FullTimeEmployee::show() const
{
    cout << "\t" << type() << endl;
    Employee::show();
    cout << "Salary: " << salary << endl;
    cout << "Bonus: " << bonus << endl;
}

void FullTimeEmployee::saveBinary(ofstream& file) const
{
    Employee::saveBinary(file);
    file.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
    file.write(reinterpret_cast<const char*>(&bonus), sizeof(bonus));
}

void FullTimeEmployee::loadBinary(ifstream& file)
{
    Employee::loadBinary(file);
    file.read(reinterpret_cast<char*>(&salary), sizeof(salary));
    file.read(reinterpret_cast<char*>(&bonus), sizeof(bonus));
}
