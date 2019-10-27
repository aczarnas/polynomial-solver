QT     += core widgets testlib
CONFIG += c++17 console

TARGET = polynomial-solver-test
TEMPLATE = app

include(../polynomial-solver-src.pri)

POLYNOMIAL_SOLVER_PATH = ../polynomial-solver
INCLUDEPATH += $$POLYNOMIAL_SOLVER_PATH
DEPENDPATH += $$POLYNOMIAL_SOLVER_PATH

SOURCES +=  \
    listtest.cpp \
    main.cpp

HEADERS += \
    listtest.h \
    main.moc

DISTFILES += \
    main.moc
