#ifndef ADDADRDIALOG_H
#define ADDADRDIALOG_H

#include <QDialog>

namespace Ui {
class AddAdrDialog;
}

class AddAdrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAdrDialog(QWidget *parent = nullptr);
    ~AddAdrDialog();

    QString Name() const;
    QString Address() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddAdrDialog *ui;
};

#endif // ADDADRDIALOG_H
