#include "song_charge.h"
#include "ui_song_charge.h"

song_charge::song_charge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::song_charge)
{
    ui->setupUi(this);
}

song_charge::~song_charge()
{
    delete ui;
}
