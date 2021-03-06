#include <QMessageBox>

#include "TripleSonicSlash.h"

TripleSonicSlash::TripleSonicSlash()
{
}

QString TripleSonicSlash::GetLastErrorMessage()
{
    DWORD err = GetLastError();
    QString errorMessage = TripleSonicSlash::GetCodeMessage(err);
    return errorMessage;
}

QString TripleSonicSlash::GetCodeMessage(DWORD errCode)
{
    wchar_t* lpMsgBuf;
    FormatMessageW(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            errCode,
            MAKELANGID(LANG_SYSTEM_DEFAULT, SUBLANG_DEFAULT),
            (wchar_t*)&lpMsgBuf,
            0, NULL );
    return QString::fromStdWString(lpMsgBuf);
}

bool TripleSonicSlash::CheckFalseGetError(bool toCheck)
{
    if(!toCheck)
    {
        ShowError();
        return false;
    }
    return true;
}

void TripleSonicSlash::ShowError()
{
    DWORD err = GetLastError();
    QString errorMessage = TripleSonicSlash::GetCodeMessage(err);
    QMessageBox mbox(QMessageBox::Warning, "Ошибка", errorMessage);
    mbox.exec();
}

//--------------MyException---------------


MyException::MyException()
{
    _message = "";
}

MyException::MyException(QString message)
{
    _message = message;
}
QString MyException::what() throw()
{
    return _message;
}

void MyException::SetMessage(QString message) throw()
{
    _message = message;
}

