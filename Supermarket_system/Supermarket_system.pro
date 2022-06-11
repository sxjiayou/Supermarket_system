#-------------------------------------------------
#
# Project created by QtCreator 2022-06-06T11:05:27
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Supermarket_system
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui

RESOURCES += \
    res.qrc

CONFIG += C++11
