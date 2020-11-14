#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

signals:
    void checkfailed();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
