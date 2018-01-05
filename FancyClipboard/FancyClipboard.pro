#-------------------------------------------------
#
# Project created by QtCreator 2018-01-04T17:00:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FancyClipboard
TEMPLATE = app

TRANSLATIONS += fc.ts


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

DISTFILES += \
    icon/app.png \
    icon/html.png \
    icon/img.png \
    icon/text.png

RESOURCES += \
    resources.qrc
