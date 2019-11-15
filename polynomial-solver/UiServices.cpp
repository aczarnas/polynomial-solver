#include "UiServices.h"

#include <QTextStream>

bool UiServices::readFromFile(const QString filePath, QString& readText)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }

    QTextStream in(&file);
    readText = in.readAll();
    return true;
}
bool UiServices::writeToFile(const QString filePath, const QString textToWrite)
{
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return false;
    }

    QTextStream out(&file);
    out << textToWrite;
    return true;
}

bool UiServices::parsePolynomialFromCsv(Polynomial& poly, const QString input)
{
    auto lines = input.split('\n');
    if(lines.empty())
    {
        return false;
    }
    auto line = lines.constBegin();

    if(lines[0].contains("x_power")){
        ++line;
    }

    auto primal = poly.getPrimalFormPointer();
    primal->clear();
    while(line != lines.constEnd()) {
        auto args = line->split(',');
        if(args.size() < 2) {
            break;
        }
        Indeterminate curr(args[1].toInt(), args[0].toInt());
        primal->append(curr);
        ++line;
    }
    return true;
}

QString UiServices::parseIndeterminateListToReadableString(List<Indeterminate>* polynomial)
{
    QString result("");
    Node<Indeterminate>* curr = polynomial->getHead();
    while(curr != nullptr){
        if(curr->getValue().mCoefficient == 0.0) {
            continue;
        } else if(curr->getValue().mCoefficient > 0) {
            result.append("+");
        }
        result.append(QString("%1x^%2").arg(curr->getValue().mCoefficient).arg(curr->getValue().mPower));
        curr = curr->getNext();
    }
    return result;
}

QString UiServices::generateCsvFromPolynomial(Polynomial& poly)
{
    QString result("x_power,x_constant\n");
    Node<Indeterminate>* curr = poly.getPrimalFormPointer()->getHead();
    while(curr != nullptr){
        result.append(QString("%1,%2\n").arg(curr->getValue().mPower).arg(curr->getValue().mCoefficient));
        curr = curr->getNext();
    }
    return result;
}
