#include "charge_dialog.h"
#include "ui_charge_dialog.h"
#include "charge_dialog2.h"
#include "kiosk.h"
#include "thread"

using namespace std;

charge_Dialog::charge_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charge_Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

charge_Dialog::~charge_Dialog()
{
    delete ui;
}

Room* charge_Dialog::getRoom(){
    return this->room;
}

void charge_Dialog::setRoom(Room* room){
    this->room = room;
}

User* charge_Dialog::getUser(){
    return this->user;
}

void charge_Dialog::setUser(User *user){
    this->user = user;
    ui->userId->setText(this->user->getID());
    ui->song_remain->setText(QString(QString::number(this->user->getSong_num())));
}

int charge_Dialog::getIndex(){
    return this->index;
}

void charge_Dialog::setIndex(int index){
    this->index = index;
}

void charge_Dialog::update(){
    ui->userId->setText(this->user->getID());
    ui->song_remain->setText(QString(QString::number(this->user->getSong_num())));
}

void charge_Dialog::on_b1_clicked()
{
    ui->using_song->insert(QString('1'));
}

void charge_Dialog::on_b2_clicked()
{
    ui->using_song->insert(QString('2'));
}

void charge_Dialog::on_b3_clicked()
{
    ui->using_song->insert(QString('3'));
}

void charge_Dialog::on_b4_clicked()
{
    ui->using_song->insert(QString('4'));
}

void charge_Dialog::on_b5_clicked()
{
    ui->using_song->insert(QString('5'));
}

void charge_Dialog::on_b6_clicked()
{
    ui->using_song->insert(QString('6'));
}

void charge_Dialog::on_b7_clicked()
{
    ui->using_song->insert(QString('7'));
}

void charge_Dialog::on_b8_clicked()
{
    ui->using_song->insert(QString('8'));
}

void charge_Dialog::on_b9_clicked()
{
    ui->using_song->insert(QString('9'));
}

void charge_Dialog::on_b0_clicked()
{
    ui->using_song->insert(QString('0'));
}

void charge_Dialog::on_back_clicked()
{
    QString temp(ui->using_song->text());
    temp.chop(1);
    ui->using_song->setText(temp);
}

void charge_Dialog::on_cancel_B_clicked() // cancel button (close the window)
{
    this->close();
}

void charge_Dialog::on_charge_B_clicked() //charge button (on to the next)
{
    //this->close();
    charge_Dialog2 *c_D2 = new charge_Dialog2(this);
    c_D2->setUser(this->user);

    c_D2->setModal(true);
    c_D2->exec();

    this->update(); //update showed information
}


void charge_Dialog::on_use_B_clicked() //real login button
{
    int haveNum = ui->song_remain->text().toInt(); //user has these songs
    int useNum = ui->using_song->text().toInt();//user will use these songs


    if((haveNum >= useNum) && haveNum != 0 && useNum != 0){ //user has enough songs to sing

    kiosk::getInstance()->room_reserve(this->user, this->index, useNum); //room reserving
    this->close();

    connect(this, SIGNAL(login_sig()), this->parent()->parent(), SLOT(ud_empty_minus())); // if logged in, send login signal to mainwindow, and change emptyroom number text box
    connect(this, SIGNAL(login_img_sig(int)), this->parent()->parent(), SLOT(used_img(int)));
    emit login_sig();
    emit login_img_sig(this->getIndex());

    std::thread SingTh(&Room::sing, this->getRoom()); // sing Thread per 10 second
    SingTh.detach(); //running background

    }
    else{ //user doesn't have enough songs to sing
        ui->message->setText("올바른 곡수를 입력하세요");
    }
}
