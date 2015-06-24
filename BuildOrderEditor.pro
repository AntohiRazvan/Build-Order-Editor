#-------------------------------------------------
#
# Project created by QtCreator 2015-06-23T15:51:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BuildOrderEditor
TEMPLATE = app


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    itemview.cpp \
    action.cpp \
    item.cpp \
    model.cpp \
    unittypes.cpp


HEADERS  += \
    mainwindow.h \
    itemview.h \
    action.h \
    item.h \
    model.h \
    unittypes.h

FORMS    += mainwindow.ui

CONFIG += c++11

