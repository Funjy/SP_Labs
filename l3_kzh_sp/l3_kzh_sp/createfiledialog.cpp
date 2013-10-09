#include "createfiledialog.h"
#include "ui_createfiledialog.h"
#include "constants.h"
#include "TripleSonicSlash.h"

CreateFileDialog::CreateFileDialog(FileCreateParams *params, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateFileDialog)
{
    ui->setupUi(this);
    ui->CreateOpenFileBox->addItem(Constants::OPEN_EXISTING_TEXT);
    ui->CreateOpenFileBox->addItem(Constants::CREATE_REWRITE_TEXT);
    ui->CreateOpenFileBox->addItem(Constants::OPEN_CREATE_TEXT);
    _params = params;
}

CreateFileDialog::~CreateFileDialog()
{
    delete ui;
}

void CreateFileDialog::on_buttonBox_accepted()
{
    if(_params == 0)
        _params = new FileCreateParams();
    DWORD desiredAccess = 0;
    if(ui->ReadCheckBox->isChecked())
        desiredAccess += GENERIC_READ;
    if(ui->WriteCheckBox->isChecked())
        desiredAccess += GENERIC_WRITE;
    _params->DesiredAccess  = desiredAccess;
    _params->FileName = QString(ui->FileNameBox->text());
    QString coSelected = ui->CreateOpenFileBox->currentText();
    if(coSelected.compare(Constants::OPEN_EXISTING_TEXT) == 0)
    {
        _params->CreateOptions = OPEN_EXISTING;
    } else if (coSelected.compare(Constants::CREATE_REWRITE_TEXT) == 0)
    {
        _params->CreateOptions = CREATE_ALWAYS;
    } else if (coSelected.compare(Constants::OPEN_CREATE_TEXT) == 0)
    {
        _params->CreateOptions = OPEN_ALWAYS;
    }

    WCHAR* chars;
    std::wstring wst = _params->FileName.toStdWString();
    LPCWSTR filePath = wst.c_str();
    //Открытие файла
    HANDLE handle = CreateFileW(filePath, _params->DesiredAccess, 0, NULL,
                               _params->CreateOptions, FILE_ATTRIBUTE_NORMAL, NULL);
    //Проверка на ошибку
    if(handle == INVALID_HANDLE_VALUE)
    {
        _params->IsFileOpenError = true;
        DWORD err = GetLastError();
        QString errorMessage = TripleSonicSlash::GetCodeMessage(err);
        _params->FileOpenError = errorMessage;
        emit CreateComplete();
        return;
    }
    _params->FileSize = GetFileSize(handle, NULL);
    _params->IsFileOpenError = false;
    _params->FileHandle = handle;
    _params->Accepted = true;
    emit CreateComplete();
}

void CreateFileDialog::on_buttonBox_rejected()
{
    _params->Accepted = false;
}
