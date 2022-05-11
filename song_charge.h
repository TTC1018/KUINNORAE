#ifndef SONG_CHARGE_H
#define SONG_CHARGE_H

#include <QWidget>

namespace Ui {
class song_charge;
}

class song_charge : public QWidget
{
    Q_OBJECT

public:
    explicit song_charge(QWidget *parent = nullptr);
    ~song_charge();

private:
    Ui::song_charge *ui;
};

#endif // SONG_CHARGE_H
