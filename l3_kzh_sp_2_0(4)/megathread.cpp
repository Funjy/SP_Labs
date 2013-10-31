#include "megathread.h"

MegaThread::MegaThread(WorkType workType, FileCreateParams *fileParams, QTextEdit *textEdit)
{
    _workType = workType;
    _textEdit = textEdit;
    _fileParams = fileParams;
}

void MegaThread::run()
{

}
