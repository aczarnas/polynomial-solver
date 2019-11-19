#ifndef LOADCSVDATADIALOG_H
#define LOADCSVDATADIALOG_H

#include <QDialog>

namespace Ui {
class LoadCsvDataDialog;
}

class LoadCsvDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadCsvDataDialog(QWidget *parent = nullptr);
    ~LoadCsvDataDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoadCsvDataDialog *ui;
};

#endif // LOADCSVDATADIALOG_H
