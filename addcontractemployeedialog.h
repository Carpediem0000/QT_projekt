#ifndef ADDCONTRACTEMPLOYEEDIALOG_H
#define ADDCONTRACTEMPLOYEEDIALOG_H

#include <QDialog>
#include "companywidget.h"
#include <QValidator>

namespace Ui {
class AddContractEmployeeDialog;
}

class AddContractEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    AddContractEmployeeDialog(CompanyWidget* companyWidget, QWidget *parent = nullptr);
    ~AddContractEmployeeDialog();

private slots:
    void on_BackpushButton_clicked();

    void on_AddpushButton_clicked();

private:
    Ui::AddContractEmployeeDialog *ui;
    CompanyWidget* companyWidget;
};

#endif // ADDCONTRACTEMPLOYEEDIALOG_H
