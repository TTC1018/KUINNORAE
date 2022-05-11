#include "test_dialog.h"
#include "ui_test_dialog.h"

test_Dialog::test_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test_Dialog)
{
    ui->setupUi(this);
}

test_Dialog::~test_Dialog()
{
    delete ui;
}

void test_Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    this->close();
}
