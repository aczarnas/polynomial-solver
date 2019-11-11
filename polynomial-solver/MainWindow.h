//! MainWindow class
/*!
 *  \brief Starting UI window of polynomial solver
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Polynomial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Polynomial& polynomialInstance = Polynomial::getInstance();
public:
    //! Default constructor generated by QtCreator's Designer
    MainWindow(QWidget *parent = nullptr);
    //! Default destructor generated by QtCreator's Designer
    ~MainWindow();

private slots:
    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_calculateButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
