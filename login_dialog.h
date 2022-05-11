#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>

namespace Ui {
class login_Dialog;
}

class login_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit login_Dialog(QWidget *parent = nullptr);
    ~login_Dialog();

    int getIndex();
    void setIndex(int index);

    bool getInfo_log();
    void setInfo_log(bool info_login);

    bool getMain_log();
    void setMain_log(bool main_login);

private slots:
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
    void on_back_clicked();


    void on_login_ok_clicked(); //login OK button
    void on_login_cancel_clicked();//login cancel button

private:
    Ui::login_Dialog *ui;
    bool info_login;
    bool main_login;
    int index;
};

#endif // LOGIN_DIALOG_H
