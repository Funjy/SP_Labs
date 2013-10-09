#ifndef SUPPORTCLASSES_H
#define SUPPORTCLASSES_H

#include <QString>
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
    void UpdateFileData(HANDLE fHandle);
    HANDLE FileHandle;
    QString FileName;
    DWORD DesiredAccess;
    DWORD CreateOptions;
    bool IsFileOpenError;
    QString FileOpenError;
    DWORD FileSize;
    bool Accepted;
};

class DirCreateParams
{
public:
    QString DirName;
};


#endif // SUPPORTCLASSES_H
