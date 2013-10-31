#ifndef CREATEFILEDIALOG_H
#define CREATEFILEDIALOG_H

#include "supportclasses.h"
#include <QDialog>

namespace Ui {
class CreateFileDialog;
}

class CreateFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateFileDialog(FileCreateParams *params, QWidget *parent = 0);
    ~CreateFileDialog();
signals:
    void CreateComplete();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CreateFileDialog *ui;
    FileCreateParams *_params;
};

#endif // CREATEFILEDIALOG_H
