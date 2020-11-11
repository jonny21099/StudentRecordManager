#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <QtSql>
#include <QTextStream>
#include <regex>

using namespace std;
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_buttonBox_accepted()
{
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString username = ui->userName->text();
    QString password = ui->passWord->text();
    QString repassword = ui->rPassWord->text();
    regex passwordcheck("^(?=.*?[a-zA-Z])(?=.*?[0-9]).{8,}$");
    if(firstName == "" || lastName == "" || username == "" || password == "" || repassword == ""){
        QMessageBox::warning(this,"Error", "Please make sure all fields are filled.");
    }
    else if(password != repassword){
        QMessageBox::warning(this,"Error","Your passwords do not match!");
    }
    else if(!regex_match(password.toStdString(),passwordcheck)) QMessageBox::warning(this,"Error","Your password must contain minimum eight characters, at least one letter and one number.");
    else{
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("accounts.db");
        if(!mydb.open()){
            QMessageBox::warning(this,"File Not Found Error", "The database file cannot be find.");
        }
        else{
            QSqlQuery query;
            if(!query.exec("INSERT INTO loginInfo VALUES('"+firstName+"','"+lastName+"','"+username+"','"+password+"');")){
                QMessageBox::warning(this,"Error:constraint error","This username already exists, please enter a unique username.");
            }
            else{
                QMessageBox::information(this,"Success","Your accounts successfully registered.");
            }
        }
    }
}
