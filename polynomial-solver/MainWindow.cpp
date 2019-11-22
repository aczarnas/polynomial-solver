#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QStandardPaths>
#include "UiServices.h"
#include "LoadCsvDataDialog.h"

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
    updateDisplayedPolynomial();
}

void MainWindow::on_calculateButton_clicked()
{
    bool hintOk = false;
    double hint = ui->hintInputLineEdit->text().toDouble(&hintOk);
    if (hintOk)
    {
        double solution = polynomialInstance.findSingleSolutionPoint(hint);
        ui->foundSolutionsDisplayTextEdit->append(QString("hint = %1; x = %2").arg(hint).arg(solution));
    }
}

void MainWindow::on_setPrecisionButton_clicked()
{
    polynomialInstance.setPrecision(ui->precisionInputLineEdit->text().toDouble());
    ui->foundSolutionsDisplayTextEdit->setText(QString("precision = %1").arg(polynomialInstance.getPrecision()));
}

void MainWindow::on_editButton_clicked()
{
    LoadCsvDataDialog dialog(this);
    dialog.exec();
    updateDisplayedPolynomial();
}

void MainWindow::updateDisplayedPolynomial()
{
    polynomialInstance.calculateDerivative();
    ui->polynomialDisplayTextEdit->setText(UiServices::parseIndeterminateListToReadableString(polynomialInstance.getPrimalFormPointer()));
    ui->firstDerivativeDisplayTextEdit->setText(UiServices::parseIndeterminateListToReadableString(polynomialInstance.getFirstDerivativePointer()));
    ui->precisionInputLineEdit->setText(QString("%1").arg(polynomialInstance.getPrecision()));
}
