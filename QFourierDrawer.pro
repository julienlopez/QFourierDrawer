#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T17:52:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFourierDrawer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    fourierdrawer.cpp \
    fourierbuilder.cpp

HEADERS += \
        mainwindow.hpp \
    fourierdrawer.hpp \
    fourierbuilder.hpp \
    fourier.hpp
