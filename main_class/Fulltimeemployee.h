#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FullTimeEmployee : public Employee
{
    double salary;
    double bonus;
public:
    FullTimeEmployee();
    FullTimeEmployee(string name, string surname, string position, double salary, double bonus = 0);

    void setSalary(double salary);
    void setBonus(double bonus);

    double getSalary()const;
    double getBonus()const;

    string type()const override;

    void show()const override;

    void saveBinary(ofstream& file)const override;
    void loadBinary(ifstream& file) override;
};

#endif // FULLTIMEEMPLOYEE_H
