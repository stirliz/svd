#-------------------------------------------------
#
# Project created by QtCreator 2014-01-26T01:40:13
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = svd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    downloader.cpp \
    algo.cpp

INCLUDEPATH += include
LIBS += -Llib -lcurl -lgumbo

HEADERS  += mainwindow.h \
    downloader.h \
    algo.h

FORMS    += mainwindow.ui \
    algo.ui \
    paramentry.ui
