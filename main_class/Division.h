#ifndef DIVISION_H
#define DIVISION_H

#include "ContractEmployee.h"
#include "FullTimeEmployee.h"
#include <map>
#include <memory>

class Division
{
    string name;
    map<int, shared_ptr<Employee>> employees;

public:
    Division();
    Division(string name);
    ~Division();

    void setName(string name);
    string getName()const;

    void addEmployee(shared_ptr<Employee> obj);
    void removeEmployee(int ind);

    map<int, shared_ptr<Employee>> getEmployees()const;

    void saveBinary(ofstream& file)const;
    void loadBinary(ifstream& file);

    void show()const;
};
#endif // DIVISION_H
