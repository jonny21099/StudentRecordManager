#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "register.h"
#include "modifypassword.h"
#include "calendar.h"
#include "viewstudents.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

    void on_option1_clicked();

    void on_option2_clicked();

    void on_option3_clicked();

    void on_option4_clicked();

    void on_option5_clicked();

    void refreshRegisterWindow();

private:
    Ui::MainWindow *ui;
    Register *registerWindow;
    modifyPassword *modifyPasswordWindow;
    Calendar *calendar;
    viewStudents *viewstudents;
    QString username;
    QString password;
};
#endif // MAINWINDOW_H
