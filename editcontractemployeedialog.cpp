#include "editcontractemployeedialog.h"
#include "ui_editcontractemployeedialog.h"

EditContractEmployeeDialog::EditContractEmployeeDialog(CompanyWidget* companyWidget, int key, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditContractEmployeeDialog)
{
    ui->setupUi(this);
    this->companyWidget = companyWidget;
    this->obj = companyWidget->getObjWhereKey(key);

    std::shared_ptr<ContractEmployee> conractempl = std::dynamic_pointer_cast<ContractEmployee>(this->obj);

    if (conractempl){
        ui->NamelineEdit_5->setText(QString::fromStdString(conractempl->getName()));
        ui->SurnamelineEdit_4->setText(QString::fromStdString(conractempl->getSurname()));
        ui->PositionlineEdit_3->setText(QString::fromStdString(conractempl->getPosition()));
        ui->RatelineEdit_2->setText(QString::number(conractempl->getHourlyRate()));
        ui->HourInDaylineEdit->setText(QString::number(conractempl->getHour()));
    }
    ui->RatelineEdit_2->setValidator(new QDoubleValidator);
    ui->HourInDaylineEdit->setValidator(new QIntValidator);
}

EditContractEmployeeDialog::~EditContractEmployeeDialog()
{
    delete ui;
}

void EditContractEmployeeDialog::on_BackpushButton_clicked()
{
    this->hide();
}


void EditContractEmployeeDialog::on_AddpushButton_clicked()
{
    std::shared_ptr<ContractEmployee> conractempl = std::dynamic_pointer_cast<ContractEmployee>(this->obj);

    QString name = ui->NamelineEdit_5->text();
    QString surName = ui->SurnamelineEdit_4->text();
    QString position = ui->PositionlineEdit_3->text();
    QString rate = ui->RatelineEdit_2->text();
    QString hourInDay = ui->HourInDaylineEdit->text();

    if (name.isEmpty() || surName.isEmpty() || position.isEmpty() || rate.isEmpty() || hourInDay.isEmpty()){}
    else {
        conractempl->setName(name.toStdString());
        conractempl->setSurname(surName.toStdString());
        conractempl->setPosition(position.toStdString());
        conractempl->setHour(hourInDay.toInt());
        conractempl->setHourlyRate(rate.toDouble());
        this->hide();
    }
}

