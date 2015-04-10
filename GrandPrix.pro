#-------------------------------------------------
#
# Project created by QtCreator 2011-11-29T15:25:36
#
#-------------------------------------------------

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}
#CONFIG += static static-libgcc


TARGET = GrandPrix
TEMPLATE = app

INCLUDEPATH += src
SOURCES += \
    src/main.cpp\
    src/grandprix.cpp \
    src/gpcontrolview.cpp \
    src/gpmapview.cpp \
    src/gpmapselector.cpp \
    src/gpcontrol.cpp \
    src/gpmap.cpp \
    src/gpdriverselector.cpp \
    src/finishdialog.cpp \
    src/gpprogression.cpp \
    src/car.cpp \
    src/headless.cpp

HEADERS  += \
    src/grandprix.h \
    src/gpcontrolview.h \
    src/gpmapview.h \
    src/gpmapselector.h \
    src/gpcontrol.h \
    src/gpmap.h \
    src/gpdriverselector.h \
    src/finishdialog.h \
    src/gpprogression.h \
    src/car.h \
    src/headless.h

FORMS    += \
    src/grandprix.ui \
    src/gpcontrolview.ui \
    src/gpmapview.ui \
    src/gpmapselector.ui \
    src/gpdriverselector.ui \
    src/finishdialog.ui \
    src/gpprogression.ui

RESOURCES += \
    res.qrc

TRANSLATIONS = GrandPrix_fr_FR.ts GrandPrix_en_EN.ts

OBJECTS_DIR=bin
MOC_DIR=bin
UI_DIR=bin
RCC_DIR=bin

