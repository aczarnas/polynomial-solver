#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QStandardPaths>
#include "UiServices.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent), ui(new Ui::MainWindow)
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

    UiServices::parsePolynomialFromCsv(polynomialInstance, temp);

    ui->polynomialDisplayTextEdit->setText(UiServices::parseIndeterminateListToReadableString(polynomialInstance.getPrimalFormPointer()));
    polynomialInstance.calculateDerivative();
    ui->firstDerivativeDisplayTextEdit->setText(UiServices::parseIndeterminateListToReadableString(polynomialInstance.getFirstDerivativePointer()));
    ui->foundSolutionsDisplayTextEdit->setText(QString("precision = %1").arg(polynomialInstance.getPrecision()));
}

void MainWindow::on_calculateButton_clicked()
{
    bool hintOk = false;
    double hint = ui->hintInputLineEdit->text().toDouble(&hintOk);
    if (hintOk)
    {
        double solution = polynomialInstance.findSingleSolutionPoint(hint);
        ui->foundSolutionsDisplayTextEdit->append(QString("x = %1").arg(solution));
    }
}

void MainWindow::on_setPrecisionButton_clicked()
{
    polynomialInstance.setPrecision(ui->precisionInputLineEdit->text().toDouble());
    ui->foundSolutionsDisplayTextEdit->setText(QString("precision = %1").arg(polynomialInstance.getPrecision()));
}
