#ifndef EDITFULLTIMEEMPLOYEEDIALOG_H
#define EDITFULLTIMEEMPLOYEEDIALOG_H

#include <QDialog>
#include "companywidget.h"
#include <QDoubleValidator>

namespace Ui {
class EditFulltimeemployeeDialog;
}

class EditFulltimeemployeeDialog : public QDialog
{
    Q_OBJECT

public:
    EditFulltimeemployeeDialog(CompanyWidget* companyWidget, int key, QWidget *parent = nullptr);
    ~EditFulltimeemployeeDialog();

private slots:
    void on_BackpushButton_clicked();

    void on_AddpushButton_clicked();

private:
    Ui::EditFulltimeemployeeDialog *ui;
    CompanyWidget* companyWidget;
    std::shared_ptr<Employee> obj;
};

#endif // EDITFULLTIMEEMPLOYEEDIALOG_H
