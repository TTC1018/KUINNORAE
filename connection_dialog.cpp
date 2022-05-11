#include "connection_dialog.h"
#include "ui_connection_dialog.h"

connection_Dialog::connection_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connection_Dialog)
{
    ui->setupUi(this);
}

connection_Dialog::~connection_Dialog()
{
    delete ui;
}

void connection_Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    this->close();
}
