#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addadrdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList TableHeader;
    TableHeader << "Name" << "Address";

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(TableHeader);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddButton_clicked()
{
    QString Name, Address;
    AddAdrDialog AddAdrDialog(this);

    AddAdrDialog.exec();

    Name = AddAdrDialog.Name();
    Address = AddAdrDialog.Address();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    int index = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(index, NAME, new QTableWidgetItem(Name));
    ui->tableWidget->setItem(index, ADDRESS, new QTableWidgetItem(Address));
}
