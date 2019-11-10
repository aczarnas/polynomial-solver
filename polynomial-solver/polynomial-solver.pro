QT     += core gui widgets
CONFIG += c++17

TARGET = polynomial-solver
TEMPLATE = app

include(../polynomial-solver-src.pri)

SOURCES += main.cpp \
    MainWindow.cpp \
    UiServices.cpp

HEADERS += \
    MainWindow.h \
    UiServices.h

FORMS += \
    MainWindow.ui
