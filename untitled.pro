QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Room.cpp \
    User.cpp \
    charge_dialog.cpp \
    charge_dialog2.cpp \
    info_dialog.cpp \
    kiosk.cpp \
    login_dialog.cpp \
    logout_dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    phone_num.cpp \
    register_dialog.cpp \
    test_dialog.cpp

HEADERS += \
    Room.h \
    User.h \
    charge_dialog.h \
    charge_dialog2.h \
    info_dialog.h \
    kiosk.h \
    login_dialog.h \
    logout_dialog.h \
    mainwindow.h \
    phone_num.h \
    register_dialog.h \
    test_dialog.h

FORMS += \
    charge_dialog.ui \
    charge_dialog2.ui \
    info_dialog.ui \
    login_dialog.ui \
    logout_dialog.ui \
    mainwindow.ui \
    phone_num.ui \
    register_dialog.ui \
    test_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc \
    Images.qrc
