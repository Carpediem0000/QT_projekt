#ifndef COMPANYWIDGET_H
#define COMPANYWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QString>
#include <QVector>
#include <QSignalMapper>
#include "main_class/Company.h"

class CompanyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CompanyWidget(QWidget *parent = nullptr);

    QString getCurrentItemText()const;
    QString getCurrentItemType()const;

    std::shared_ptr<Employee> getObjWhereKey(int key)const;

    void removeEmployee(int ind);
    void addEmployee(shared_ptr<Employee> obj, int key);
    void addDivison(QString name);
    void removeDivision(int ind);
    void save()const;
    void searchItem(QString text)const;
    void sort(Qt::SortOrder order = Qt::AscendingOrder);

    QVector<QString> getNameDivison()const;

private slots:
    void handleItemDoubleClicked(QListWidgetItem* item);

private:
    QVector<QGroupBox*> groupBoxex;
    Company* company;

    void setupUI();
};

#endif // COMPANYWIDGET_H
