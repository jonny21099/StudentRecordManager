#ifndef MODIFYPASSWORD_H
#define MODIFYPASSWORD_H

#include <QDialog>

namespace Ui {
class modifyPassword;
}

class modifyPassword : public QDialog
{
    Q_OBJECT

public:
    explicit modifyPassword(QString username, QString password, QWidget *parent = nullptr);
    ~modifyPassword();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::modifyPassword *ui;
    QString username;
    QString password;
};

#endif // MODIFYPASSWORD_H
