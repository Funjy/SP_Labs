#include "fileworker.h"


FileWorker::FileWorker()
{
}

void FileWorker::OpenCreateFile(FileCreateParams *params)
{
    std::wstring wst = params->FileName.toStdWString();
    LPCWSTR filePath = wst.c_str();
    //Открытие файла

    HANDLE handle = CreateFileW(filePath, params->DesiredAccess, 0, NULL,
                               params->CreateOptions, FILE_ATTRIBUTE_NORMAL, NULL);
    //Проверка на ошибку
    if(handle == INVALID_HANDLE_VALUE)
    {
        params->IsFileOpenError = true;
        DWORD err = GetLastError();
        QString errorMessage = TripleSonicSlash::GetCodeMessage(err);
        params->FileOpenError = errorMessage;
        //emit CreateComplete();
        return;
    }
    params->FileSize = GetFileSize(handle, NULL);
    params->IsFileOpenError = false;
    params->FileHandle = handle;
    params->Accepted = true;
}

void FileWorker::UpdateFile(FileCreateParams* file)
{
    std::string startSt = "<html><body>";
    std::string endSt = "</body></html>";
    QString nFileName = file->FileName + "_tmp";
    //WCHAR* chars;
    std::wstring wst = nFileName.toStdWString();
    LPCWSTR filePath = wst.c_str();
    HANDLE nFileHandle = CreateFileW(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if(nFileHandle == INVALID_HANDLE_VALUE)
    {
        TripleSonicSlash::ShowError();
        return;
    }
    DWORD bytesReadOnPeriod = 0;
    DWORD bytesWriteOnPeriod = 0;
    //DWORD bytesRead = 0;
    //DWORD position = 0;
    char buf;
    DWORD sizec = startSt.length();
    if(!WriteFile(nFileHandle, startSt.c_str(), sizec, &bytesWriteOnPeriod, NULL))
    {
        TripleSonicSlash::ShowError();
        return;
    }
    if(bytesWriteOnPeriod != sizec)
    {
        MyException ex(QString("Не удалось записать информацию в файл."));
        throw ex;
        //QMessageBox::warning(0, "Информация", "Не удалось записать информацию в файл.");
        return;
    }
    while(1)
    {
        /*if(!ReadFile(file->FileHandle, &buf, sizeof(char), &bytesReadOnPeriod, NULL))
        {
            TripleSonicSlash::ShowError();
            return;
        }*/
        if(!TripleSonicSlash::CheckFalseGetError(ReadFile(file->FileHandle,
                                                          &buf, sizeof(char), &bytesReadOnPeriod, NULL)))
            return;

        if(bytesReadOnPeriod == 0)
        {
            break;
        }

        //Выполнение задания

        if(buf == ' ')
        {
            continue;
        }

        if(!WriteFile(nFileHandle, &buf, sizeof(char), &bytesWriteOnPeriod, NULL))
        {
            TripleSonicSlash::ShowError();
            return;
        }
        if(bytesWriteOnPeriod == 0)
        {
            MyException ex(QString("Не удалось записать информацию в файл."));
            throw ex;
            //QMessageBox::warning(0, "Информация", "Не удалось записать информацию в файл.");
            break;
        }

    }

    sizec = endSt.length();
    if(!WriteFile(nFileHandle, endSt.c_str(), sizec, &bytesWriteOnPeriod, NULL))
    {
        TripleSonicSlash::ShowError();
        return;
    }

    if(!FlushFileBuffers(nFileHandle))
    {
        TripleSonicSlash::ShowError();
        return;
    }

    if(!CloseHandle(nFileHandle))
    {
        TripleSonicSlash::ShowError();
        return;
    }

    if(!CloseHandle(file->FileHandle))
    {
        TripleSonicSlash::ShowError();
        return;
    }

    if(!ReplaceFileW(file->FileName.toStdWString().c_str(), filePath,
                     NULL, REPLACEFILE_WRITE_THROUGH, NULL, NULL))
    {
        TripleSonicSlash::ShowError();
        HANDLE handle = CreateFileW(file->FileName.toStdWString().c_str(), file->DesiredAccess, 0, NULL,
                                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        file->FileHandle = handle;
        return;
    }

    HANDLE handle = CreateFileW(file->FileName.toStdWString().c_str(), file->DesiredAccess, 0, NULL,
                               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if(handle == INVALID_HANDLE_VALUE)
    {
        MyException ex(QString("Не удалось снова открыть файл "  + file->FileName + "."));
        throw ex;
    }
    file->FileHandle = handle;

}

//bool FileWorker::CreateFile(QString fileName)
//{
//    LPCTSTR fname;
//    fname = fileName.toStdString();
//    return true;
//    //CreateFile()
//}
