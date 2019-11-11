#include "Polynomial.h"

#include <cmath>

bool Polynomial::calculateDerivative()
{
    if(this->p_mPrimalForm->getSize() < 1) {
        return false;
    }
    if(p_mFirstDerivative != nullptr){
        delete p_mFirstDerivative;
    }
    p_mFirstDerivative = new List<Indeterminate>();
    Node<Indeterminate>* lastNode = this->p_mPrimalForm->getTail();
    for(Node<Indeterminate>* node = this->p_mPrimalForm->getHead(); node != lastNode; node = node->getNext()){
        if(node->getValue().mPower < 1) {
            return false; // something is wrong with polynomial, this method should never get to power below 1
        }
        Indeterminate* calculated = new Indeterminate(node->getValue().mCoefficient * node->getValue().mPower, node->getValue().mPower - 1);
        Node<Indeterminate>* current = new Node<Indeterminate>(*calculated);
        p_mFirstDerivative->append(current->getValue());
    }
    return true;
}

Polynomial::Polynomial() : mPrecision(0.1){
    p_mPrimalForm = new List<Indeterminate>();
    p_mFirstDerivative = new List<Indeterminate>();
}

Polynomial::~Polynomial()
{
    delete p_mPrimalForm;
    delete p_mFirstDerivative;
}

double Polynomial::functionValueAtPoint(List<Indeterminate>* functionHandler, double xPoint)
{
    double result = 0.0;
    for(Node<Indeterminate>* node = functionHandler->getHead(); node != nullptr; node = node->getNext()){
        Indeterminate curr = node->getValue();
        result += curr.mCoefficient * pow(xPoint, curr.mPower);
    }
    return result;
}

Polynomial &Polynomial::getInstance()
{
    static Polynomial instance;
    return instance;
}

double Polynomial::solveUsingPrediction(double hint)
{
    calculateDerivative();
    double result = hint;
    double previous = hint + mPrecision * 2;
    while(abs(result - previous) > mPrecision)
    {
        double polyValue = functionValueAtPoint(p_mPrimalForm, result);
        double deriValue = functionValueAtPoint(p_mFirstDerivative, result);
        previous = result;
        result = previous - polyValue/deriValue;
    }
    return result;
}

double Polynomial::solveStartingFromZero()
{
    return 0.0;
}

List<Indeterminate> *Polynomial::getFirstDerivativePointer()
{
    return p_mFirstDerivative;
}
