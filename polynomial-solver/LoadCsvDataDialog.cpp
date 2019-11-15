#include "LoadCsvDataDialog.h"
#include "ui_LoadCsvDataDialog.h"

LoadCsvDataDialog::LoadCsvDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadCsvDataDialog)
{
    ui->setupUi(this);
}

LoadCsvDataDialog::~LoadCsvDataDialog()
{
    delete ui;
}
