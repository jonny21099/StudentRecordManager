#ifndef VIEWSTUDENTS_H
#define VIEWSTUDENTS_H

#include <QDialog>
#include <studentmanagement.h>

namespace Ui {
class viewStudents;
}

class viewStudents : public QDialog
{
    Q_OBJECT

public:
    explicit viewStudents(QString username, QWidget *parent = nullptr);
    ~viewStudents();

public slots:
    void refreshwindow();

    void on_addStudent_clicked();

private slots:
    void on_removeStudent_clicked();

private:
    QString username;
    Ui::viewStudents *ui;
    studentManagement *studentWindow;
};

#endif // VIEWSTUDENTS_H
