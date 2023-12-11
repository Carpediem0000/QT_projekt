#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->companyWidget = new CompanyWidget();
    QVBoxLayout* groupBoxLayout = new QVBoxLayout(ui->groupBox);
    groupBoxLayout->addWidget(companyWidget);

    ui->groupBox->setLayout(groupBoxLayout);
    ui->AddDivisionlineEdit->setPlaceholderText("Введите название отдела");

    ui->comboBox_2->addItem("");
    for (auto obj : companyWidget->getNameDivison()) {
        ui->comboBox_2->addItem(obj);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete companyWidget;
    delete addFulltimeemployeeDialog;
}

void MainWindow::updateWidget()
{
    QLayout* currentLayout = ui->groupBox->layout();
    if (currentLayout)
    {
        delete currentLayout;
    }
    delete companyWidget;

    this->companyWidget = new CompanyWidget();
    QVBoxLayout* groupBoxLayout = new QVBoxLayout(ui->groupBox);
    groupBoxLayout->addWidget(companyWidget);

    ui->groupBox->setLayout(groupBoxLayout);

    ui->comboBox_2->clear();

    ui->comboBox_2->addItem("");
    for (auto obj : companyWidget->getNameDivison()) {
        ui->comboBox_2->addItem(obj);
    }
}

void MainWindow::on_AddDivision_clicked()
{
    QTextStream out(stdout);
    out << companyWidget->getCurrentItemText();

    QString name = ui->AddDivisionlineEdit->text();
    companyWidget->addDivison(name);
    this->companyWidget->save();
    updateWidget();
}


void MainWindow::on_pushButton_5_clicked()
{
    QString index = companyWidget->getCurrentItemText();
//    QString curr;
//    for (int i = 1; i < text.length(); i++) {
//        if(text[i] == ' '){
//            break;
//        }
//        curr.append(text[i]);
//    }
    companyWidget->removeEmployee(index.toInt());

    // Устанавливаем новый макет
    updateWidget();
}


void MainWindow::on_pushButton_3_clicked()
{
    if (ui->comboBox->currentIndex() == 1)
    {
        this->addFulltimeemployeeDialog = new AddFulltimeemployeeDialog(this->companyWidget, this);
        this->addFulltimeemployeeDialog->setWindowTitle("Add Employee");
        this->addFulltimeemployeeDialog->setModal(true);
        this->addFulltimeemployeeDialog->exec();
        this->companyWidget->save();
        updateWidget();
        delete this->addFulltimeemployeeDialog;
    }
    else if (ui->comboBox->currentIndex() == 2)
    {
        this->addContractEmployeeDialog = new AddContractEmployeeDialog(this->companyWidget, this);
        this->addContractEmployeeDialog->setWindowTitle("Add Employee");
        this->addContractEmployeeDialog->setModal(true);
        this->addContractEmployeeDialog->exec();
        this->companyWidget->save();
        updateWidget();
        delete this->addContractEmployeeDialog;
    }
    ui->comboBox->setCurrentIndex(0);
}


void MainWindow::on_pushButton_4_clicked()
{
    QString type = companyWidget->getCurrentItemType();
    int index = companyWidget->getCurrentItemText().toInt();
    if (type == QString("FullTimeEmployee"))
    {
        this->editFulltimeemployeeDialog = new EditFulltimeemployeeDialog(this->companyWidget, index, this);
        this->editFulltimeemployeeDialog->setWindowTitle("Edit Employee");
        this->editFulltimeemployeeDialog->setModal(true);
        this->editFulltimeemployeeDialog->exec();
        this->companyWidget->save();
        updateWidget();
        delete this->editFulltimeemployeeDialog;
    }
    else if (type == QString("ContractEmployee"))
    {
        this->editContractEmployeeDialog = new EditContractEmployeeDialog(this->companyWidget, index, this);
        this->editContractEmployeeDialog->setWindowTitle("Edit Employee");
        this->editContractEmployeeDialog->setModal(true);
        this->editContractEmployeeDialog->exec();
        this->companyWidget->save();
        updateWidget();
        delete this->editContractEmployeeDialog;
    }
}


void MainWindow::on_DElDivison_clicked()
{
    int ind = ui->comboBox_2->currentIndex();
    if (ind != 0){
        ui->comboBox_2->setCurrentIndex(0);
        companyWidget->removeDivision(ind-1);
        this->companyWidget->save();
        updateWidget();
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    companyWidget->searchItem(arg1);
}


void MainWindow::on_comboBox_3_activated(int index)
{
    if (index == 1)
    {
        companyWidget->sort();
    }
    else if (index == 2)
    {
        companyWidget->sort(Qt::DescendingOrder);
    }
}

