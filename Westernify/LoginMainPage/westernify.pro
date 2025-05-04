QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = westernify
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
        globle.cpp \
        insertlogin.cpp \
        mainpage.cpp \


HEADERS  += mainwindow.h \
        globle.h \
        insertlogin.h \
        mainpage.h \

FORMS    += mainwindow.ui \
            insertlogin.ui \
            mainpage.ui \

QT       += sql

