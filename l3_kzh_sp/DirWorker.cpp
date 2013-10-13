#include "DirWorker.h"

DirWorker::DirWorker()
{    
}

QString DirWorker::RootDir = 0;

bool DirWorker::CreateNewDir(QString ndirName)
{
    //QString st("D:\\1337");
    std::wstring wst = ndirName.toStdWString();
    LPCWSTR dirName =  wst.c_str();

    if(CreateDirectoryW(dirName, NULL))
        return true;
    TripleSonicSlash::ShowError();
    return false;
}
