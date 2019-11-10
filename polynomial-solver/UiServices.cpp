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
