#ifndef INFO_DIALOG_H
#define INFO_DIALOG_H

#include <QDialog>
#include "User.h"

namespace Ui {
class info_Dialog;
}

class info_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit info_Dialog(QWidget *parent = nullptr);
    ~info_Dialog();
    User* getUser();
    void setUser(User* user);

private slots:
    void on_closeB_clicked();

private:
    Ui::info_Dialog *ui;
    User *user; // this dialog will show this user's data

};

#endif // INFO_DIALOG_H
