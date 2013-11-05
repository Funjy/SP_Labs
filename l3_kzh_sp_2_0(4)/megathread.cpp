#include "megathread.h"

MegaThread::MegaThread(WorkType workType, FileCreateParams *fileParams, LPCRITICAL_SECTION section, QTextEdit *textEdit)
{
    _workType = workType;
    _textEdit = textEdit;
    _fileParams = fileParams;
    _critSection = section;
    //_threadStopper = new QMutex();
    _stopped = false;
}

void MegaThread::run()
{
    _threadStopper = new QMutex();
    _stopped = false;
    switch(_workType)
    {
        case MegaThread::AB_Swap:
            while(1)
            {
                EnterCriticalSection(_critSection);
                FileWorker::SwapSymbols(_fileParams, 'a', 'b');
                LeaveCriticalSection(_critSection);
                _threadStopper->lock();
                if(_stopped)
                {
                    _threadStopper->unlock();
                    break;
                }
                _threadStopper->unlock();
            }
            break;
        case MegaThread::BA_Swap:
            while(1)
            {
                EnterCriticalSection(_critSection);
                FileWorker::SwapSymbols(_fileParams, 'b', 'a');
                LeaveCriticalSection(_critSection);
                _threadStopper->lock();
                if(_stopped)
                {
                    _threadStopper->unlock();
                    break;
                }
                _threadStopper->unlock();
            }
            break;
        case MegaThread::NO_Swap:
            while(1)
            {
                Sleep(1000);

                //_textEdit->clear();
                EnterCriticalSection(_critSection);                

                QString s;
                for(int i = 0; i < _fileParams->FileSize; i++)
                {                    
                    s.append(_fileParams->ArrayPointer[i]);
                }                
                //const QString sc = s;
                emit SetNiceText(s);
                LeaveCriticalSection(_critSection);
                //_textEdit->append(s);
                _threadStopper->lock();
                if(_stopped)
                {
                    _threadStopper->unlock();
                    break;
                }
                _threadStopper->unlock();
            }
            break;
    }
    _threadStopper->~QMutex();
    _threadStopper = NULL;
}

void MegaThread::pause()
{
    if(_threadStopper == NULL)
        return;
    _threadStopper->lock();
    _stopped = true;
    _threadStopper->unlock();
}
