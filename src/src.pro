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

CONFIG += c++11

unix:OBJECTS_DIR = ../build/o/unix
win32:OBJECTS_DIR = ../build/o/win32
macx:OBJECTS_DIR = ../build/o/mac

SOURCES += \
    direction.cpp \
    coordselecter.cpp \
    gridcoordselecter.cpp \
    listcoordselecter.cpp \
    manhattandistancefunction.cpp \
    diagonaldistancefunction.cpp \
    euclideandistancefunction.cpp \
    squaredeuclideandistancefunction.cpp \
    gridlistcoordselecter.cpp
HEADERS += \
    abstractlocated.h \
    located.h \
    abstractmovable.h \
    movable.h \
    coord.h \
    direction.h \
    coordselecter.h \
    gridcoordselecter.h \
    listcoordselecter.h \
    abstractdistancefunction.h \
    manhattandistancefunction.h \
    diagonaldistancefunction.h \
    euclideandistancefunction.h \
    squaredeuclideandistancefunction.h \
    moveevent.h \
    gridlistcoordselecter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
