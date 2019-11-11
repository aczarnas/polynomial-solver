//! Helper namespace with services used by UI
#ifndef UISERVICES_H
#define UISERVICES_H

#include <QFile>
#include "Polynomial.h"

namespace UiServices {
    bool readFromFile(const QString filePath, QString& readText);
    bool writeToFile(const QString filePath, const QString textToWrite);
    bool parsePolynomialFromCsv(Polynomial& poly, const QString input);
    QString parseIndeterminateListToReadableString(List<Indeterminate>* polynomial);
    QString generateCsvFromPolynomial(Polynomial& poly);
}

#endif // UISERVICES_H
