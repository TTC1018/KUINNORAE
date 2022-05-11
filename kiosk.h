#pragma once
#include "Room.h"
#include "mainwindow.h"
#include <vector>
#include <mutex>

#include <QString>
#include <QObject>

using namespace std;

class kiosk : public QObject
{
    Q_OBJECT



private:

    Room arr_room[17]; //Room- 17
    vector<User> arr_account; //User's accounts repository :vector


    kiosk(){

    }
    ~kiosk(){}

    static kiosk *instance; //declare with singleton, created autimatically when program starts.

public:


    mutex mu;
    static kiosk *getInstance(); //Singleton object getter

    vector<User>* getArr_account();
	void setArr_account();
	Room* getArr_room();
	void setArr_room();


	void main_controller(void); // main controller
    bool registration(QString id, QString pw, bool *overlap);
//    bool login(QString id, QString pw, int idx);//Login method using search
    bool search(QString id, QString pw);
    /* first, search Id and then search Pw. If both of them is correct, return true */
    bool logout(Room *room, int idx, QString pw);
    bool checkId(QString id);//id searching
    void recharge(User *user,int songnum);//recharge the songnum
    void room_reserve(User *user, int idx, int songNum);
    void refresh_room(int idx); // refresh room : song->0 user->NULL occupied:false

    User* return_user(QString id); // return vector's idx
	void check_zero();

signals:
    void logout_sig();
    void login_sig();

	

};

