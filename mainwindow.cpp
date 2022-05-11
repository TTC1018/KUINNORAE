#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kiosk.h"
#include <thread>
#include <mutex>

#include <QtDebug>
#include <QHostAddress>
#include <QAbstractSocket>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _server(this)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    connect(this, SIGNAL(em_update_sig(int)), SLOT(empty_img(int))); //when auto logged out, change button's image to emptyroom
    connect(kiosk::getInstance(), SIGNAL(logout_sig()), this, SLOT(ud_empty_plus())); //In kiosk, 'logout' method operated, change 'emptyroom number text box'

    std::thread waitTh(&MainWindow::wait_thread, this);
    waitTh.detach();

    std::thread logoutTh(&MainWindow::logout_thread, this);
    logoutTh.detach();

    _server.listen(QHostAddress::Any,4242);
    connect(&_server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_phoneNumB_clicked()
{
    this->P_n = new Phone_num(this);
    this->P_n->setModal(true);
    this->P_n->exec(); //Dialog에만 초점이 맞춰지고, 메인 창을 작동시킬 수 없게 해줌
}

void MainWindow::on_register_Button_clicked()
{
    this->r_D = new register_Dialog(this);
    this->r_D->setModal(true);
    this->r_D->exec();
}

void MainWindow::on_info_Button_clicked()
{
    this->l_D = new login_Dialog(this);
    this->l_D->setInfo_log(true); //login to information dialog
    this->l_D->setMain_log(false);
    this->l_D->setModal(true);
    this->l_D->exec();
}

void MainWindow::on_room1_B_clicked()
{
    int index = 1;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room1_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room1_B->setChecked(false);
    }
}

void MainWindow::on_room2_B_clicked()
{
    int index = 2;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room2_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room2_B->setChecked(false);
    }
}

void MainWindow::on_room3_B_clicked()
{
    int index = 3;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room3_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room3_B->setChecked(false);
    }
}

void MainWindow::on_room4_B_clicked()
{
    int index = 4;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room4_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room4_B->setChecked(false);
    }
}

void MainWindow::on_room5_B_clicked()
{
    int index = 5;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room5_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room5_B->setChecked(false);
    }
}

void MainWindow::on_room6_B_clicked()
{
    int index = 6;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room6_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room6_B->setChecked(false);
    }
}

void MainWindow::on_room7_B_clicked()
{
    int index = 7;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room7_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room7_B->setChecked(false);
    }
}

void MainWindow::on_room8_B_clicked()
{
    int index = 8;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room8_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room8_B->setChecked(false);
    }
}

void MainWindow::on_room9_B_clicked()
{
    int index = 9;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room9_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room9_B->setChecked(false);
    }
}

void MainWindow::on_room10_B_clicked()
{
    int index = 10;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room10_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room10_B->setChecked(false);
    }
}

void MainWindow::on_room11_B_clicked()
{
    int index = 11;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room11_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room11_B->setChecked(false);
    }
}

void MainWindow::on_room12_B_clicked()
{
    int index = 12;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room12_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room12_B->setChecked(false);
    }
}

void MainWindow::on_room13_B_clicked()
{
    int index = 13;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room13_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room13_B->setChecked(false);
    }
}

void MainWindow::on_room14_B_clicked()
{
    int index = 14;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room14_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room14_B->setChecked(false);
    }
}

void MainWindow::on_room15_B_clicked()
{
    int index = 15;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room15_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room15_B->setChecked(false);
    }
}

void MainWindow::on_room16_B_clicked()
{
    int index = 16;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room16_B->setChecked(false);

    }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
        Room *room = &kiosk::getInstance()->getArr_room()[index-1];

        this->lt_D = new logout_Dialog(this);
        this->lt_D->setRoom(room);
        this->lt_D->setIndex(index);
        this->lt_D->setModal(true);
        this->lt_D->exec();

        ui->room16_B->setChecked(false);
    }
}

void MainWindow::on_room17_B_clicked()
{
    int index = 17;

    if(!(kiosk::getInstance()->getArr_room()[index-1].getOccupied())){ // login

        this->l_D = new login_Dialog(this);
        this->l_D->setMain_log(true);
        this->l_D->setInfo_log(false);
        this->l_D->setModal(true);
        this->l_D->setIndex(index);
        this->l_D->exec();

        ui->room17_B->setChecked(false);

        }else if(kiosk::getInstance()->getArr_room()[index-1].getOccupied()){ //logout
            Room *room = &kiosk::getInstance()->getArr_room()[index-1];

            this->lt_D = new logout_Dialog(this);
            this->lt_D->setRoom(room);
            this->lt_D->setIndex(index);
            this->lt_D->setModal(true);
            this->lt_D->exec();

            ui->room17_B->setChecked(false);
    }
}

void* MainWindow::wait_thread(){
    bool full = false;
    int temp[17];
    int tmp;

    while(1){


        for(int i=0; i<17; i++){
            temp[i] = kiosk::getInstance()->getArr_room()[i].getSong_remain();
        }

        full = (ui->emptyR_num->text().toInt() == 0) ? true:false; // if there's no empty room, full is true

        if(full){

            for(int i=16; i>0; i--){ // arrange numbers by bubble sort
              for(int j=0; j<i; j++){
                if(temp[j] > temp[j+1]){
                  tmp = temp[j];
                  temp[j] = temp[j+1];
                  temp[j+1] = tmp;
                }
              }
            }

            ui->wait_1->setText(QString::number(temp[0]*3));
            ui->wait_2->setText(QString::number(temp[1]*3));
            ui->wait_3->setText(QString::number(temp[2]*3));
            ui->wait_4->setText(QString::number(temp[3]*3));
            ui->wait_5->setText(QString::number(temp[4]*3));
          }
        else{
            ui->wait_1->setText(QString::number(0));
            ui->wait_2->setText(QString::number(0));
            ui->wait_3->setText(QString::number(0));
            ui->wait_4->setText(QString::number(0));
            ui->wait_5->setText(QString::number(0));
        }

       std::this_thread::sleep_for(std::chrono::milliseconds(5000));
       }

}

void* MainWindow::logout_thread(){
    Room* temp;

    while(1){

        for(int index=1; index<=17; index++){

            temp = &kiosk::getInstance()->getArr_room()[index - 1];
            bool occupied = temp->getOccupied();
            int remain = temp->getSong_remain();

            if(occupied && (remain == 0)){

                kiosk::getInstance()->logout(temp, index, temp->getCurrentuser()->getPW()); //logout by kiosk
                emit em_update_sig(index); //image change signal
             }
            }

      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}

void MainWindow::ud_empty_plus(){
    ui->emptyR_num->setText(QString::number(ui->emptyR_num->text().toInt() + 1)); // update empty room number
    ui->usingR_num->setText(QString::number(ui->usingR_num->text().toInt() - 1)); // update using room number
}

void MainWindow::ud_empty_minus(){
    ui->emptyR_num->setText(QString::number(ui->emptyR_num->text().toInt() - 1)); // update empty room number
    ui->usingR_num->setText(QString::number(ui->usingR_num->text().toInt() + 1)); // update using room number
}

void MainWindow::empty_img(int index){
    switch(index){

    case 1:
        ui->room1_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_1);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_1_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_1);}");
        break;
    case 2:
        ui->room2_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_2);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_2_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_2);}");
        break;
    case 3:
        ui->room3_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_3);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_3_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_3);}");
        break;
    case 4:
        ui->room4_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_4);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_4_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_4);}");
        break;
    case 5:
        ui->room5_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_5);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_5_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_5);}");
        break;
    case 6:
        ui->room6_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_6);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_6_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_6);}");
        break;
    case 7:
        ui->room7_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_7);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_7_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_7);}");
        break;
    case 8:
        ui->room8_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_8);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_8_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_8);}");
        break;
    case 9:
        ui->room9_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_9);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_9_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_9);}");
        break;
    case 10:
        ui->room10_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_10);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_10_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_10);}");
        break;
    case 11:
        ui->room11_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_11);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_11_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_11);}");
        break;
    case 12:
        ui->room12_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_12);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_12_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_12);}");
        break;
    case 13:
        ui->room13_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_13);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_13_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_13);}");
        break;
    case 14:
        ui->room14_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_14);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_14_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_14);}");
        break;
    case 15:
        ui->room15_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_15);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_15_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_15);}");
        break;
    case 16:
        ui->room16_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_16);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_16_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_16);}");
        break;
    case 17:
        ui->room17_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/EMPTYROOM_17);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/EMPTYROOM_17_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/PAIDROOM_17);}");
        break;

    }
}

void MainWindow::used_img(int index){
    switch(index){

    case 1:
        ui->room1_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_1);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_1_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_1);}");
        break;
    case 2:
        ui->room2_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_2);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_2_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_2);}");
        break;
    case 3:
        ui->room3_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_3);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_3_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_3);}");
        break;
    case 4:
        ui->room4_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_4);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_4_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_4);}");
        break;
    case 5:
        ui->room5_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_5);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_5_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_5);}");
        break;
    case 6:
        ui->room6_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_6);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_6_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_6);}");
        break;
    case 7:
        ui->room7_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_7);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_7_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_7);}");
        break;
    case 8:
        ui->room8_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_8);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_8_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_8);}");
        break;
    case 9:
        ui->room9_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_9);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_9_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_9);}");
        break;
    case 10:
        ui->room10_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_10);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_10_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_10);}");
        break;
    case 11:
        ui->room11_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_11);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_11_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_11);}");
        break;
    case 12:
        ui->room12_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_12);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_12_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_12);}");
        break;
    case 13:
        ui->room13_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_13);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_13_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_13);}");
        break;
    case 14:
        ui->room14_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_14);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_14_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_14);}");
        break;
    case 15:
        ui->room15_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_15);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_15_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_15);}");
        break;
    case 16:
        ui->room16_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_16);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_16_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_16);}");
        break;
    case 17:
        ui->room17_B->setStyleSheet("QPushButton{border-image: url(:/ROOM/USEDROOM_17);}"
                                               "QPushButton:hover{border-image: url(:/ROOM/USEDROOM_17_T);}"
                                               "QPushButton:checked{border-image: url(:/ROOM/CANCEL_17);}");
        break;

    }
}

void MainWindow::onNewConnection()
{
    QTcpSocket* clientSocket = _server.nextPendingConnection();
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(clientSocket,SIGNAL(stateChanged(QabstractSocket::SocketState)),this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    this->conn_D = new connection_Dialog(this);

    _sockets.push_back(clientSocket);
    for(QTcpSocket* socket:_sockets){
        socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString()+"connected to server !\n"));
    }
    conn_D->exec();
}

void MainWindow::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        _sockets.removeOne(sender);
    }
}

void MainWindow::onReadyRead()
{
    this->t_D = new test_Dialog(this);
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());

    QByteArray datas = sender->readAll();
    QString msg = QString::fromStdString(datas.toStdString());
    QStringList splited = msg.split(";");

    QString room_num = splited[0];
    int Int_room_num = room_num.toInt(); // int 타입 방 번호

    QString operation = splited[1]; // LOGOUT : "q" , sing : "s"

    // TEST
    if((Int_room_num==18)&&(operation=="q")){
        t_D->exec();
    }

    if((Int_room_num==18)&&(operation=="s")){
        t_D->exec();
    }

    Room* temp = &kiosk::getInstance()->getArr_room()[Int_room_num-1];

    // 방 나가기
    if((operation == "q")&&(kiosk::getInstance()->getArr_room()[Int_room_num-1].getOccupied()))
    {
        kiosk::getInstance()->logout(temp, Int_room_num, temp->getCurrentuser()->getPW());
        emit em_update_sig(Int_room_num);
    }

    // 노래 한 곡 부르기
    if((operation == "s")
            &&(temp->getOccupied())
            &&((temp->getSong_remain())!=0))
    {
       temp->setSong_remain(temp->getSong_remain()-1);
    }
    for (QTcpSocket* socket : _sockets) {
           if (socket != sender)
               socket->write(QByteArray::fromStdString(sender->peerAddress().toString().toStdString() + ": " + datas.toStdString()));
       }
}
