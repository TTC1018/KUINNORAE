#pragma once
#include "User.h"

using namespace std;

class Room
{
private:
    int song_remain; //left song
    User *currentUser; //User in room now
    bool occupied; //Is room using or not


public:
	Room();

    void* sing(); // thread: sing (each 10 sec)
	int getSong_remain();
	void setSong_remain(int songInput);
    User* getCurrentuser();
    void setCurrentuser(User *user);
	bool getOccupied();
	void setOccupied(bool status);

};
