QT     += core widgets testlib
CONFIG += c++17 console

TARGET = polynomial-solver-test
TEMPLATE = app

include(../polynomial-solver-src.pri)

POLYNOMIAL_SOLVER_PATH = ../polynomial-solver
INCLUDEPATH += $$POLYNOMIAL_SOLVER_PATH
DEPENDPATH += $$POLYNOMIAL_SOLVER_PATH

SOURCES +=  \
    ListTest.cpp \
    PolynomialTest.cpp \
    main.cpp

HEADERS += \
    ListTest.h \
    PolynomialTest.h \
    helpers.h \
    main.moc

DISTFILES += \
    main.moc
