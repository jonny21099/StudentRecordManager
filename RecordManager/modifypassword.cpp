#include "modifypassword.h"
#include "ui_modifypassword.h"
#include <QMessageBox>
#include <QtSql>

modifyPassword::modifyPassword(QString username, QString password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyPassword)
{
    this->username = username;
    this->password = password;
    ui->setupUi(this);
}

modifyPassword::~modifyPassword()
{
    delete ui;
}

void modifyPassword::on_buttonBox_accepted()
{
    QString currentPassword = ui->currentPassword->text();
    QString newPassword = ui->newPassword->text();
    if(currentPassword == "" || newPassword == "" || ui->reNewPassword->text() == ""){
        QMessageBox::warning(this,"Error","Please make sures all fields are filled.");
    }
    else if(currentPassword != password){
        QMessageBox::warning(this,"Error","The password you have entered is incorrect.");
    }
    else if(newPassword!=ui->reNewPassword->text()){
        QMessageBox::warning(this,"Error","The new passwords you entered do not match.");
    }
    else if(password == newPassword){
        QMessageBox::warning(this,"Error","Please choose a new password.");
    }
    else{
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("accounts.db");
        if(!mydb.open()){
            QMessageBox::warning(this,"File Not Found Error", "The database file cannot be find.");
        }
        else{
            QSqlQuery query("UPDATE loginInfo SET password = '"+newPassword+"' WHERE username = '"+username+"';");
        }
    }
}
