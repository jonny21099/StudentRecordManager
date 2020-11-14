#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <QDialog>

namespace Ui {
class studentManagement;
}

class studentManagement : public QDialog
{
    Q_OBJECT

public:
    explicit studentManagement(QString username, QWidget *parent = nullptr);
    ~studentManagement();

private slots:
    void on_buttonBox_accepted();

signals:
    void updateDatabase();

private:
    QString username;
    Ui::studentManagement *ui;
};

#endif // STUDENTMANAGEMENT_H
