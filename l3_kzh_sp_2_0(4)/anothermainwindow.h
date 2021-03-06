#ifndef ANOTHERMAINWINDOW_H
#define ANOTHERMAINWINDOW_H

//Qt
#include <QMainWindow>
#include <QListWidgetItem>
//Local
#include "createfiledialog.h"
#include "supportclasses.h"
#include "CreateDirDialog.h"
#include "fileworker.h"
#include "DirWorker.h"
#include "megathread.h"
#include "ThreadWindow.h"

namespace Ui {
class AnotherMainWindow;
}

class AnotherMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AnotherMainWindow(QWidget *parent = 0);
    ~AnotherMainWindow();
    
private slots:
    void on_CreateButton_clicked();
    void on_CreateFileDialog_accepted();

    void on_CloseButton_clicked();

    void on_CreateDir_clicked();
    void on_CreateDir_accepted();
    void on_UpdateFileButton_clicked();

    void on_CurrentDir_changed();

    void on_OpenedFilesList_itemDoubleClicked(QListWidgetItem *item);

    void on_changeDirButton_clicked();

    void on_deleteDirButton_clicked();

    void on_DoTaskButton_clicked();

public slots:

    void on_ThreadWindowClosed(QString arg1);

private:
    //funcs
    void DestroyThis(void* pointer);
    void DoTask();
    //members
    Ui::AnotherMainWindow *ui;
    FileCreateParams *_createFileParams;
    QList<FileCreateParams*> _openedFiles;
    CreateFileDialog* _createFileDialog;
    CreateDirDialog* _createDirDialog;
    DirCreateParams* _createDirP;
    QString _rootDir;
    QString _curDir;
    DirWorker* _dirWorker;
    TaskOptions* _taskOptions;
    QMap<QString, ThreadWindow*> _winThreads;
};

#endif // ANOTHERMAINWINDOW_H
