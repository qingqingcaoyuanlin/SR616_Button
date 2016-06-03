#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T14:38:27
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SR616_Button
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serial.cpp

HEADERS  += mainwindow.h \
    serial.h

FORMS    += mainwindow.ui
