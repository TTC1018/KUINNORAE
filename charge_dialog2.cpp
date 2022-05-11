#include "charge_dialog2.h"
#include "ui_charge_dialog2.h"
#include "kiosk.h"

charge_Dialog2::charge_Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charge_Dialog2)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

charge_Dialog2::~charge_Dialog2()
{
    delete ui;
}

void charge_Dialog2::setUser(User *user){
    this->user = user;

}

User* charge_Dialog2::getUser(){
    return this->user;
}

int charge_Dialog2::getIndex(){
    return this->index;
}

void charge_Dialog2::setIndex(int index){
    this->index = index;
}

void charge_Dialog2::on_price1000_4_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 1000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 4;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price2000_9_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 2000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 9;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price3000_14_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 3000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 14;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price4000_19_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 4000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 19;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price5000_24_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 5000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 24;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price7000_34_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 7000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 34;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price10000_49_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 10000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 49;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_price20000_100_clicked()
{
    int priceNum = ui->price_box->text().toInt();
    priceNum += 20000;
    ui->price_box->setText(QString::number(priceNum));


    int songNum = ui->song_box->text().toInt();
    songNum += 100;
    ui->song_box->setText(QString::number(songNum));
}

void charge_Dialog2::on_payB_clicked()
{
    int plus = ui->song_box->text().toInt();
    kiosk::getInstance()->recharge(this->user, plus);
    this->close();
}

void charge_Dialog2::on_clearB_clicked()
{
    ui->song_box->setText("0");
    ui->price_box->setText("0");
}

void charge_Dialog2::on_closeB_clicked()
{
        this->close();
}






