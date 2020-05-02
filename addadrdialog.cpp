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

void AddAdrDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    switch (ui->buttonBox->standardButton(button))
    {
    case QDialogButtonBox::Ok:
        IsOk = true;
        break;
    default:
        IsOk = false;
        break;
    }
}

void AddAdrDialog::on_buttonBox_accepted()
{
    accept();
}

void AddAdrDialog::on_buttonBox_rejected()
{
    reject();
}

bool AddAdrDialog::GetIsOk()
{
    return IsOk;
}

QString AddAdrDialog::Name() const
{
    return ui->lineEdit->text();
}

QString AddAdrDialog::Address() const
{
    return ui->lineEdit_2->text();
}
