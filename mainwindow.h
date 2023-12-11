#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "companywidget.h"
#include "addfulltimeemployeedialog.h"
#include "addcontractemployeedialog.h"
#include "editfulltimeemployeedialog.h"
#include "editcontractemployeedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateWidget();

private slots:
    void on_AddDivision_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_DElDivison_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_3_activated(int index);

private:
    Ui::MainWindow *ui;
    CompanyWidget* companyWidget;
    AddFulltimeemployeeDialog* addFulltimeemployeeDialog;
    EditFulltimeemployeeDialog* editFulltimeemployeeDialog;
    AddContractEmployeeDialog* addContractEmployeeDialog;
    EditContractEmployeeDialog* editContractEmployeeDialog;
};
#endif // MAINWINDOW_H
