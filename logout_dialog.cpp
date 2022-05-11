#include "logout_dialog.h"
#include "ui_logout_dialog.h"
#include "kiosk.h"

#include <thread>

using namespace std;

logout_Dialog::logout_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logout_Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

logout_Dialog::~logout_Dialog()
{
    delete ui;
}

Room* logout_Dialog::getRoom(){
    return this->room;
}

void logout_Dialog::setRoom(Room* room){
    this->room = room;
}

int logout_Dialog::getIndex(){
    return this->index;
}

void logout_Dialog::setIndex(int index){
    this->index = index;
}

void logout_Dialog::on_yesB_clicked()
{
    if(this->getRoom()->getOccupied()){
    bool logout = kiosk::getInstance()->logout(this->room, this->index, this->passwd);

        if(logout){
            connect(this, SIGNAL(logout_sig(int)), this->parent(), SLOT(empty_img(int))); //connect to with mainwindow, it will send logout signal to main, and change button image
            emit logout_sig(this->getIndex());
            this->close();
        }
        else{
            ui->message->setText("비밀번호가 일치하지 않습니다");
            ui->pw_box->clear();
            this->passwd.clear();
        }
    }
    else{ // error prevention
        ui->message->setText("이미 사용이 종료된 방입니다");
        this->close();
    }
}

void logout_Dialog::on_noB_clicked()
{
 this->close();
}

void logout_Dialog::on_num1_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('1');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num2_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('2');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num3_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('3');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num4_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('4');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num5_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('5');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num6_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('6');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num7_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('7');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num8_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('8');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num9_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('9');
        ui->pw_box->insert("*");
    }
}

void logout_Dialog::on_num0_clicked()
{
    int pw_len = this->passwd.length();
    if(pw_len < 4){
        this->passwd.append('0');
        ui->pw_box->insert("*");
    }
}
