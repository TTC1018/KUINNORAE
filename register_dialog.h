#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QDialog>

namespace Ui {
class register_Dialog;
}

class register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit register_Dialog(QWidget *parent = nullptr);
    ~register_Dialog();

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

    void on_regi_cancel_clicked(); //취소 버튼(창 끄기)

    void on_regi_ok_clicked(); //등록 버튼

private:
    Ui::register_Dialog *ui;
};

#endif // REGISTER_DIALOG_H
