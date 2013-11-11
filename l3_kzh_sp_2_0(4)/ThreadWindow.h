#ifndef THREADWINDOW_H
#define THREADWINDOW_H

#include <QMainWindow>
#include "supportclasses.h"
#include "megathread.h"
#include <QCloseEvent>

namespace Ui {
class ThreadWindow;
}

class ThreadWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ThreadWindow(QWidget *parent = 0);
    ThreadWindow(FileCreateParams *params, QWidget *parent = 0);
    ~ThreadWindow();
    void closeEvent(QCloseEvent *event);

signals:

    void WindowClosed();

private slots:
    void on_RunStopButton_clicked();

    void on_ChangePriority_clicked();

    void on_ThreadSelector_currentTextChanged(const QString &arg1);

    void on_SetNiceText(QString text);

private:
    Ui::ThreadWindow *ui;
    QString _startString = "Запустить";
    QString _pauseString = "Приостановить";
    QString _threadAB = "Поток А-Б";
    QString _threadBA = "Поток Б-А";
    QString _mainThread = "mainThread";

    QString _lowPriority = "Низкий";
    QString _mediumPriority = "Средний";
    QString _highPriority = "Высокий";

    QString _fileName;

    QMap<QString, MegaThread*> _threads;
    MegaThread* _curThread;
    LPCRITICAL_SECTION _critSection;
};

#endif // THREADWINDOW_H
