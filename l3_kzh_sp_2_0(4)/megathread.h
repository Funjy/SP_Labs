#ifndef MEGATHREAD_H
#define MEGATHREAD_H

#include <supportclasses.h>
#include <fileworker.h>
#include <QThread>
#include <QTextEdit>
#include <QString>


class MegaThread : public QThread
{
    Q_OBJECT
public:
    enum WorkType
    {
        AB_Swap,
        BA_Swap,
        NO_Swap
    };
    MegaThread(WorkType workType, FileCreateParams *fileParams, LPCRITICAL_SECTION section, QTextEdit *textEdit = NULL);
    void run();
    void pause();
signals:
    void SetNiceText(QString str);
private:
    WorkType _workType;
    QTextEdit *_textEdit;
    FileCreateParams *_fileParams;
    LPCRITICAL_SECTION _critSection;
    volatile bool _stopped;
    QMutex *_threadStopper;
};

#endif // MEGATHREAD_H
