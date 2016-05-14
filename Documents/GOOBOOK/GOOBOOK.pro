#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T22:42:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = GOOBOOK
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    btn.cpp \
    resultwindow.cpp \
    taiko2.cpp \
    taiko3.cpp \
    taiko4.cpp \
    play.cpp \
    time.cpp \
    score.cpp \
    drum.cpp \
    drum2.cpp \
    game.cpp \
    taiko.cpp \
    pause.cpp

HEADERS  += mainwindow.h \
    btn.h \
    resultwindow.h \
    taiko.h \
    taiko2.h \
    taiko3.h \
    taiko4.h \
    play.h \
    time.h \
    score.h \
    drum.h \
    drum2.h \
    game.h \
    pause.h

FORMS    += mainwindow.ui \
    resultwindow.ui

RESOURCES += \
    res.qrc
