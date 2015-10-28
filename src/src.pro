#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T12:53:50
#
#-------------------------------------------------

QT       -= gui

TARGET = gridb
TEMPLATE = lib

DEFINES += GRIDB_LIBRARY

DESTDIR = ../bin
MOC_DIR = ../build/moc
RCC_DIR = ../build/rcc
UI_DIR = ../build/ui

unix:OBJECTS_DIR = ../build/o/unix
win32:OBJECTS_DIR = ../build/o/win32
macx:OBJECTS_DIR = ../build/o/mac

SOURCES += located.cpp \
    direction.cpp \
    movable.cpp \
    coord.cpp \
    coordselecter.cpp

HEADERS += located.h\
        src_global.h \
    direction.h \
    movable.h \
    coord.h \
    coordselecter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
