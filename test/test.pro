#-------------------------------------------------
#
# Project created by QtCreator 2015-08-20T14:21:17
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    autotest.h \
    testLocated.h \
    testDirection.h \
    testMovable.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../bin/release/ -lgridb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../bin/debug/ -lgridb
else:unix: LIBS += -L$$OUT_PWD/../bin/ -lgridb

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
