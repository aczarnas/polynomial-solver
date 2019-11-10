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
    auto line = lines.begin();

    if(lines[0].contains("x_power")){
        ++line;
    }

    auto primal = poly.getPrimalFormPointer();
    primal->clear();
    while(line != lines.end()) {
        auto args = line->split(',');
        Indeterminate curr(args[0].toInt(),args[1].toInt());
        primal->append(curr);
        ++line;
    }
    return true;
}
