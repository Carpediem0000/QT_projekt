#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->company = new Company();
//    this->company->addDivision(new Division("IT Division"));
//    this->company->addDivision(new Division("Book Division"));

//    shared_ptr<Employee> a1 = make_unique<ContractEmployee>("Vanya", "Bones", "It_spesialist", 120, 4);
//    shared_ptr<Employee> a2 = make_unique<ContractEmployee>("Vanya1", "Bone", "It_speist", 150, 7);
//    shared_ptr<Employee> a3 = make_unique<ContractEmployee>("Vanya2", "Boes", "It_", 90, 6);
//    shared_ptr<Employee> a4 = make_unique<ContractEmployee>("Vanya3", "ones", "Spesialist", 200, 4);

//    shared_ptr<Employee> a5 = make_unique<FullTimeEmployee>("Vanya4", "ones", "Spesialist", 25000, 150);
//    shared_ptr<Employee> a6 = make_unique<FullTimeEmployee>("Vanya5", "ones", "Nikto", 5000);
//    shared_ptr<Employee> a7 = make_unique<FullTimeEmployee>("Vanya6", "ones", "Director", 125000, 15000);

//    this->company->addEmployee(a1, 0);
//    this->company->addEmployee(a3, 0);
//    this->company->addEmployee(a5, 0);
//    this->company->addEmployee(a7, 0);

//    this->company->addEmployee(a4, 1);
//    this->company->addEmployee(a2, 1);
//    this->company->addEmployee(a6, 1);

    this->company->show();
    //this->company->saveDivisionToFile();


    this->companyTreeModel = new CompanyTreeModel(company, this);
    ui->treeView->setModel(companyTreeModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

