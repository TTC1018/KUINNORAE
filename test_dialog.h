#ifndef TEST_DIALOG_H
#define TEST_DIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class test_Dialog;
}

class test_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit test_Dialog(QWidget *parent = nullptr);
    ~test_Dialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::test_Dialog *ui;
};

#endif // TEST_DIALOG_H
