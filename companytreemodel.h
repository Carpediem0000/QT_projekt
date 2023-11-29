#ifndef COMPANYTREEMODEL_H
#define COMPANYTREEMODEL_H

#include <QStandardItemModel>
#include <QStandardItem>
#include "main_class/Company.h"

class CompanyTreeModel : public QStandardItemModel
{
public:
    CompanyTreeModel(Company* company, QObject* parent = nullptr);

    void setupModelData(Company* company);
};

#endif // COMPANYTREEMODEL_H
