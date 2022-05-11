#include "register_dialog.h"
#include "ui_register_dialog.h"
#include "kiosk.h"

register_Dialog::register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

register_Dialog::~register_Dialog()
{
    delete ui;
}


void register_Dialog::on_b1_clicked() // 버튼 1 눌렸을 때
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('1')); //전화번호가 꽉 차기 전까지는 전화번호 텍스트 상자에 문자열을 추가함
    else ui->passwd->insert(QString('1')); //꽉 차면 패스워드 텍스트 상자에 문자열 추가
}

void register_Dialog::on_b2_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('2'));
    else ui->passwd->insert(QString('2'));
}

void register_Dialog::on_b3_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('3'));
    else ui->passwd->insert(QString('3'));
}

void register_Dialog::on_b4_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('4'));
    else ui->passwd->insert(QString('4'));
}

void register_Dialog::on_b5_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('5'));
    else ui->passwd->insert(QString('5'));
}

void register_Dialog::on_b6_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('6'));
    else ui->passwd->insert(QString('6'));
}

void register_Dialog::on_b7_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('7'));
    else ui->passwd->insert(QString('7'));
}

void register_Dialog::on_b8_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('8'));
    else ui->passwd->insert(QString('8'));
}

void register_Dialog::on_b9_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('9'));
    else ui->passwd->insert(QString('9'));
}

void register_Dialog::on_b0_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('0'));
    else ui->passwd->insert(QString('0'));
}

void register_Dialog::on_back_clicked() //지우기 버튼
{
    if(ui->phoneNum->text().length() < 11) // 전화번호(ID) 다 안 적었을 때는, 전화번호 텍스트를 지움
    {
        QString temp(ui->phoneNum->text());
        temp.chop(1);
        ui->phoneNum->setText(temp);
    }
    else if((ui->phoneNum->text().length() == 11) && (ui->passwd->text() == NULL)) //전화번호가 다 쓰여졌지만, 패스워드는 비어있을 때 전화번호를 지움
    {
        QString temp(ui->phoneNum->text());
        temp.chop(1);
        ui->phoneNum->setText(temp);
    }
    else if((ui->phoneNum->text().length() == 11) && (ui->passwd->text() != NULL)) //전화번호가 다 쓰여져 있고, 패스워드에도 텍스트가 있을 때 패스워드를 지움
    {
        QString temp(ui->passwd->text());
        temp.chop(1);
        ui->passwd->setText(temp);
    }
}

void register_Dialog::on_regi_cancel_clicked() //취소 버튼
{
    this->close(); //닫기
}


void register_Dialog::on_regi_ok_clicked() //등록 버튼
{

    QString id = ui->phoneNum->text();
    QString pw = ui->passwd->text();

    bool overlap = false; // ID overlap check
    bool registrating = kiosk::getInstance()->registration(id, pw, &overlap); // registration check

    if(registrating){
        this->close();
    }else{
        if(overlap){
            ui->message->setText("중복된 ID 입니다. 다른 ID를 입력하세요");
        }else{
            ui->message->setText("올바른 값을 입력하세요");
        }
    }

}
