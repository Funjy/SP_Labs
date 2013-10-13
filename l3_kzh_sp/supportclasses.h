#ifndef SUPPORTCLASSES_H
#define SUPPORTCLASSES_H
//Qt
#include <QString>
#include <QTime>
//Native
#include "iostream"
#include "windows.h"

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
    QString DirName;
};


#endif // SUPPORTCLASSES_H
