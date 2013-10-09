#include "createfiledialog.h"
#include "ui_createfiledialog.h"
#include "constants.h"
#include "TripleSonicSlash.h"
#include "fileworker.h"

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

    FileWorker::OpenCreateFile(_params);
    emit CreateComplete();
}

void CreateFileDialog::on_buttonBox_rejected()
{
    _params->Accepted = false;
}
