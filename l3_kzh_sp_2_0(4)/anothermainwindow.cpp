#include "anothermainwindow.h"
#include "ui_anothermainwindow.h"
#include <QMessageBox>
#include "supportclasses.h"
#include "TripleSonicSlash.h"
#include <QDir>
#include <QDesktopServices>

AnotherMainWindow::AnotherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnotherMainWindow)
{
    ui->setupUi(this);

    DirWorker::RootDir = QDir::currentPath();
    _curDir = DirWorker::RootDir;
    ui->CurDirBox->setText(_curDir);
    _createDirDialog = new CreateDirDialog(DirWorker::RootDir);
    connect(_createDirDialog, SIGNAL(MyAccepted()), this, SLOT(on_CreateDir_accepted()));    

    _taskOptions = new TaskOptions();
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
        QMessageBox mbox(QMessageBox::Warning, "Error", _createFileParams->FileOpenError + ".");
        mbox.exec();
        return;
    }
    ui->DurationBox->setText(QString::number(_createFileParams->LastOperationDuration));
    _openedFiles.append(_createFileParams);
    QMessageBox::information(0, "Информация", "Операция создания/открытия файла успешно завершена.");
    ui->OpenedFilesList->addItem(_createFileParams->FileName);
}

void AnotherMainWindow::DestroyThis(void *pointer)
{
    if(pointer == 0)
        return;
    delete pointer;
    pointer = 0;
}

void AnotherMainWindow::DoTask()
{
    int t1s = QTime::currentTime().msec() + QTime::currentTime().second()*1000;
    QList<QString>* fList = new QList<QString>();
    try
    {
        DirWorker::FindFiles(_taskOptions->FromDir, "*.txt", fList);
    }
    catch(MyException& ex)
    {
        QMessageBox::critical(0, "Внимание", ex.what());
        return;
    }

    int len = fList->length();

    for(int i = 0; i < len; i++)
    {
        QString fName = fList->at(i);
        std::wstring sst = fName.toStdWString();
        LPCWSTR sourseFile =  sst.c_str();
        QString newFileQ(_taskOptions->ToDir + "\\" + QString::number(1) + '_' + QString::number(i) + ".html");
        std::wstring nst = newFileQ.toStdWString();
        LPCWSTR newFile = nst.c_str();
        if(!CopyFileW(sourseFile, newFile, false))
        {
            QMessageBox::critical(0, "Ошибка", "Не удалось скопировать файл: " + fName);
            return;
        }
        FileCreateParams* params = new FileCreateParams();
        params->CreateOptions = OPEN_EXISTING;
        params->DesiredAccess = GENERIC_READ;
        params->DesiredAccess += GENERIC_WRITE;
        params->FileName = newFileQ;
        FileWorker::OpenCreateFile(params);
        FileWorker::UpdateFile(params);
        FileWorker::CloseOpenedFile(params);
        delete params;
    }
    int t2s = QTime::currentTime().msec() + QTime::currentTime().second()*1000;
    ui->DurationBox->setText(QString::number(t2s - t1s));
}

void AnotherMainWindow::on_CloseButton_clicked()
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
            try
            {
                FileWorker::CloseOpenedFile(file);
                _openedFiles.removeOne(file);
                ui->OpenedFilesList->takeItem(ui->OpenedFilesList->row(ui->OpenedFilesList->currentItem()));
                QMessageBox::information(0, "Информация", "Операция закрытия файла успешно завершена.");

            }
            catch(MyException &ex)
            {
                QMessageBox::critical(0, "Ошибка", ex.what());
                return;
            }
            break;
        }
    }
}


//Создать папку
void AnotherMainWindow::on_CreateDir_clicked()
{
    _createDirP = new DirCreateParams();
    _createDirP->DialogTitle = "Имя директории для создания";
    _createDirP->OperationType = DirWorker::Create;
    _createDirDialog->ShowDialog( _createDirP);
}

void AnotherMainWindow::on_CreateDir_accepted()
{
    switch(_createDirP->OperationType)
    {
    case DirWorker::Create:
        _dirWorker->CreateNewDir(_createDirP->DirName);
        break;
    case DirWorker::SetCurrent:
        _dirWorker->SetCurrentDir(_createDirP->DirName);
        on_CurrentDir_changed();
        break;
    case DirWorker::Delete:
        _dirWorker->DeleteDir(_createDirP->DirName);
        break;
    case DirWorker::FromDir:
        _taskOptions->FromDir = _createDirP->DirName;
        _taskOptions->FromDirSet = true;
        _createDirP = new DirCreateParams();
        _createDirP->DialogTitle = "Куда копировать";
        _createDirP->OperationType = DirWorker::ToDir;
        _createDirDialog->ShowDialog( _createDirP);
        break;
    case DirWorker::ToDir:
        _taskOptions->ToDir = _createDirP->DirName;
        if(_taskOptions->FromDirSet)
            DoTask();
        break;
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

void AnotherMainWindow::on_CurrentDir_changed()
{
    ui->CurDirBox->setText(DirWorker::CurrentDir());
}

void AnotherMainWindow::on_OpenedFilesList_itemDoubleClicked(QListWidgetItem *item)
{
    bool closed = false;
    FileCreateParams* file;
    foreach (file, _openedFiles) {
        if(file->FileName == item->text())
        {
            closed = CloseHandle(file->FileHandle);
            break;
        }
    }
    if(closed)
    {
        _openedFiles.removeOne(file);
        ui->OpenedFilesList->takeItem(ui->OpenedFilesList->row(ui->OpenedFilesList->currentItem()));
    }
    else
    {
        TripleSonicSlash::ShowError();
        return;
    }
    QDesktopServices::openUrl(QUrl(item->text()));
}

void AnotherMainWindow::on_changeDirButton_clicked()
{
    _createDirP = new DirCreateParams();
    _createDirP->DialogTitle = "Имя директории для перехода";
    _createDirP->OperationType = DirWorker::SetCurrent;
    _createDirDialog->ShowDialog( _createDirP);

}

void AnotherMainWindow::on_deleteDirButton_clicked()
{
    _createDirP = new DirCreateParams();
    _createDirP->DialogTitle = "Имя директории для удаления";
    _createDirP->OperationType = DirWorker::Delete;
    _createDirDialog->ShowDialog( _createDirP);
}

void AnotherMainWindow::on_DoTaskButton_clicked()
{
    _createDirP = new DirCreateParams();
    _createDirP->DialogTitle = "Откуда копировать";
    _createDirP->OperationType = DirWorker::FromDir;
    _createDirDialog->ShowDialog( _createDirP);
}

void AnotherMainWindow::on_OpenThreadWindow_clicked()
{

}
