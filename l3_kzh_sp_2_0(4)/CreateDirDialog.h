#ifndef CREATEDIRDIALOG_H
#define CREATEDIRDIALOG_H

#include <QDialog>
#include "supportclasses.h"

namespace Ui {
class CreateDirDialog;
}

class CreateDirDialog : public QDialog
{
    Q_OBJECT
    
public:
    void ShowDialog(DirCreateParams *point);
    explicit CreateDirDialog(QString rootDir, QWidget *parent = 0);
    ~CreateDirDialog();
    
private slots:
    void on_buttonBox_accepted();

    signals:
    void MyAccepted();
private:

    QString _rootDir;
    DirCreateParams* _point;
    Ui::CreateDirDialog *ui;
};

#endif // CREATEDIRDIALOG_H
