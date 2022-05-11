#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "charge_dialog.h"
#include "phone_num.h"
#include "register_dialog.h"
#include "info_dialog.h"
#include "login_dialog.h"
#include "logout_dialog.h"

#include <QTcpServer>
#include <QTcpSocket>
#include "test_dialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void* wait_thread(); // predict waiting time thread method
    void* logout_thread(); //auto logout

signals:
    void em_update_sig(int index);
    void us_update_sig(int index);

public slots:
    void empty_img(int index);
    void used_img(int index);
    void ud_empty_plus(); //
    void ud_empty_minus();

    void onNewConnection(); // 새로운 client 감지
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

private slots:
    void on_room1_B_clicked();
    void on_room2_B_clicked();
    void on_room3_B_clicked();
    void on_room4_B_clicked();
    void on_room5_B_clicked();
    void on_room6_B_clicked();
    void on_room7_B_clicked();
    void on_room8_B_clicked();
    void on_room9_B_clicked();
    void on_room11_B_clicked();
    void on_room10_B_clicked();
    void on_room12_B_clicked();
    void on_room13_B_clicked();
    void on_room14_B_clicked();
    void on_room15_B_clicked();
    void on_room16_B_clicked();
    void on_room17_B_clicked();

    void on_info_Button_clicked();
    void on_register_Button_clicked();
    void on_phoneNumB_clicked();

private:
    Ui::MainWindow *ui;
    Phone_num *P_n;
    charge_Dialog *c_D;
    register_Dialog *r_D;
    info_Dialog *i_D;
    login_Dialog *l_D;
    logout_Dialog *lt_D;

    test_Dialog* t_D;
    QTcpServer _server;
    QList<QTcpSocket*> _sockets;

};
#endif // MAINWINDOW_H
