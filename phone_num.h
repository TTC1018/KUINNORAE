#ifndef PHONE_NUM_H
#define PHONE_NUM_H

#include <QDialog>

namespace Ui {
class Phone_num;
}

class Phone_num : public QDialog
{
    Q_OBJECT

public:
    explicit Phone_num(QWidget *parent = nullptr);
    ~Phone_num();

private slots:
    void on_closeB_clicked();

private:
    Ui::Phone_num *ui;
};

#endif // PHONE_NUM_H
