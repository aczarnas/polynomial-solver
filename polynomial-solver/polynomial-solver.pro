QT     += core gui widgets
CONFIG += c++17

TARGET = polynomial-solver
TEMPLATE = app

include(../polynomial-solver-src.pri)

SOURCES += main.cpp \
    LoadCsvDataDialog.cpp \
    MainWindow.cpp \
    UiServices.cpp

HEADERS += \
    LoadCsvDataDialog.h \
    MainWindow.h \
    UiServices.h

FORMS += \
    LoadCsvDataDialog.ui \
    MainWindow.ui
