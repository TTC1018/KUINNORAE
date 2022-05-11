#include "mainwindow.h"
#include "kiosk.h"
#include <QApplication>


void read(QString filename);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
