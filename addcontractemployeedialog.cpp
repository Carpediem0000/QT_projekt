#include "addcontractemployeedialog.h"
#include "ui_addcontractemployeedialog.h"

AddContractEmployeeDialog::AddContractEmployeeDialog(CompanyWidget* companyWidget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContractEmployeeDialog)
{
    ui->setupUi(this);
    this->companyWidget = companyWidget;

    ui->RatelineEdit_2->setValidator(new QDoubleValidator);
    ui->HourInDaylineEdit->setValidator(new QIntValidator);

    ui->comboBox->addItem("");
    for (auto obj : companyWidget->getNameDivison()) {
        ui->comboBox->addItem(obj);
    }
}

AddContractEmployeeDialog::~AddContractEmployeeDialog()
{
    delete ui;
}

void AddContractEmployeeDialog::on_BackpushButton_clicked()
{
    this->hide();
}


void AddContractEmployeeDialog::on_AddpushButton_clicked()
{
    QString name = ui->NamelineEdit_5->text().at(0).toUpper() + ui->NamelineEdit_5->text().mid(1);
    QString surname = ui->SurnamelineEdit_4->text().at(0).toUpper() + ui->SurnamelineEdit_4->text().mid(1);
    QString position = ui->PositionlineEdit_3->text().at(0).toUpper() + ui->PositionlineEdit_3->text().mid(1);
    double hourlyRate = ui->RatelineEdit_2->text().toDouble();
    int hourInDay = ui->HourInDaylineEdit->text().toDouble();

    if (name.isEmpty() || surname.isEmpty() || position.isEmpty() || ui->comboBox->currentIndex() == 0 ||
        ui->RatelineEdit_2->text().isEmpty() || (hourInDay <= 0 || hourInDay > 24)){}
    else
    {
        shared_ptr<Employee> employee = make_unique<ContractEmployee>(name.toStdString(), surname.toStdString(),
                                                                      position.toStdString(), hourlyRate, hourInDay);
        companyWidget->addEmployee(employee, ui->comboBox->currentIndex() - 1);
        this->hide();
    }
}

