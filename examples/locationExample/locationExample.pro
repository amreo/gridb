#-------------------------------------------------
#
# Project created by QtCreator 2016-01-24T11:52:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = locationExample
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../bin/release/ -lgridb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../bin/debug/ -lgridb
else:unix: LIBS += -L$$OUT_PWD/../../bin/ -lgridb

INCLUDEPATH += $$PWD/../../src
DEPENDPATH += $$PWD/../../src
