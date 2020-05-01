#include "addadrdialog.h"
#include "ui_addadrdialog.h"

AddAdrDialog::AddAdrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAdrDialog)
{
    ui->setupUi(this);
}

AddAdrDialog::~AddAdrDialog()
{
    delete ui;
}

void AddAdrDialog::on_buttonBox_accepted()
{
    accept();
}

void AddAdrDialog::on_buttonBox_rejected()
{
    reject();
}

QString AddAdrDialog::Name() const
{
    return ui->lineEdit->text();
}

QString AddAdrDialog::Address() const
{
    return ui->lineEdit_2->text();
}
