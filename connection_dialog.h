#ifndef CONNECTION_DIALOG_H
#define CONNECTION_DIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class connection_Dialog;
}

class connection_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit connection_Dialog(QWidget *parent = nullptr);
    ~connection_Dialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::connection_Dialog *ui;
};

#endif // CONNECTION_DIALOG_H
