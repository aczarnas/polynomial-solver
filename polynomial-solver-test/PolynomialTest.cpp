#include "PolynomialTest.h"
#include "Polynomial.h"
#include "helpers.h"
#include <iostream>

PolynomialTest::PolynomialTest(QObject *parent) : QObject(parent)
{

}

void PolynomialTest::cleanup()
{

}

void PolynomialTest::SecondDegreePolynomial_SolveWithWithoutPrediction_ProperResult()
{
    Indeterminate zero(-21.0, 0);
    Indeterminate first(4.0, 1);
    Indeterminate second(1.0, 2);

    Polynomial tested;
    List<Indeterminate> poly;
    poly.append(zero);
    poly.append(first);
    poly.append(second);
    tested.setPrimalForm(&poly);

    double polyZero[] = {-7.0, 3.0};

    QVERIFY(compareDoubles(tested.solveStartingFromZero(), polyZero[1], tested.getPrecision()));
    QVERIFY(compareDoubles(tested.solveUsingPrediction(-5), polyZero[0], tested.getPrecision()));
}

void PolynomialTest::FourthDegreePolynomial_SolveWithWithoutPrediction_ProperResult()
{
    Indeterminate zero(60.0, 0);
    Indeterminate first(31.0, 1);
    Indeterminate second(-32.0, 2);
    Indeterminate third(-1.0, 3);
    Indeterminate fourth(2.0, 4);

    Polynomial tested;
    List<Indeterminate> poly;
    poly.append(zero);
    poly.append(first);
    poly.append(second);
    poly.append(third);
    poly.append(fourth);
    tested.setPrimalForm(&poly);

    double polyZero[] = {-4.0, -1.0, 2.5, 3.0};

    QVERIFY(compareDoubles(tested.solveUsingPrediction(-3.5), polyZero[0], tested.getPrecision()));
    QVERIFY(compareDoubles(tested.solveUsingPrediction(-1.5), polyZero[1], tested.getPrecision()));
    QVERIFY(compareDoubles(tested.solveUsingPrediction(2.0), polyZero[2], tested.getPrecision()));
    QVERIFY(compareDoubles(tested.solveUsingPrediction(2.8), polyZero[3], tested.getPrecision()));

    QVERIFY(compareDoubles(tested.solveStartingFromZero(), polyZero[1], tested.getPrecision()));
}

void PolynomialTest::SecondDegreePolynomialsMinMaxAtZero_SolveStartingFromZero_ProperResults()
{

}
