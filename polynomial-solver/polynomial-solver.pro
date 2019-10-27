QT     += core gui widgets
CONFIG += c++17

TARGET = polynomial-solver
TEMPLATE = app

include(../polynomial-solver-src.pri)

SOURCES += main.cpp \
    mainwindow.cpp \
    node.cpp

HEADERS += \
    mainwindow.h \
    node.h

FORMS += \
    mainwindow.ui
