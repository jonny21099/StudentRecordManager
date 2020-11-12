#include "viewstudents.h"
#include "ui_viewstudents.h"
#include <QtSql>
#include <QMessageBox>

viewStudents::viewStudents(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewStudents)
{
    this->username = username;
    ui->setupUi(this);
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("accounts.db");
    if(mydb.open()){
        QSqlQuery query;
        query.exec("SELECT firstname, lastname, DOB, Day_of_lessons, Start_date, Price_per_lesson, Length_of_lessons from studentList WHERE teacher = '"+username+"';");
        modal->setQuery(query);
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
        mydb.close();
    }
    else{
        QMessageBox::warning(this,"Error","Something unexpected happened.");
    }
}

viewStudents::~viewStudents()
{
    delete ui;
}

//void viewStudents::on_tableView_doubleClicked(const QModelIndex &index)
//{
//    QString val = ui->tableView->model()->data(index).toString();
//    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
//    mydb.setDatabaseName("accounts.db");
//    qDebug()<<(val);
//}

//CREATE TABLE studentList(firstname string, lastname string, DOB datetime, Day_of_lessons string, Start_date datetime, Price_per_lesson int, Length_of_lessons int, teacher FOREIGN KEY REFERENCES loginInfo(username));



void viewStudents::on_addStudent_clicked()
{
    studentWindow = new studentManagement(username,this);
    connect(studentWindow,SIGNAL(accepted()),this,SLOT(exec()));
    studentWindow->show();
    qDebug()<<(studentWindow->result());
    if(studentWindow->result()==1){
        qDebug()<<("here");
        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("accounts.db");
        if(mydb.open()){
            QSqlQuery query;
            query.exec("SELECT firstname, lastname, DOB, Day_of_lessons, Start_date, Price_per_lesson, Length_of_lessons from studentList WHERE teacher = '"+username+"';");
            modal->setQuery(query);
            ui->tableView->setModel(modal);
            mydb.close();
        }
        else{
            QMessageBox::warning(this,"Error","Something unexpected happened.");
        }
    }
}

void viewStudents::on_removeStudent_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    QModelIndex tempIndex = ui->tableView->model()->index(index.row(),0);
    QString firstname = tempIndex.data().toString();
    tempIndex = ui->tableView->model()->index(index.row(),1);
    QString lastname = tempIndex.data().toString();
    tempIndex = ui->tableView->model()->index(index.row(),2);
    QString DOB = tempIndex.data().toString();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("accounts.db");
    if(mydb.open()){
        QSqlQuery query;
        query.exec("DELETE FROM studentList WHERE firstname = '"+firstname+"' AND lastname = '"+lastname+"' AND DOB = '"+DOB+"' AND teacher = '"+username+"';");
        query.exec("SELECT firstname, lastname, DOB, Day_of_lessons, Start_date, Price_per_lesson, Length_of_lessons from studentList WHERE teacher = '"+username+"';");
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(query);
        ui->tableView->setModel(modal);
    }
    else QMessageBox::warning(this,"Error","Something unexpected has happened");
}
