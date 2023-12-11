#ifndef ADDFULLTIMEEMPLOYEEDIALOG_H
#define ADDFULLTIMEEMPLOYEEDIALOG_H

#include <QDialog>
#include "companywidget.h"
#include <QValidator>

namespace Ui {
class AddFulltimeemployeeDialog;
}

class AddFulltimeemployeeDialog : public QDialog
{
    Q_OBJECT

public:
    AddFulltimeemployeeDialog(CompanyWidget* companyWidget, QWidget *parent = nullptr);
    ~AddFulltimeemployeeDialog();

private slots:
    void on_AddpushButton_clicked();

    void on_BackpushButton_clicked();

private:
    Ui::AddFulltimeemployeeDialog *ui;
    CompanyWidget* companyWidget;
};

#endif // ADDFULLTIMEEMPLOYEEDIALOG_H
