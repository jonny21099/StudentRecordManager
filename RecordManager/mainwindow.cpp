#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QtSql>

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
    int numberOfRows=0;
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("accounts.db");
    if(!mydb.open()){
        QMessageBox::warning(this,"File Not Found Error", "The database file cannot be find.");
    }
    else{
        QSqlQuery query("SELECT * FROM loginInfo WHERE username = '"+username+"' AND password = '"+password+"'");
        query.last();
        numberOfRows=query.at()+1;
        if(numberOfRows==1){
            ui->stackedWidget->setCurrentIndex(1);
            QString welcomeMessage = "Welcome";
            welcomeMessage = welcomeMessage + ' ' + query.value(2).toString();
            ui->name_label->setText(welcomeMessage);
            QFont name_label_font = ui->name_label->font();
            name_label_font.setPointSize(25);
            name_label_font.setBold(true);
            ui->name_label->setFont(name_label_font);
        }
        else{
            QMessageBox::warning(this,"Failure","Please enter a valid username and password.\nIf you don't have an account, please register with us.");
        }
        mydb.close();
    }
}

void MainWindow::on_pushButton_register_clicked()
{
    registerWindow = new Register(this);
    registerWindow->show();
}
