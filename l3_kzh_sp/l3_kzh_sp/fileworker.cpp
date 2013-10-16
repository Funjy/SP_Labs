#include "fileworker.h"


FileWorker::FileWorker()
{
}

void FileWorker::OpenCreateFile(FileCreateParams *params)
{    
    int t1s = QTime::currentTime().msec();
    if(params == NULL)
    {
        params = new FileCreateParams();
        params->IsFileOpenError = true;
        params->FileOpenError = "Передан пустой параметр.";
        return;
    }
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
    int t2s = QTime::currentTime().msec();
    params->LastOperationDuration = (t2s - t1s);
}

FileCreateParams* FileWorker::OpenCreateFile(QString fileName)
{
    FileCreateParams* params = new FileCreateParams();
    params->FileName = fileName;
    params->DesiredAccess = GENERIC_READ;
    params->DesiredAccess += GENERIC_WRITE;
    params->CreateOptions = OPEN_EXISTING;
    OpenCreateFile(params);
    return params;
}

void FileWorker::CloseOpenedFile(FileCreateParams *params)
{    
    if(params == NULL)
    {
        MyException ex("Передан не инициализированный параметр.");
        throw ex;
    }
    params->LastOperationDuration = 0;
    if(!CloseHandle(params->FileHandle))
    {
        MyException ex(TripleSonicSlash::GetLastErrorMessage());        
        throw ex;
    }
}

void FileWorker::UpdateFile(FileCreateParams* file)
{
    int t1s = QTime::currentTime().msec();
    std::string startSt = "<html><body>";
    std::string endSt = "</body></html>";
    QString nFileName = file->FileName + "_tmp";
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
    int t2s = QTime::currentTime().msec();
    file->LastOperationDuration = t2s - t1s;

}

