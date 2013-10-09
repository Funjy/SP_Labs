#ifndef ANOTHERMAINWINDOW_H
#define ANOTHERMAINWINDOW_H

#include <QMainWindow>
#include "createfiledialog.h"
#include "supportclasses.h"
#include "CreateDirDialog.h"
#include "fileworker.h"

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
    void on_CreateFileDialog_rejected();

    void on_CloseButton_clicked();

    void on_CreateDir_clicked();
    void on_CreateDir_accepted();
    void on_UpdateFileButton_clicked();

private:
    //funcs
    void DestroyThis(void* pointer);
    //members
    Ui::AnotherMainWindow *ui;
    FileCreateParams *_createFileParams;
    QList<FileCreateParams*> _openedFiles;
    CreateFileDialog* _createFileDialog;
    CreateDirDialog* _createDirDialog;
    DirCreateParams* _createDirP;
    QString _rootDir;
    QString _curDir;
};

#endif // ANOTHERMAINWINDOW_H
