#include "editfulltimeemployeedialog.h"
#include "ui_editfulltimeemployeedialog.h"

EditFulltimeemployeeDialog::EditFulltimeemployeeDialog(CompanyWidget* companyWidget, int key, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditFulltimeemployeeDialog)
{
    ui->setupUi(this);
    this->companyWidget = companyWidget;
    this->obj = companyWidget->getObjWhereKey(key);

    std::shared_ptr<FullTimeEmployee> conractempl = std::dynamic_pointer_cast<FullTimeEmployee>(this->obj);
    if (conractempl){
        ui->NamelineEdit_5->setText(QString::fromStdString(conractempl->getName()));
        ui->SurnamelineEdit_4->setText(QString::fromStdString(conractempl->getSurname()));
        ui->PositionlineEdit_3->setText(QString::fromStdString(conractempl->getPosition()));
        ui->SalarylineEdit_2->setText(QString::number(conractempl->getSalary()));
        ui->BonuslineEdit->setText(QString::number(conractempl->getBonus()));
    }

    ui->SalarylineEdit_2->setValidator(new QDoubleValidator);
    ui->BonuslineEdit->setValidator(new QDoubleValidator);
}

EditFulltimeemployeeDialog::~EditFulltimeemployeeDialog()
{
    delete ui;
}

void EditFulltimeemployeeDialog::on_BackpushButton_clicked()
{
    this->hide();
}


void EditFulltimeemployeeDialog::on_AddpushButton_clicked()
{
    std::shared_ptr<FullTimeEmployee> conractempl = std::dynamic_pointer_cast<FullTimeEmployee>(this->obj);

    QString name = ui->NamelineEdit_5->text();
    QString surName = ui->SurnamelineEdit_4->text();
    QString position = ui->PositionlineEdit_3->text();
    QString salary = ui->SalarylineEdit_2->text();
    QString bonus = ui->BonuslineEdit->text();

    if (name.isEmpty() || surName.isEmpty() || position.isEmpty() || salary.isEmpty() || bonus.isEmpty()){}
    else {
        conractempl->setName(name.toStdString());
        conractempl->setSurname(surName.toStdString());
        conractempl->setPosition(position.toStdString());
        conractempl->setSalary(salary.toDouble());
        conractempl->setBonus(bonus.toDouble());
        this->hide();
    }
}

