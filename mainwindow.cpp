#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addadrdialog.h"

#include <QFile>
#include <QDebug>
#include <QMessageBox>

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
    QString Name = NULL, Address = NULL;
    AddAdrDialog AddAdrDialog(this);

    AddAdrDialog.exec();

    if (!AddAdrDialog.GetIsOk())
        return;

    Name = AddAdrDialog.Name();
    Address = AddAdrDialog.Address();

    if (Name == NULL || Address == NULL)
        return;

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    int index = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(index, NAME, new QTableWidgetItem(Name));
    ui->tableWidget->setItem(index, ADDRESS, new QTableWidgetItem(Address));
    SaveAdrData.push_back(Name);
    SaveAdrData.push_back(": ");
    SaveAdrData.push_back(Address);
    SaveAdrData.push_back("\n");
}

void MainWindow::on_ShowButton_clicked()
{
    QFile File("C:\\AddressBook.txt");

    if (!File.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Can't open file.";
        return;
    }

    QTextStream FileData(&File);

    QMessageBox ShowAdrData(this);
    ShowAdrData.setText(FileData.readAll());
    ShowAdrData.show();
    ShowAdrData.exec();

    File.close();
}

void MainWindow::on_SaveButton_clicked()
{
    QFile File("C:\\AddressBook.txt");

    if (!File.open(QFile::WriteOnly | QFile::Text | QIODevice::Append))
    {
        qDebug() << "Can't open file.";
        return;
    }

    QTextStream FileData(&File);

    for (int idx = 0; idx < SaveAdrData.size(); ++idx)
        FileData << SaveAdrData[idx];

    SaveAdrData.clear();

    File.close();

    QMessageBox Result(this);
    Result.setText("Success!");
    Result.exec();
}
