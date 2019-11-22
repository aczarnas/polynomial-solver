#ifndef EDITCSVDATADIALOG_H
#define EDITCSVDATADIALOG_H

#include <QDialog>

namespace Ui {
class EditCsvDataDialog;
}

class EditCsvDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCsvDataDialog(QWidget *parent = nullptr);
    ~EditCsvDataDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditCsvDataDialog *ui;
};

#endif // EDITCSVDATADIALOG_H
