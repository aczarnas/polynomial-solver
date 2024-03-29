//! Polynomial singleton class
/*!
 * \class Polynomial
 * \brief Handler class for polynomial with solving methods
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <QString>
#include "List.h"

//! Indeterminate structure used with Polynomial class
struct Indeterminate
{
    //! Coefficient floating-point number of indeterminate
    double mCoefficient;
    //! Power integer of Indeterminate
    int mPower;

    //! Default constructor for structure
    /*!
     * \param constant coefficient value of Indeterminate
     * \param power power value of Indeterminate
     */
    Indeterminate(double coefficient, int power): mCoefficient(coefficient), mPower(power) {}

    void updateCoefficient(double newCoefficient) {mCoefficient = newCoefficient;}
};

class Polynomial
{
    double mPrecision;
    List<Indeterminate>* p_mPrimalForm;
    List<Indeterminate>* p_mFirstDerivative;

    Polynomial();
    ~Polynomial();
    double functionValueAtPoint(List<Indeterminate>* function, double xPoint);
public:
    //! Declaration of non-existing copy constructor
    Polynomial(Polynomial const&) = delete;
    //! Declaration of non-existing operator= overload
    void operator=(Polynomial const&) = delete;

    //! getInstance method provides access to Polynomial singleton object
    static Polynomial& getInstance();

    //! Clears both lists with polynomial and derivative
    void clearData();

    /*!
     * \brief Calculates derivative of loaded polynomial
     * \return False when polynomial not loaded, true after successful calculations
     */
    bool calculateDerivative();

    /*!
     * \brief Solves loaded polynomial using provided hint.
     * \param [in] hint Floating-point value to start searching with for polynomial solution (defaults to 0.0).
     * \return Floating-point value approximation of solution which lies closer than mPrecision to real solution.
     */
    double findSingleSolutionPoint(double hint = 0.0);

    /*!
     * \brief Divide polynomial using Horner's method and given point x.
     * \param [in] xValue Point value used for dividing by (x - xValue)
     * \return Value of calculated remainder from division.
     */
    double divideUsingHornersMethod(double xValue);

    /*!
    * \brief Setter for solution prevision value.
    * \param [in] precision New value of precision to set.
    */
    void setPrecision(double precision) {mPrecision = precision;}
    //! Getter for solution precision value
    double getPrecision() {return mPrecision;}
    //! Getter for polynomial primal form pointer
    List<Indeterminate>* getPrimalFormPointer() {return p_mPrimalForm;}
    //! Getter for polynomial first derivative pointer
    List<Indeterminate>* getFirstDerivativePointer();
};

#endif // POLYNOMIAL_H
