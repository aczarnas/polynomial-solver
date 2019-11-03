#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
    double mPrecision;

public:
    Polynomial() : mPrecision(0.1){}
    Polynomial(double precision);
    double solveUsingPrediction(double hint);
    double solveStartingFromZero();
};

#endif // POLYNOMIAL_H
