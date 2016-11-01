#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T13:54:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BetfairLibExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    eventsmodel.cpp

HEADERS  += mainwindow.h \
    eventsmodel.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BetfairLib/release/ -lBetfairLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BetfairLib/debug/ -lBetfairLib
else:unix: LIBS += -L$$OUT_PWD/../BetfairLib/ -lBetfairLib

INCLUDEPATH += $$PWD/../BetfairLib
DEPENDPATH += $$PWD/../BetfairLib
