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
    //_rootDir = QDir::currentPath();

    DirWorker::RootDir = QDir::currentPath();
    _curDir = DirWorker::RootDir;
    ui->CurDirBox->setTitle(_curDir);
    _createDirDialog = new CreateDirDialog(DirWorker::RootDir);
    connect(_createDirDialog, SIGNAL(MyAccepted()), this, SLOT(on_CreateDir_accepted()));
    _dirWorker = new DirWorker();

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
    ui->DurationBox->setText(QString::number(_createFileParams->LastOperationDuration));
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

    //_dirWorker->CreateNewDir(QString(""));

}

void AnotherMainWindow::on_CreateDir_accepted()
{

    _dirWorker->CreateNewDir(_createDirP->DirName);

    //_createDirP->toWCharArray(chars);
    /*QString d;
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
    }*/
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

    try
    {
        FileWorker::UpdateFile(file);
        QMessageBox::information(0, "Информаиця", "Операция изменения файла завершена.");
    }
    catch(MyException& ex)
    {
        QMessageBox::warning(0, "Внимание", ex.what());
    }
}
