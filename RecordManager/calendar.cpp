#include "calendar.h"
#include "ui_calendar.h"
#include <QPainter>

Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
}
Calendar::~Calendar()
{
    delete ui;
}
