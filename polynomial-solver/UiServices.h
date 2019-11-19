//! Helper namespace with services used by UI
#ifndef UISERVICES_H
#define UISERVICES_H

#include <QFile>
#include <QTableWidget>
#include "Polynomial.h"

namespace UiServices {
    /*!
     * \brief Reads whole file and saves content to provided object.
     * \param [in] filePath Absolute path to file.
     * \param [out] readText Reference to object which will hold text from file.
     * \return True if everything went well, false when file could not have been opened.
     */
    bool readFromFile(const QString filePath, QString& readText);
    /*!
     * \brief Writes provided text to file.
     * \param [in] filePath Absolute path to file.
     * \param [in] textToWrite Object with text to be written to file.
     * \return True if everything went well, false when file could not have been opened.
     */
    bool writeToFile(const QString filePath, const QString textToWrite);
    /*!
     * \brief Parses polynomial from text input loaded as csv.
     * \param [out] poly Reference to object holding polynomial.
     * \param [in] input Text input to parse.
     * \return False when input contains nothing, true after successful parsing.
     */
    bool parsePolynomialFromCsv(Polynomial& poly, const QString input);
    /*!
     * \brief Parses polynomials indeterminates to form, which is human-readable.
     * \param [in] polynomial Indeterminates holder.
     * \return Parsed text.
     */
    QString parseIndeterminateListToReadableString(List<Indeterminate>* polynomial);
    /*!
     * \brief Generates from polynomial well-constructed string which can be saved to file.
     * \param [in] poly Reference to polynomial.
     * \return Generated string.
     */
    QString generateCsvFromPolynomial(Polynomial& poly);
    /*!
     * \brief Fills provided table with data of existing polynomial. If polynomial wasn't loaded,
     *      does nothing.
     * \param [in] poly Polynomial object with required data.
     * \param [in, out] table Table to fill.
     */
    void fillTableWithPolynomialData(Polynomial& poly, QTableWidget* table);
    /*!
     * \brief Updates polynomial after edits made inside modal dialog.
     * \param [in, out] poly Polynomial object to update.
     * \param [in] table Table with edited data.
     */
    void updatePolynomialDataFromUi(Polynomial& poly, QTableWidget* table);
}

#endif // UISERVICES_H
