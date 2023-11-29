#include "companytreemodel.h"

CompanyTreeModel::CompanyTreeModel(Company* company, QObject* parent)
    : QStandardItemModel(parent)
{
    setupModelData(company);
}

void CompanyTreeModel::setupModelData(Company* company)
{
    clear();

    if (!company)
        return;

    // Создайте корневой элемент для компании
    QStandardItem* rootItem = new QStandardItem("Company");

    // Добавьте отделы в корневой элемент
    for (Division* division : company->getDivision()) {
        QStandardItem* divisionItem = new QStandardItem(QString::fromStdString(division->getName()));
        rootItem->appendRow(divisionItem);

        // Добавьте сотрудников в отдел
        for (const auto& pair : division->getEmployees()) {
            const std::shared_ptr<Employee>& employee = pair.second;
            QStandardItem* employeeItem = new QStandardItem(QString::fromStdString(employee->getName()) + " " + QString::fromStdString(employee->getSurname()));
            divisionItem->appendRow(employeeItem);
        }
    }

    // Установите корневой элемент для модели
    setItem(0, rootItem);
}
