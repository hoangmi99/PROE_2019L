#-------------------------------------------------
#
# Project created by QtCreator 2019-05-31T00:26:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJEKT3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        instrumenty_dialog.cpp \
        instrumenty_smyczkowe.cpp \
        kontrabas.cpp \
        koszyk.cpp \
        main.cpp \
        mainwindow.cpp \
        nozka_kontrabasu.cpp \
        podbrodek.cpp \
        skrzypce.cpp \
        skrzypce_elektryczne.cpp \
        smyczek.cpp \
        wyjscie.cpp

HEADERS += \
        instrumenty_dialog.h \
        instrumenty_smyczkowe.h \
        kontrabas.h \
        koszyk.h \
        mainwindow.h \
        nozka_kontrabasu.h \
        podbrodek.h \
        skrzypce.h \
        skrzypce_elektryczne.h \
        smyczek.h \
        wyjscie.h

FORMS += \
        instrumenty_dialog.ui \
        koszyk.ui \
        mainwindow.ui \
        wyjscie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
