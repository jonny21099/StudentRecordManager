#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <QTextStream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QFile file("accounts.txt");
    QString usercheck;
    QString passcheck;
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        usercheck = file.readLine();
        passcheck = file.readLine();
        if(username == usercheck && password == passcheck){
            QTextStream(stdout) << "string to print" << endl;
            userWindow = new User(this);
            userWindow->show();
        }
        file.close();
    }
    QMessageBox::warning(this,"Failure","Login Failed");
}
