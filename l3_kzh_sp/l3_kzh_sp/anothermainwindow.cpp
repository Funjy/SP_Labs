#include "anothermainwindow.h"
#include "ui_anothermainwindow.h"
#include <QMessageBox>
#include "supportclasses.h"
#include "TripleSonicSlash.h"
#include <QDir>

AnotherMainWindow::AnotherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnotherMainWindow)
{
    ui->setupUi(this);
    _rootDir = QDir::currentPath();
    _curDir = _rootDir;
    ui->CurDirBox->setTitle(_curDir);
    _createDirDialog = new CreateDirDialog(_rootDir);
    connect(_createDirDialog, SIGNAL(MyAccepted()), this, SLOT(on_CreateDir_accepted()));    
}

AnotherMainWindow::~AnotherMainWindow()
{
    delete ui;
}

void AnotherMainWindow::on_CreateButton_clicked()
{
    _createFileParams = 0;
    _createFileParams = new FileCreateParams();
    _createFileDialog = 0;
    DestroyThis(_createFileDialog);
    _createFileDialog = new CreateFileDialog(_createFileParams, this);
    //CreateFileDialog dialog(_createFileParams, this);
    connect(_createFileDialog, SIGNAL(CreateComplete()), this, SLOT(on_CreateFileDialog_accepted()));
    //connect(_createFileDialog, SIGNAL(rejected()), this, SLOT(on_CreateFileDialog_rejected()));
    _createFileDialog->setModal(true);
    _createFileDialog->show();
}

void AnotherMainWindow::on_CreateFileDialog_accepted()
{

    if(_createFileParams->IsFileOpenError)
    {
        //QMessageBox::critical(0, "Ошибка", _createFileParams->FileOpenError + ".");
        QMessageBox mbox(QMessageBox::Warning, "Error", _createFileParams->FileOpenError + ".");
        mbox.exec();
        return;
    }
    _openedFiles.append(_createFileParams);
    QMessageBox::information(0, "Информация", "Операция создания/открытия файла успешно завершена.");
    ui->OpenedFilesList->addItem(_createFileParams->FileName);
    //DestroyThis(_createFileDialog);
}

void AnotherMainWindow::on_CreateFileDialog_rejected()
{

}

void AnotherMainWindow::DestroyThis(void *pointer)
{
    if(pointer == 0)
        return;
    delete pointer;
    pointer = 0;
}

void AnotherMainWindow::on_CloseButton_clicked()
{
    QListWidgetItem* curItem = ui->OpenedFilesList->currentItem();
    if (curItem == 0 ){
        QMessageBox::critical(0, "Ошибка", "Нет выбранных файлов");
        return;
    }
    bool closed = false;
    FileCreateParams* file;
    foreach (file, _openedFiles) {
        if(file->FileName == curItem->text())
        {
            closed = CloseHandle(file->FileHandle);
        }
    }
    if(closed)
    {
        _openedFiles.removeOne(file);
        ui->OpenedFilesList->takeItem(ui->OpenedFilesList->row(ui->OpenedFilesList->currentItem()));
        QMessageBox::information(0, "Информация", "Операция закрытия файла успешно завершена.");
    }
    else
    {
        QMessageBox::critical(0, "Ошибка", "Ошибка");
    }
}

void AnotherMainWindow::on_CreateDir_clicked()
{
    _createDirP = new DirCreateParams();
    _createDirDialog->ShowDialog( _createDirP);
}

void AnotherMainWindow::on_CreateDir_accepted()
{
    //_createDirP->toWCharArray(chars);
    QString d;
    d = _createDirP->DirName;
    std::wstring wst = d.toStdWString();
    LPCWSTR filePath = wst.c_str();
    if(!CreateDirectoryW(filePath, NULL))
    {
        DWORD err = GetLastError();
        QString errorMessage = TripleSonicSlash::GetCodeMessage(err);
        QMessageBox mbox(QMessageBox::Warning, "Ошибка", errorMessage);
        mbox.exec();
    }
    else
    {
        //ui->CurDirBox->setTitle(QDir::currentPath() + QString("\\") + _createDirP);
        ui->CurDirBox->setTitle(QDir::currentPath()+ QString("/") + _createDirP->DirName);
    }

}


//--------------Разделитель 1337---------------------------------

void AnotherMainWindow::on_UpdateFileButton_clicked()
{
    QListWidgetItem* curItem = ui->OpenedFilesList->currentItem();
    if (curItem == 0 ){
        QMessageBox::critical(0, "Ошибка", "Нет выбранных файлов");
        return;
    }
    FileCreateParams* file;
    foreach (file, _openedFiles) {
        if(file->FileName == curItem->text())
        {
            break;
        }
    }
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
    DWORD bytesRead = 0;
    DWORD position = 0;
    char buf;
    int sizec = startSt.length();
    if(!WriteFile(nFileHandle, startSt.c_str(), sizec, &bytesWriteOnPeriod, NULL))
    {
        TripleSonicSlash::ShowError();
        return;
    }
    if(bytesWriteOnPeriod != sizec)
    {
        QMessageBox::warning(0, "Информация", "Не удалось записать информацию в файл.");
        return;
    }
    while(1)
    {
        if(!ReadFile(file->FileHandle, &buf, sizeof(char), &bytesReadOnPeriod, NULL))
        {
            TripleSonicSlash::ShowError();
            return;
        }
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
            QMessageBox::warning(0, "Информация", "Не удалось записать информацию в файл.");
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

    QMessageBox::information(0, "Информаиця", "Операция изменения файла завершена.");

}
