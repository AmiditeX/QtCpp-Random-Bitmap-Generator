#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T23:19:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BitmapGenerator
TEMPLATE = app


SOURCES += main.cpp\
        uidisplay.cpp \
    generator.cpp \
    bitmap.cpp

HEADERS  += uidisplay.h \
    generator.h \
    bitmap.h

FORMS    += uidisplay.ui
