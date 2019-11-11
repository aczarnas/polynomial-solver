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
    ui->foundSolutionsDisplayTextEdit->setText(QString("precision = %1").arg(poly.getPrecision()));
}

void MainWindow::on_calculateButton_clicked()
{
    Polynomial& poly = Polynomial::getInstance();
    bool hintOk = false;
    double hint = ui->hintInputLineEdit->text().toDouble(&hintOk);
    if(hintOk) {
        double solution = poly.findSingleSolutionPoint(hint);
        ui->foundSolutionsDisplayTextEdit->append(QString("x = %1").arg(solution));
    }
}
