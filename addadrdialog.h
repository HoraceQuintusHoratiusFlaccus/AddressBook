#ifndef ADDADRDIALOG_H
#define ADDADRDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class AddAdrDialog;
}

class AddAdrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAdrDialog(QWidget *parent = nullptr);
    ~AddAdrDialog();

    bool GetIsOk();

    QString Name() const;
    QString Address() const;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddAdrDialog *ui;
    bool IsOk;
};

#endif // ADDADRDIALOG_H
