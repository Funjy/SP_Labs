#include "ThreadWindow.h"
#include "ui_ThreadWindow.h"

ThreadWindow::ThreadWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThreadWindow)
{
    ui->setupUi(this);

    _critSection = new CRITICAL_SECTION();
    //_curThread = new QString();
}

ThreadWindow::ThreadWindow(FileCreateParams *params, QWidget *parent) : ThreadWindow(parent)
{
    //LPCRITICAL_SECTION sec;

    _fileName = params->FileName;

    InitializeCriticalSection(_critSection);

    MegaThread *mtAB = new MegaThread(MegaThread::AB_Swap, params, _critSection);
    MegaThread *mtBA = new MegaThread(MegaThread::BA_Swap, params, _critSection);
    MegaThread *mtShow = new MegaThread(MegaThread::NO_Swap, params, _critSection, ui->NiceEdit);

    connect(mtShow, SIGNAL(SetNiceText(QString)), this, SLOT(on_SetNiceText(QString)));

    _threads.insert(_threadAB, mtAB);
    _threads.insert(_threadBA, mtBA);
    _threads.insert(_mainThread, mtShow);

    ui->ThreadSelector->addItem(_threadAB);
    ui->ThreadSelector->addItem(_threadBA);

    ui->PrioritySelector->addItem(_lowPriority);
    ui->PrioritySelector->addItem(_mediumPriority);
    ui->PrioritySelector->addItem(_highPriority);

    ui->RunStopButton->setText(_pauseString);

    _curThread = mtAB;

    mtAB->start();
    mtBA->start();
    mtShow->start();
}

ThreadWindow::~ThreadWindow()
{
    delete ui;    
    MegaThread *it;
    foreach (it, _threads) {
        it->pause();
        it->wait();
        delete it;
    }
    DeleteCriticalSection(_critSection);
}

void ThreadWindow::closeEvent(QCloseEvent *event)
{
    emit WindowClosed();
    event->accept();
}

void ThreadWindow::on_RunStopButton_clicked()
{
    if(_curThread->isRunning())
    {
        _curThread->pause();
        _curThread->wait();
        ui->RunStopButton->setText(_startString);
    } else
    {
        _curThread->start();
        ui->RunStopButton->setText(_pauseString);
    }
}

void ThreadWindow::on_ChangePriority_clicked()
{
    QString curPriority = ui->PrioritySelector->currentText();
    if(curPriority == _lowPriority)
    {
        _curThread->setPriority(QThread::LowestPriority);
    } else if(curPriority == _mediumPriority)
    {
        _curThread->setPriority(QThread::LowPriority);
    } else if(curPriority == _highPriority)
    {
        _curThread->setPriority(QThread::NormalPriority);
    }
}

void ThreadWindow::on_ThreadSelector_currentTextChanged(const QString &arg1)
{
    MegaThread *mt = (_threads.find(arg1).value());
    _curThread = mt;
    if(mt->isRunning())
    {
        ui->RunStopButton->setText(_pauseString);
    }
    else
    {
        ui->RunStopButton->setText(_startString);
    }
}

void ThreadWindow::on_SetNiceText(QString text)
{
    ui->NiceEdit->setText(text);
}
