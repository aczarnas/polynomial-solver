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

    double polyZero1 = 3.0;
    double polyZero2 = -7.0;

    tested.setPrimalForm(&poly);

    QVERIFY(compareDoubles(tested.solveStartingFromZero(), polyZero1, tested.getPrecision()));
    QVERIFY(compareDoubles(tested.solveUsingPrediction(-5), polyZero2, tested.getPrecision()));
}

void PolynomialTest::FourthDegreePolynomial_SolveWithWithoutPrediction_ProperResult()
{

}

void PolynomialTest::SecondDegreePolynomialsMinMaxAtZero_SolveStartingFromZero_ProperResults()
{

}
