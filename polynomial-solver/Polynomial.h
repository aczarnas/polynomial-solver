#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "List.h"

struct Indeterminate{
    double mConstant;
    int mPower;

    Indeterminate(double constant, int power): mConstant(constant), mPower(power) {}
};

class Polynomial
{
    double mPrecision;
    List<Indeterminate>* p_mPrimalForm;
public:
    Polynomial() : mPrecision(0.1){}
    Polynomial(double precision);
    double solveUsingPrediction(double hint);
    double solveStartingFromZero();
    void setPrimalForm(List<Indeterminate>* primal);
};

#endif // POLYNOMIAL_H
