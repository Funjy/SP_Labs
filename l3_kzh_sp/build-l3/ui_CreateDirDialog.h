/********************************************************************************
** Form generated from reading UI file 'CreateDirDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIRDIALOG_H
#define UI_CREATEDIRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateDirDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *CreateDirDialog)
    {
        if (CreateDirDialog->objectName().isEmpty())
            CreateDirDialog->setObjectName(QStringLiteral("CreateDirDialog"));
        CreateDirDialog->setWindowModality(Qt::NonModal);
        CreateDirDialog->resize(240, 144);
        CreateDirDialog->setModal(false);
        buttonBox = new QDialogButtonBox(CreateDirDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 90, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(CreateDirDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 221, 21));

        retranslateUi(CreateDirDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateDirDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateDirDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateDirDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateDirDialog)
    {
        CreateDirDialog->setWindowTitle(QApplication::translate("CreateDirDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateDirDialog: public Ui_CreateDirDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIRDIALOG_H
