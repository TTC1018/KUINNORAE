#include "phone_num.h"
#include "ui_phone_num.h"

Phone_num::Phone_num(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Phone_num)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Phone_num::~Phone_num()
{
    delete ui;
}

void Phone_num::on_closeB_clicked()
{
    this->close();
}
