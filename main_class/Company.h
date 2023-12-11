#ifndef COMPANY_H
#define COMPANY_H

#include "Division.h"
#include <vector>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include <QScrollArea>
#include <QString>

class Company
{
    vector <Division*> division;
public:
    Company();
    ~Company();

    void addEmployee(shared_ptr<Employee> obj, int key);
    void removeEmployee(int ind);

    void addDivision(Division* obj);
    void removeDivision(int ind);

    vector <Division*> getDivision()const;
    QString getTypeObject(int key)const;
    std::shared_ptr<Employee> getObjWhereKey(int key)const;

    void loadDivisionFromFile();
    void saveDivisionToFile();

    void show()const;

    QVBoxLayout* createGroupBoxesLayout();
};

#endif // COMPANY_H
