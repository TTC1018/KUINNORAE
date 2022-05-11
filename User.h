#pragma once
#include <QString>

class User
{
	private:
        QString id;
        QString pw;
		int song_num;
public:
    User();
    User(QString id, QString pw, int song_num);
    QString getID();
    void setID(QString idInput);
    QString getPW();
    void setPW(QString pwInput);
    int getSong_num();
    void setSong_num(int songInput);

};

