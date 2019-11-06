#ifndef POLYNOMIALTEST_H
#define POLYNOMIALTEST_H

#include <QObject>
#include <QTest>

class PolynomialTest : public QObject
{
    Q_OBJECT
public:
    explicit PolynomialTest(QObject *parent = nullptr);

signals:

private slots:
    void cleanup();
    void SecondDegreePolynomial_SolveWithWithoutPrediction_ProperResult();
    void FourthDegreePolynomial_SolveWithWithoutPrediction_ProperResult();
    void SecondDegreePolynomialsMinMaxAtZero_SolveStartingFromZero_ProperResults();
};

#endif // POLYNOMIALTEST_H
