#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T13:01:22
#
#-------------------------------------------------

QT       += core widgets
QMAKE_CXXFLAGS += -std=c++11

TARGET = yata
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    oglwidget.cpp \
    drawtools.cpp

HEADERS  += \
    common.hpp \
    drawtools.hpp \
    oglwidget.hpp \
    mainwindow.hpp

FORMS    += mainwindow.ui
