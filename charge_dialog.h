#ifndef CHARGE_DIALOG_H
#define CHARGE_DIALOG_H

#include <QDialog>

#include "User.h"
#include "Room.h"

namespace Ui {
class charge_Dialog;
}

class charge_Dialog : public QDialog
{
    Q_OBJECT

signals:
    void login_sig();
    void login_img_sig(int index);

public:
    explicit charge_Dialog(QWidget *parent = nullptr);
    ~charge_Dialog();

    Room* getRoom();
    void setRoom(Room *room);
    void setUser(User *user);
    User* getUser();
    void setIndex(int index);
    int getIndex();

    void update();

private slots:

    void on_cancel_B_clicked(); // cancel button
    void on_back_clicked(); // number erase button
    void on_charge_B_clicked(); // charge button
    void on_use_B_clicked(); // use button

    void on_b0_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();


private:
    Ui::charge_Dialog *ui;
    User* user;
    int index;
    Room* room;

};

#endif // CHARGE_DIALOG_H
