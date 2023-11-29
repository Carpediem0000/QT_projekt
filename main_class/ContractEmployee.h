#ifndef CONTRACTEMPLOYEE_H
#define CONTRACTEMPLOYEE_H

#include "Employee.h"

class ContractEmployee : public Employee
{
    double hourlyRate; //Часовая ставка
    int hoursWorked; // ск часов работает
public:
    ContractEmployee();
    ContractEmployee(string name, string surname, string position, double hourlyRate, int hoursWorked);

    void setHour(int hour);
    void setHourlyRate(double hourlyRate);

    int getHour()const;
    double getHourlyRate()const;

    string type()const override;

    void show()const override;

    void saveBinary(ofstream& file)const override;
    void loadBinary(ifstream& file) override;
};

#endif // CONTRACTEMPLOYEE_H
