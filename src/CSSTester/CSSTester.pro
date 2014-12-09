#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T01:02:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSSTester
TEMPLATE = app


SOURCES += main.cpp\
        csstester.cpp

HEADERS  += csstester.h

FORMS    += csstester.ui
win32: RC_ICONS = icon.ico
macx: ICON = icon.icns
