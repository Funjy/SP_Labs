#include <QMessageBox>

#include "TripleSonicSlash.h"

TripleSonicSlash::TripleSonicSlash()
{
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

void TripleSonicSlash::CheckFalseGetError(bool toCheck)
{
    if(!toCheck)
        ShowError();
}

void TripleSonicSlash::ShowError()
{
    DWORD err = GetLastError();
    QString errorMessage = TripleSonicSlash::GetCodeMessage(err);
    QMessageBox mbox(QMessageBox::Warning, "Ошибка", errorMessage);
    mbox.exec();
}
