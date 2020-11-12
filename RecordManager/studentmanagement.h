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
    explicit studentManagement(QWidget *parent = nullptr);
    ~studentManagement();

private:
    Ui::studentManagement *ui;
};

#endif // STUDENTMANAGEMENT_H
