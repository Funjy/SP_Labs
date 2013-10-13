#include <QQueue>

#include "DirWorker.h"
#include "TripleSonicSlash.h"

DirWorker::DirWorker()
{    
}

QString DirWorker::RootDir = 0;
QString DirWorker::_currentDir = 0;

bool DirWorker::CreateNewDir(QString ndirName, bool setCurrent)
{
    //QString st("D:\\1337");
    std::wstring wst = ndirName.toStdWString();
    LPCWSTR dirName =  wst.c_str();

    if(CreateDirectoryW(dirName, NULL))
    {
        if(setCurrent)
            SetCurrentDir(ndirName);
        return true;
    }
    TripleSonicSlash::ShowError();
    return false;
}

bool DirWorker::DeleteDir(QString dirName)
{
    std::wstring wst = dirName.toStdWString();
    LPCWSTR dir =  wst.c_str();
    if(RemoveDirectoryW(dir))
        return true;
    TripleSonicSlash::ShowError();
    return false;
}

bool DirWorker::SetCurrentDir(QString dirName)
{
    std::wstring wst = dirName.toStdWString();
    LPCWSTR dir =  wst.c_str();
    if(SetCurrentDirectoryW(dir))
    {
        _currentDir = dirName;
        return true;
    }
    TripleSonicSlash::ShowError();
    return false;
}

void DirWorker::FindFiles(QString directory, QString mask, QList<QString> *foundFiles)
{

    //Определяем все вложенные директории
    QQueue<QString> allDirs;
    allDirs.enqueue(directory);
    QQueue<QString> dirs;
    dirs.enqueue(directory);
    LPWIN32_FIND_DATAW attributes = new WIN32_FIND_DATAW();

    HANDLE searchDirHandle;

    while(dirs.length() > 0)
    {
        QString temp = dirs.dequeue();
        temp.append("\\*");
        std::wstring wst = temp.toStdWString();
        LPCWSTR dirName =  wst.c_str();

        searchDirHandle = FindFirstFileW(dirName, attributes);

        if(searchDirHandle == INVALID_HANDLE_VALUE)
        {
            MyException ex(TripleSonicSlash::GetLastErrorMessage());
            throw ex;
        }

        while(1)
        {
            if(attributes->dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
            {
                QString dName(QString::fromStdWString(attributes->cFileName));
                if(dName != "." && dName != "..")
                {
                    QString fullDir = directory + "\\" + dName;
                    dirs.enqueue(fullDir);
                    allDirs.enqueue(fullDir);
                }
            }

            if(!FindNextFileW(searchDirHandle, attributes))
                break;
        }
        if(!FindClose(searchDirHandle))
        {
            MyException ex(TripleSonicSlash::GetLastErrorMessage());
            throw ex;
        }
    }

//-----------------------------------------------------------------------------

    //Поиск файлов

    if(foundFiles == NULL)
        foundFiles = new QList<QString>();

    while(allDirs.length() > 0)
    {
        QString temp = allDirs.dequeue();
        QString fName = temp + QString("\\") + mask;

        std::wstring wst = fName.toStdWString();
        LPCWSTR fileName =  wst.c_str();

        HANDLE searchFileHandle = FindFirstFileW(fileName, attributes);

        if(searchFileHandle == INVALID_HANDLE_VALUE)
        {
            DWORD err = GetLastError();
            if(err == 2)
                continue;
            MyException ex(TripleSonicSlash::GetCodeMessage(err));
            throw ex;
        }

        while(1)
        {
            QString sts(temp + "\\" + QString::fromStdWString(attributes->cFileName));
            //QString* st = &(QString::fromStdWString(attributes->cFileName));
            foundFiles->append(sts);

            if(!FindNextFileW(searchFileHandle, attributes))
                break;
        }

        if(!FindClose(searchFileHandle))
        {
            MyException ex(TripleSonicSlash::GetLastErrorMessage());
            throw ex;
        }
    }
}

QString DirWorker::CurrentDir()
{
    return _currentDir;
}
