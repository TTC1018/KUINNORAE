#include "info_dialog.h"
#include "ui_info_dialog.h"

info_Dialog::info_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info_Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

info_Dialog::~info_Dialog()
{
    delete ui;
}

void info_Dialog::setUser(User* user){
    this->user = user;
    ui->phone_Num->setText(user->getID());
    ui->remain_Song->setText(QString::number(user->getSong_num()));
}

User* info_Dialog::getUser(){
    return this->user;
}

void info_Dialog::on_closeB_clicked()
{
    this->close();
}
