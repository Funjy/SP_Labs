#include "CreateDirDialog.h"
#include "ui_CreateDirDialog.h"
#include "supportclasses.h"

CreateDirDialog::CreateDirDialog(QString rootDir, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDirDialog)
{
    ui->setupUi(this);
    //this->setModal(true);
    _rootDir = rootDir;
    //_point = new QString;
}

CreateDirDialog::~CreateDirDialog()
{
    delete ui;
}

void CreateDirDialog::on_buttonBox_accepted()
{
    //QString* str = new QString(ui->lineEdit->text());
    _point->DirName = ui->lineEdit->text();
    this->setModal(false);
    emit MyAccepted();
}


void CreateDirDialog::ShowDialog(DirCreateParams *point)
{
    this->setModal(true);
    ui->operationLabel->setText(point->DialogTitle);
    ui->lineEdit->setText(_rootDir);
    _point = point;
    this->show();
}
