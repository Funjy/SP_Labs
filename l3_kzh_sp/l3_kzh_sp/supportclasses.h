#ifndef SUPPORTCLASSES_H
#define SUPPORTCLASSES_H
//Qt
#include <QString>
#include <QTime>
//Native
#include "iostream"
#include "windows.h"
//Local
#include "DirWorker.h"

class SupportClasses
{
public:
    SupportClasses();
    static QString RootDir;

};

class FileCreateParams
{
public:
    HANDLE FileHandle;
    QString FileName;
    DWORD DesiredAccess;
    DWORD CreateOptions;
    bool IsFileOpenError;
    QString FileOpenError;
    DWORD FileSize;
    int LastOperationDuration;
    bool Accepted;
};

class DirCreateParams
{
public:
    DirCreateParams() {}
    QString DirName;
    QString DialogTitle;
    DirWorker::OperationType OperationType;
};

class TaskOptions
{
public:
    TaskOptions() { FromDirSet = false; }
    QString FromDir;
    QString ToDir;
    bool FromDirSet;
};




#endif // SUPPORTCLASSES_H
