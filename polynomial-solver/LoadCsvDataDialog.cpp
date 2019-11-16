#include "LoadCsvDataDialog.h"
#include "ui_LoadCsvDataDialog.h"
#include "UiServices.h"

LoadCsvDataDialog::LoadCsvDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadCsvDataDialog)
{
    ui->setupUi(this);
    UiServices::fillTableWithPolynomialData(Polynomial::getInstance(), ui->tableWidget);
}

LoadCsvDataDialog::~LoadCsvDataDialog()
{
    delete ui;
}
