#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T00:44:11
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = To-do
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    tasklist.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    tasklist.h

FORMS    += mainwindow.ui \
    dialog.ui \
    tasklist.ui
