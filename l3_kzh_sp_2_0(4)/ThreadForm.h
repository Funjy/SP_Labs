#ifndef THREADFORM_H
#define THREADFORM_H

#include <QWidget>
#include <QString>
#include <supportclasses.h>
#include "megathread.h"

namespace Ui {
class ThreadForm;
}

class ThreadForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit ThreadForm(QWidget *parent = 0);
    ThreadForm(FileCreateParams *params, QWidget *parent = 0);
    ~ThreadForm();
    
private slots:
    void on_RunStopButton_clicked();

    void on_ChangePriority_clicked();

    void on_ThreadSelector_currentTextChanged(const QString &arg1);

private:
    Ui::ThreadForm *ui;
    const QString _startString = "Запустить";
    const QString _pauseString = "Приостановить";
    const QString _threadAB = "Поток А-Б";
    const QString _threadBA = "Поток Б-А";
    const QString _mainThread = "mainThread";

    QString *_curThread;
};

#endif // THREADFORM_H
