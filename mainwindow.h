#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<QString> SaveAdrData;

private slots:
    void on_AddButton_clicked();

    void on_ShowButton_clicked();

    void on_SaveButton_clicked();

private:
    Ui::MainWindow *ui;

    enum Column
    {
        NAME, ADDRESS
    };
};
#endif // MAINWINDOW_H
