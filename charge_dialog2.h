#ifndef CHARGE_DIALOG2_H
#define CHARGE_DIALOG2_H

#include <QDialog>
#include "User.h"

namespace Ui {
class charge_Dialog2;
}

class charge_Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit charge_Dialog2(QWidget *parent = nullptr);
    ~charge_Dialog2();

    void setUser(User *user);
    User* getUser();
    void setIndex(int index);
    int getIndex();

private slots:

    void on_payB_clicked();
    void on_closeB_clicked();

    void on_price1000_4_clicked();
    void on_price2000_9_clicked();
    void on_price3000_14_clicked();
    void on_price4000_19_clicked();
    void on_price5000_24_clicked();
    void on_price7000_34_clicked();
    void on_price10000_49_clicked();
    void on_price20000_100_clicked();
    void on_clearB_clicked();

private:
    Ui::charge_Dialog2 *ui;
    User *user;
    int index;
};

#endif // CHARGE_DIALOG2_H
