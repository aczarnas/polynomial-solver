QT     += core gui widgets
CONFIG += c++17

TARGET = polynomial-solver
TEMPLATE = app

include(../polynomial-solver-src.pri)

SOURCES += main.cpp \
    EditCsvDataDialog.cpp \
    MainWindow.cpp \
    UiServices.cpp

HEADERS += \
    EditCsvDataDialog.h \
    MainWindow.h \
    UiServices.h

FORMS += \
    EditCsvDataDialog.ui \
    MainWindow.ui
