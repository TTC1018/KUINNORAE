#ifndef LOGOUT_DIALOG_H
#define LOGOUT_DIALOG_H

#include <QDialog>
#include "Room.h"

namespace Ui {
class logout_Dialog;
}

class logout_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit logout_Dialog(QWidget *parent = nullptr);
    ~logout_Dialog();
    Room* getRoom();
    void setRoom(Room *room);
    int getIndex();
    void setIndex(int index);

private slots:
    void on_noB_clicked();
    void on_yesB_clicked();

    void on_num1_clicked();
    void on_num2_clicked();
    void on_num3_clicked();
    void on_num4_clicked();
    void on_num5_clicked();
    void on_num6_clicked();
    void on_num7_clicked();
    void on_num8_clicked();
    void on_num9_clicked();
    void on_num0_clicked();

private:
    Ui::logout_Dialog *ui;
    Room *room;
    QString passwd;
    int index;

signals:
    void logout_sig(int index);
};

#endif // LOGOUT_DIALOG_H
