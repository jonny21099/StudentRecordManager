#include "studentmanagement.h"
#include "ui_studentmanagement.h"

studentManagement::studentManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentManagement)
{
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
