#include "ContractEmployee.h"

ContractEmployee::ContractEmployee()
{
    this->hourlyRate = 0;
    this->hoursWorked = 0;
}

ContractEmployee::ContractEmployee(string name, string surname, string position, double hourlyRate, int hoursWorked)
    :Employee(name, surname, position)
{
    setHour(hoursWorked);
    setHourlyRate(hourlyRate);
}

void ContractEmployee::setHour(int hour)
{
    this->hoursWorked = hour;
}

void ContractEmployee::setHourlyRate(double hourlyRate)
{
    this->hourlyRate = hourlyRate;
}

int ContractEmployee::getHour() const
{
    return hoursWorked;
}

double ContractEmployee::getHourlyRate() const
{
    return hourlyRate;
}

string ContractEmployee::type() const
{
    return "ContractEmployee";
}

void ContractEmployee::show() const
{
    cout << "\t" << type() << endl;
    Employee::show();
    cout << "Hours worked: " << hoursWorked << endl;
    cout << "Hourly rate: " << hourlyRate << endl;
}

void ContractEmployee::saveBinary(ofstream& file) const
{
    Employee::saveBinary(file);
    file.write(reinterpret_cast<const char*>(&hoursWorked), sizeof(hoursWorked));
    file.write(reinterpret_cast<const char*>(&hourlyRate), sizeof(hourlyRate));
}

void ContractEmployee::loadBinary(ifstream& file)
{
    Employee::loadBinary(file);
    file.read(reinterpret_cast<char*>(&hoursWorked), sizeof(hoursWorked));
    file.read(reinterpret_cast<char*>(&hourlyRate), sizeof(hourlyRate));
}
