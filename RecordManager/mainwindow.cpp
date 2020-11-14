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

/**
 * Login to user
 */
void MainWindow::on_pushButton_login_clicked()
{
    int numberOfRows=0;
    this->username = ui->lineEdit_username->text();
    this->password = ui->lineEdit_password->text();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("accounts.db");
    if(!mydb.open()){
        QMessageBox::warning(this,"File Not Found Error", "The database file cannot be find.");
    }
    else{
        QSqlQuery query("SELECT * FROM loginInfo WHERE username = '"+username+"' AND password = '"+password+"';");
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
            name_label_font.setCapitalization(QFont::AllUppercase);
            name_label_font.setFamily("Helvetica");
            ui->name_label->setFont(name_label_font);
        }
        else{
            QMessageBox::warning(this,"Failure","Please enter a valid username and password.\nIf you don't have an account, please register with us.");
        }
        mydb.close();
    }
}

/**
 * Create an object of class Register
 */
void MainWindow::on_pushButton_register_clicked()
{
    registerWindow = new Register(this);
    registerWindow->show();
    connect(registerWindow,SIGNAL(checkfailed()),this,SLOT(refreshRegisterWindow()));
}
/*****************************************************************/
//AFTER LOGIN IN SUCCESSFUL
/**
 * Creates an object of class viewStudents and displays it
 */
void MainWindow::on_option1_clicked()
{
    viewstudents = new viewStudents(username, this);
    viewstudents->show();
}

/**
 * Creates an object of class Calendar and displays it
 */
void MainWindow::on_option2_clicked()
{
     calendar = new Calendar(this);
     calendar->show();
}

/**
 * When user clicks on option#3
 *
 */
void MainWindow::on_option3_clicked()
{

}

/**
 * Creates an object of class modifyPassword and displays it
 */
void MainWindow::on_option4_clicked()
{
    modifyPasswordWindow = new modifyPassword(username, password, this);
    modifyPasswordWindow->show();
}

/**
 * Logout and go back to mainwindow
 */
void MainWindow::on_option5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_username->setText("");
    ui->lineEdit_password->setText("");
}

/**
 * A slot used to redisplay the object registerWindow
 */
void MainWindow::refreshRegisterWindow(){
    registerWindow->show();
}



