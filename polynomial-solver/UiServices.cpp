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
