#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QStandardPaths>
#include "UiServices.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->filePathTextBox->setText(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveButton_clicked()
{
    QString temp = UiServices::generateCsvFromPolynomial(Polynomial::getInstance());
    UiServices::writeToFile(ui->filePathTextBox->text(), temp);
}

void MainWindow::on_loadButton_clicked()
{
    QString temp;
    UiServices::readFromFile(ui->filePathTextBox->text(), temp);

    Polynomial& poly = Polynomial::getInstance();
    UiServices::parsePolynomialFromCsv(poly, temp);

    ui->polynomialDisplayTextEdit->setText(UiServices::parseIndeterminateListToReadableString(poly.getPrimalFormPointer()));
    poly.calculateDerivative();
    ui->firstDerivativeDisplayTextEdit->setText(UiServices::parseIndeterminateListToReadableString(poly.getFirstDerivativePointer()));
}

void MainWindow::on_calculateButton_clicked()
{
    Polynomial& poly = Polynomial::getInstance();
    poly.solveStartingFromZero();
}
