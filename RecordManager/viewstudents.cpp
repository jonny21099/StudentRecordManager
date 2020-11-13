#include "viewstudents.h"
#include "ui_viewstudents.h"
#include <QtSql>
#include <QMessageBox>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


viewStudents::viewStudents(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewStudents)
{
    this->username = username;
    ui->setupUi(this);
    refreshwindow();
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
    studentWindow->show();
    connect(studentWindow,SIGNAL(updateDatabase()),this, SLOT(refreshwindow()));
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
        mydb.close();
        refreshwindow();
    }
}

void viewStudents::refreshwindow()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlDatabase tempdb = QSqlDatabase::addDatabase("QSQLITE");
    tempdb.setDatabaseName("accounts.db");
    qDebug()<<("Connect function");
    if(tempdb.open()){
        QSqlQuery tempquery;
        tempquery.exec("SELECT firstname, lastname, DOB, Day_of_lessons, Start_date, Price_per_lesson, Length_of_lessons from studentList WHERE teacher = '"+username+"';");
        modal->setQuery(tempquery);
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
        tempdb.close();
    }
    else{
        QMessageBox::warning(this,"Error","Something unexpected has happened.");
    }

}
