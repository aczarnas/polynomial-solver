#ifndef UISERVICES_H
#define UISERVICES_H

#include <QFile>


namespace UiServices {
    bool readFromFile(const QString filePath, QString& readText);
    bool writeToFile(const QString filePath, const QString textToWrite);
}

#endif // UISERVICES_H
