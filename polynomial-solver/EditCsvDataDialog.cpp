#include "EditCsvDataDialog.h"
#include "ui_EditCsvDataDialog.h"
#include "UiServices.h"

EditCsvDataDialog::EditCsvDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCsvDataDialog)
{
    ui->setupUi(this);
    UiServices::fillTableWithPolynomialData(Polynomial::getInstance(), ui->tableWidget);
}

EditCsvDataDialog::~EditCsvDataDialog()
{
    delete ui;
}

void EditCsvDataDialog::on_buttonBox_accepted()
{
    UiServices::updatePolynomialDataFromUi(Polynomial::getInstance(), ui->tableWidget);
}
