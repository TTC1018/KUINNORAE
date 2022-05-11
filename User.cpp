#include "User.h"

User::User(){

}

User::User(QString id, QString pw, int song_num) {
    this->id = id;
    this->pw = pw;
    this->song_num = song_num;
}

QString User::getID(){
    return this->id;
}

void User::setID(QString idInput) {
    this->id = idInput;
}

QString User::getPW() {
    return this->pw;
}

void User::setPW(QString pwInput) {
    this->pw = pwInput;
}

int User::getSong_num() {
    return this->song_num;
}

void User::setSong_num(int songInput) {
    this->song_num = songInput;
}
