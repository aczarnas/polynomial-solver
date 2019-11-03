#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct Indeterminate{
    double mConstant;
    int mPower;

    Indeterminate(double constant, int power): mConstant(constant), mPower(power) {}
};

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
