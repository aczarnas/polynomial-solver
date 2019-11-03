#include "Polynomial.h"

Polynomial::Polynomial(double precision) : mPrecision(precision)
{

}

double Polynomial::solveUsingPrediction(double hint)
{
    return hint;
}

double Polynomial::solveStartingFromZero()
{
    return 0.0;
}

void Polynomial::setPrimalForm(List<Indeterminate>* primal) {p_mPrimalForm = primal;}
