#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T13:25:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = controller
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        about.cpp\
        connectioninfo.cpp\
        Joystick.cpp

HEADERS  += mainwindow.h\
     about.h\
     connectioninfo.h\
     Joystick.h

FORMS    += mainwindow.ui\
     about.ui\
     connectioninfobase.ui

VERSION = 0.1
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

INCLUDEPATH += . /usr/include/SDL
LIBS += -L/usr/include/SDL -lSDL

RESOURCES = resources/icons.qrc
