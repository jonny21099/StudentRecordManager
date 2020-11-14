#include "studentmanagement.h"
#include "ui_studentmanagement.h"
#include <QMessageBox>
#include <QtSql>

/**
 * Constructor
 * Add certain labels and text fonts for the studentManagement page
 * @param username
 * @param parent
 */
studentManagement::studentManagement(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentManagement)
{
    this->username = username;
    ui->setupUi(this);
    QFont information_font = ui->informationLabel->font();
    information_font.setPointSize(14);
    information_font.setBold(true);
    ui->informationLabel->setFont(information_font);
    ui->startdate->setMinimumDate(QDate::currentDate());
    ui->dayOfLessonsBox->addItem("Monday");
    ui->dayOfLessonsBox->addItem("Tuesday");
    ui->dayOfLessonsBox->addItem("Wednesday");
    ui->dayOfLessonsBox->addItem("Thursday");
    ui->dayOfLessonsBox->addItem("Friday");
    ui->dayOfLessonsBox->addItem("Saturday");
    ui->dayOfLessonsBox->addItem("Sunday");
}

studentManagement::~studentManagement()
{
    delete ui;
}

/**
 * Add new student to the database
 */
void studentManagement::on_buttonBox_accepted()
{
    QString firstname = ui->firstname->text();
    QString lastname = ui->lastname->text();
    QString DOB = ui->dateofbirth->text();
    QString dayOfLessons = ui->dayOfLessonsBox->currentText();
    QString startdate = ui->startdate->text();
    QString pricing = ui->pricing->text();
    QString lengthoflessons = ui->lengthoflessons->text();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("accounts.db");
    if(!mydb.open())QMessageBox::warning(this,"File Not Found Error", "The database file cannot be find.");
    else{
        QSqlQuery query;
        if(query.exec("INSERT INTO studentList VALUES('"+firstname+"', '"+lastname+"', '"+DOB+"', '"+dayOfLessons+"', '"+startdate+"', '"+pricing+"', '"+lengthoflessons+"', '"+username+"');")){
            mydb.close();
        }
    }
    emit updateDatabase();
}

