#include "kiosk.h"
#include "User.h"
#include "Room.h"
#include <vector>
#include <iostream>
#include <thread>
#include <stdio.h>

#define STR_EQUAL 0

using namespace std;

kiosk *kiosk::instance = nullptr;

kiosk *kiosk::getInstance(){
    if(instance == nullptr){
        instance = new kiosk();
    }

    return instance;
}


bool kiosk::registration(QString id, QString pw, bool *overlap) {
    int idlen = id.length();
    int pwlen = pw.length();

    if ((idlen == 11) && (pwlen == 4)) // id length should be 11, pw length should be 4
    {

        if(!checkId(id)) //
        { //There's no overlapped ID
            User usr(id, pw, 0);
            arr_account.push_back(usr);
            return true;
        }
        else
        {
            *overlap = true;
            return false;
        }

    }
    else //failed
    {
      return false;
    }
}

void kiosk::room_reserve(User *user, int idx, int songNum) {
    user->setSong_num(user->getSong_num() - songNum);
    
    arr_room[idx - 1].setSong_remain(songNum);
    arr_room[idx - 1].setCurrentuser(user);
    arr_room[idx - 1].setOccupied(true);
}

void kiosk::refresh_room(int idx) {
    int left = arr_room[idx - 1].getSong_remain();
    User *tmp = arr_room[idx - 1].getCurrentuser();
    tmp->setSong_num(tmp->getSong_num() + left); // return left songs to user's account

    //function : refreshing room
    arr_room[idx - 1].setSong_remain(0);
    arr_room[idx - 1].setOccupied(false);
    arr_room[idx - 1].setCurrentuser(new User());

}

vector<User>* kiosk::getArr_account() {
    return &this->arr_account;
}

void kiosk::setArr_account(){

}

Room* kiosk::getArr_room(){
    return this->arr_room;
}

void kiosk::setArr_room(){

}

//bool kiosk::login(QString id, QString pw, int idx) {
//    bool loginresult = search(id, pw);
//    if (!loginresult)
//        return loginresult; //login fail
//    else {
//        int i = return_idx(id);
//        room_reserve(getArr_account()[i], idx);

//    }
//}

bool kiosk::search(QString id, QString pw) {

    if (!checkId(id))
    {
        return false;
    }
    else
    {
        int size;
        size = getArr_account()->size();
        User* temp;

        for (int i = 0; i < size; i++) {
            temp = &getArr_account()->at(i);
            if ((QString::compare(temp->getID(), id, Qt::CaseInsensitive) == STR_EQUAL) && (QString::compare(temp->getPW(), pw, Qt::CaseInsensitive) == STR_EQUAL)) {
                    return true;
                }
            }

        return false;
    }
}

bool kiosk::logout(Room* room, int idx, QString pw) {
    if (QString::compare(room->getCurrentuser()->getPW(), pw, Qt::CaseInsensitive) == STR_EQUAL)/*if pw is correct*/
    {
     refresh_room(idx);
     emit logout_sig();
     return true; // logout success
    }
    else {
        return false; // pw error
    }
}

bool kiosk::checkId(QString id) {// ID overlap check

    int size; // ID Database Array's size

    bool check = false;

    size = getArr_account()->size(); //get Database size

    QString temp;
    for (int i = 0; i < size; i++) {
        temp = getArr_account()->at(i).getID();
        if (QString::compare(temp, id, Qt::CaseInsensitive) == STR_EQUAL) {
            check = true; // overlapped ID
            break;
        }
    }

    return check;
}

User* kiosk::return_user(QString id) {
    int size = getArr_account()->size();

    User *user = nullptr;
    User *temp;

    for (int i = 0; i < size; i++) {
        temp = &getArr_account()->at(i);
        if (QString::compare(temp->getID(), id, Qt::CaseInsensitive) == STR_EQUAL) {
            user = temp;
        }
    }



    return user;
}


void kiosk::check_zero() {//thread: check the room's song num, if it is 0 refresh the room.
    int i;
    while (1) {
        for (i = 0; i < 17; i++) {
            if (getArr_room()[i].getSong_remain() == 0) {
                getArr_room()[i].setCurrentuser(new User());
                getArr_room()[i].setOccupied(false);
            }
        }
    }
}

void kiosk::recharge(User *user,int songnum){
    int user_song = user->getSong_num();
    user->setSong_num(user_song + songnum);
}
