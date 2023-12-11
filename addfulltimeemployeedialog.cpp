#include "addfulltimeemployeedialog.h"
#include "ui_addfulltimeemployeedialog.h"

AddFulltimeemployeeDialog::AddFulltimeemployeeDialog(CompanyWidget* companyWidget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFulltimeemployeeDialog)
{
    ui->setupUi(this);
    this->companyWidget = companyWidget;

    ui->SalarylineEdit_2->setValidator(new QDoubleValidator);
    ui->BonuslineEdit->setValidator(new QDoubleValidator);

    ui->comboBox->addItem("");
    for (auto obj : companyWidget->getNameDivison()) {
        ui->comboBox->addItem(obj);
    }
}

AddFulltimeemployeeDialog::~AddFulltimeemployeeDialog()
{
    delete ui;
}

void AddFulltimeemployeeDialog::on_AddpushButton_clicked()
{
    QString name = ui->NamelineEdit_5->text().at(0).toUpper() + ui->NamelineEdit_5->text().mid(1);
    QString surname = ui->SurnamelineEdit_4->text().at(0).toUpper() + ui->SurnamelineEdit_4->text().mid(1);
    QString position = ui->PositionlineEdit_3->text().at(0).toUpper() + ui->PositionlineEdit_3->text().mid(1);
    double salary = ui->SalarylineEdit_2->text().toDouble();
    double bonus = ui->BonuslineEdit->text().toDouble();

    if (name.isEmpty() || surname.isEmpty() || position.isEmpty() || ui->SalarylineEdit_2->text().isEmpty() ||
        ui->BonuslineEdit->text().isEmpty() || ui->comboBox->currentIndex() == 0){}
    else
    {
        shared_ptr<Employee> employee = make_unique<FullTimeEmployee>(name.toStdString(), surname.toStdString(),
                                                                      position.toStdString(), salary, bonus);
        companyWidget->addEmployee(employee, ui->comboBox->currentIndex() - 1);
        this->hide();
    }
}


void AddFulltimeemployeeDialog::on_BackpushButton_clicked()
{
    this->hide();
}

