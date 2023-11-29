#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Employee
{
private:
    static int INT;
protected:
    int index;
    string name;
    string surname;
    string position;
    bool status;
public:
    Employee();
    Employee(string name, string surname, string position);
    virtual ~Employee();

    void setName(string name);
    void setSurname(string surname);
    void setPosition(string position);
    void changeStatus();
    static void setStaticCounter(int ind);
    const static int getStaticCounter();

    string getName()const;
    string  getSurname()const;
    string getPosition()const;
    bool getStatus()const;
    int getIndex()const;

    virtual string type()const = 0;

    virtual void show()const;

    virtual void saveBinary(ofstream& file)const;
    virtual void loadBinary(ifstream& file);
};

#endif // EMPLOYEE_H
