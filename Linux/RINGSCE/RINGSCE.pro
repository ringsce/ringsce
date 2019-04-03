#-------------------------------------------------
#
# Project created by QtCreator 2019-04-02T13:12:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RINGSCE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    highlighter.cpp \
    new_file.cpp \
    settings.cpp \
    about.cpp \
    update.cpp \
    new_project.cpp \
    splashscreen.cpp

HEADERS += \
        mainwindow.h \
    highlighter.h \
    splashscreen.h \
    ui_new_file.h \
    ui_new_project.h

FORMS += \
        mainwindow.ui \
    new_file.ui \
    new_project.ui \
    below_stack.ui

RESOURCES += qdarkstyle/style.qrc

DISTFILES += \
    RINGSCE_v2.png
