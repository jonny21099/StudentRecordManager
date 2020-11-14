#include "viewstudents.h"
#include "ui_viewstudents.h"
#include <QtSql>
#include <QMessageBox>

/**
 * Constructor
 * @param username
 * @param parent
 */
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

/**
 * Create an object of class studentManagement and display it
 * If updateDatabase signal is received call refreshwindow slot
 */
void viewStudents::on_addStudent_clicked()
{
    studentWindow = new studentManagement(username,this);
    studentWindow->show();
    connect(studentWindow,SIGNAL(updateDatabase()),this, SLOT(refreshwindow()));
}

/**
 * Remove student from tableview
 */
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

/**
 * refresh the tableview used to display students
 */
void viewStudents::refreshwindow()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlDatabase tempdb = QSqlDatabase::addDatabase("QSQLITE");
    tempdb.setDatabaseName("accounts.db");
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
