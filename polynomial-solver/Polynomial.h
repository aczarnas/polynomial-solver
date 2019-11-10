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
    List<Indeterminate>* p_mFirstDerivative;

    bool calculateDerivative();
public:
    Polynomial() : mPrecision(0.1){}
    Polynomial(double precision);
    double solveUsingPrediction(double hint);
    double solveStartingFromZero();
    void setPrimalForm(List<Indeterminate>* primal) {p_mPrimalForm = primal;}
    double getPrecision() {return mPrecision;}
};

#endif // POLYNOMIAL_H
