#include "Company.h"

Company::Company()
{
    try
    {
        loadDivisionFromFile();
    }
    catch (...)
    {
        cout << "File error...\n";
    }
}

Company::~Company()
{
    for (auto& div : division) {
        delete div;
    }
}


void Company::addEmployee(shared_ptr<Employee> obj, int key)
{
    if (key >= 0 && key < division.size())
    {
        division[key]->addEmployee(move(obj));
    }
}

void Company::removeEmployee(int ind, int key)
{
    if (key >= 0 && key < division.size())
    {
        division[key]->removeEmployee(ind);
    }
}

void Company::addDivision(Division* obj)
{
    division.push_back(obj);
}

void Company::removeDivision(int ind)
{
    if (ind >= 0 && ind < division.size()) {
        delete division[ind];
        division.erase(division.begin() + ind);
    }
}

void Company::loadDivisionFromFile()
{
    std::ifstream file("Company.bin", std::ios::binary);
    if (file.is_open()) {

        int numDivision;
        file.read(reinterpret_cast<char*>(&numDivision), sizeof(numDivision));

        for (int i = 0; i < numDivision; i++)
        {
            Division* div = new Division();
            division.push_back(div);
        }

        for (int i = 0; i < numDivision; i++) {
            division[i]->loadBinary(file);
        }

        file.close();
    }
}

void Company::saveDivisionToFile()
{
    std::ofstream file("Company.bin", std::ios::binary | std::ios::trunc);
    if (file.is_open()) {

        int numDivision = static_cast<int>(division.size());
        file.write(reinterpret_cast<const char*>(&numDivision), sizeof(numDivision));

        for (int i = 0; i < numDivision; i++)
        {
            division[i]->saveBinary(file);
        }

        file.close();
    }
}

void Company::show() const
{
    for (const auto& div : division) {
        div->show();
    }
}

vector <Division*> Company::getDivision()const
{
    return division;
}
