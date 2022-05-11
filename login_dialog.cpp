#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "kiosk.h"
#include "charge_dialog.h"
#include "info_dialog.h"

login_Dialog::login_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

login_Dialog::~login_Dialog()
{
    delete ui;
}

void login_Dialog::setIndex(int index){
    this->index = index;
}

int login_Dialog::getIndex(){
    return this->index;
}

void login_Dialog::setInfo_log(bool info_login){
    this->info_login = info_login;
}

bool login_Dialog::getInfo_log(){
    return this->info_login;
}

void login_Dialog::setMain_log(bool main_login){
    this->main_login = main_login;
}

bool login_Dialog::getMain_log(){
    return this->main_login;
}

void login_Dialog::on_b1_clicked() // 버튼 1 눌렸을 때
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('1')); //전화번호가 꽉 차기 전까지는 전화번호 텍스트 상자에 문자열을 추가함
    else ui->passwd->insert(QString('1')); //꽉 차면 패스워드 텍스트 상자에 문자열 추가
}

void login_Dialog::on_b2_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('2'));
    else ui->passwd->insert(QString('2'));
}

void login_Dialog::on_b3_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('3'));
    else ui->passwd->insert(QString('3'));
}

void login_Dialog::on_b4_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('4'));
    else ui->passwd->insert(QString('4'));
}

void login_Dialog::on_b5_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('5'));
    else ui->passwd->insert(QString('5'));
}

void login_Dialog::on_b6_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('6'));
    else ui->passwd->insert(QString('6'));
}

void login_Dialog::on_b7_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('7'));
    else ui->passwd->insert(QString('7'));
}

void login_Dialog::on_b8_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('8'));
    else ui->passwd->insert(QString('8'));
}

void login_Dialog::on_b9_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('9'));
    else ui->passwd->insert(QString('9'));
}

void login_Dialog::on_b0_clicked()
{
    if(ui->phoneNum->text().length() < 11) ui->phoneNum->insert(QString('0'));
    else ui->passwd->insert(QString('0'));
}

void login_Dialog::on_back_clicked() //지우기 버튼
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

void login_Dialog::on_login_ok_clicked()
{
    QString id = ui->phoneNum->text();
    QString pw = ui->passwd->text();

    bool login = kiosk::getInstance()->search(id, pw);

    if(main_login){ // enter to room
        if(login)
        { //login success

            this->close();

            User *user = kiosk::getInstance()->return_user(id);
            charge_Dialog *c_D = new charge_Dialog(this);
            c_D->setUser(user);
            c_D->setIndex(this->index);
            c_D->setRoom(&kiosk::getInstance()->getArr_room()[this->index -1]);

            c_D->setModal(true);
            c_D->exec();
        }
        else
        {
            ui->message->setText("로그인에 실패하였습니다.");
        }
    }
    else if(info_login) //enter to User information window
    {
        if(login)
        {
            this->close();

            User *user = kiosk::getInstance()->return_user(id);
            info_Dialog *i_D = new info_Dialog(this);
            i_D->setUser(user);

            i_D->setModal(true);
            i_D->exec();
        }
        else
        {
            ui->message->setText("로그인에 실패하였습니다.");
        }
    }

}

void login_Dialog::on_login_cancel_clicked()
{
    this->close();
}
