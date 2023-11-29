#ifndef COMPANY_H
#define COMPANY_H

#include "Division.h"
#include <vector>

class Company
{
    vector <Division*> division;
public:
    Company();
    ~Company();

    void addEmployee(shared_ptr<Employee> obj, int key);
    void removeEmployee(int ind, int key);

    void addDivision(Division* obj);
    void removeDivision(int ind);

    vector <Division*> getDivision()const;

    void loadDivisionFromFile();
    void saveDivisionToFile();

    void show()const;
};

#endif // COMPANY_H
