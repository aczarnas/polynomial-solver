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
    calculateDerivative();
    return hint;
}

double Polynomial::solveStartingFromZero()
{
    calculateDerivative();
    return 0.0;
}

QString Polynomial::getFirstDerivativeAsString()
{
    QString result("");
    Node<Indeterminate>* curr = p_mFirstDerivative->getHead();
    while(curr != nullptr){
        if(curr->getValue().mConstant == 0.0) {
            continue;
        } else if(curr->getValue().mConstant > 0) {
            result.append("+");
        }
        result.append(QString("%1x^%2").arg(curr->getValue().mConstant).arg(curr->getValue().mPower));
        curr = curr->getNext();
    }
    return result;
}
