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
    Polynomial();
    Polynomial(double precision);
    double solveUsingPrediction(double hint);
    double solveStartingFromZero();
    void setPrecision(double precision) {mPrecision = precision;}
    double getPrecision() {return mPrecision;}
    List<Indeterminate>* getPrimalFormPointer() {return p_mPrimalForm;}
};

#endif // POLYNOMIAL_H
