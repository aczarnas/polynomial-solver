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
    UiServices::writeToFile(ui->filePathTextBox->text(), ui->polynomialDisplayTextEdit->toPlainText());
}

void MainWindow::on_loadButton_clicked()
{
    QString temp;
    UiServices::readFromFile(ui->filePathTextBox->text(), temp);
    ui->polynomialDisplayTextEdit->setText(temp);
}
