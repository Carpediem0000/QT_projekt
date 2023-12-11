#ifndef EDITCONTRACTEMPLOYEEDIALOG_H
#define EDITCONTRACTEMPLOYEEDIALOG_H

#include <QDialog>
#include "companywidget.h"
#include <QIntValidator>
#include <QDoubleValidator>

namespace Ui {
class EditContractEmployeeDialog;
}

class EditContractEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    EditContractEmployeeDialog(CompanyWidget* companyWidget, int key, QWidget *parent = nullptr);
    ~EditContractEmployeeDialog();

private slots:
    void on_BackpushButton_clicked();

    void on_AddpushButton_clicked();

private:
    Ui::EditContractEmployeeDialog *ui;
    CompanyWidget* companyWidget;
    std::shared_ptr<Employee> obj;
};

#endif // EDITCONTRACTEMPLOYEEDIALOG_H
