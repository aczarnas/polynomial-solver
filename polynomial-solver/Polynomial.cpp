#include "Polynomial.h"

#include <QStringBuilder>

bool Polynomial::calculateDerivative()
{
    if(this->p_mPrimalForm->getSize() < 1) {
        return false;
    }
    if(p_mFirstDerivative != nullptr){
        delete p_mFirstDerivative;
    }
    p_mFirstDerivative = new List<Indeterminate>();
    for(Node<Indeterminate>* node = this->p_mPrimalForm->getHead(); node != this->p_mPrimalForm->getTail(); node = node->getNext()){
        Indeterminate* calculated = new Indeterminate(node->getValue().mConstant * node->getValue().mPower, node->getValue().mPower - 1);
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

Polynomial &Polynomial::getInstance()
{
    static Polynomial instance;
    return instance;
}

double Polynomial::solveUsingPrediction(double hint)
{
    return hint;
}

double Polynomial::solveStartingFromZero()
{
    return 0.0;
}

List<Indeterminate> *Polynomial::getFirstDerivativePointer()
{
    return p_mFirstDerivative;
}
