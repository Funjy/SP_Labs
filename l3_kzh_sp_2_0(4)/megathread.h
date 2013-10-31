#ifndef MEGATHREAD_H
#define MEGATHREAD_H

#include <supportclasses.h>
#include <QThread>
#include <QTextEdit>

class MegaThread : public QThread
{
public:
    MegaThread(WorkType workType, FileCreateParams *fileParams, QTextEdit *textEdit = NULL);
    void run();
    enum WorkType
    {
        AB_Swap,
        BA_Swap,
        NO_Swap
    };
private:
    WorkType _workType;
    QTextEdit *_textEdit;
    FileCreateParams *_fileParams;
};

#endif // MEGATHREAD_H
