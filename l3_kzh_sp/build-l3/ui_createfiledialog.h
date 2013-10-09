/********************************************************************************
** Form generated from reading UI file 'createfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEFILEDIALOG_H
#define UI_CREATEFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateFileDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *FileNameLabel;
    QLineEdit *FileNameBox;
    QGroupBox *AccessTypesBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *ReadCheckBox;
    QCheckBox *WriteCheckBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *CreateOpenFileLabel;
    QComboBox *CreateOpenFileBox;

    void setupUi(QDialog *CreateFileDialog)
    {
        if (CreateFileDialog->objectName().isEmpty())
            CreateFileDialog->setObjectName(QStringLiteral("CreateFileDialog"));
        CreateFileDialog->resize(192, 240);
        buttonBox = new QDialogButtonBox(CreateFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        verticalLayoutWidget = new QWidget(CreateFileDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 171, 41));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FileNameLabel = new QLabel(verticalLayoutWidget);
        FileNameLabel->setObjectName(QStringLiteral("FileNameLabel"));
        FileNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(FileNameLabel);

        FileNameBox = new QLineEdit(verticalLayoutWidget);
        FileNameBox->setObjectName(QStringLiteral("FileNameBox"));

        verticalLayout->addWidget(FileNameBox);

        AccessTypesBox = new QGroupBox(CreateFileDialog);
        AccessTypesBox->setObjectName(QStringLiteral("AccessTypesBox"));
        AccessTypesBox->setGeometry(QRect(10, 60, 171, 71));
        verticalLayoutWidget_2 = new QWidget(AccessTypesBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 151, 42));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ReadCheckBox = new QCheckBox(verticalLayoutWidget_2);
        ReadCheckBox->setObjectName(QStringLiteral("ReadCheckBox"));

        verticalLayout_2->addWidget(ReadCheckBox);

        WriteCheckBox = new QCheckBox(verticalLayoutWidget_2);
        WriteCheckBox->setObjectName(QStringLiteral("WriteCheckBox"));

        verticalLayout_2->addWidget(WriteCheckBox);

        verticalLayoutWidget_3 = new QWidget(CreateFileDialog);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 130, 171, 51));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        CreateOpenFileLabel = new QLabel(verticalLayoutWidget_3);
        CreateOpenFileLabel->setObjectName(QStringLiteral("CreateOpenFileLabel"));

        verticalLayout_3->addWidget(CreateOpenFileLabel);

        CreateOpenFileBox = new QComboBox(verticalLayoutWidget_3);
        CreateOpenFileBox->setObjectName(QStringLiteral("CreateOpenFileBox"));

        verticalLayout_3->addWidget(CreateOpenFileBox);


        retranslateUi(CreateFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateFileDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateFileDialog)
    {
        CreateFileDialog->setWindowTitle(QApplication::translate("CreateFileDialog", "Dialog", 0));
        FileNameLabel->setText(QApplication::translate("CreateFileDialog", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", 0));
        AccessTypesBox->setTitle(QApplication::translate("CreateFileDialog", "\320\241\320\277\320\276\321\201\320\276\320\261\321\213 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", 0));
        ReadCheckBox->setText(QApplication::translate("CreateFileDialog", "\320\247\321\202\320\265\320\275\320\270\320\265", 0));
        WriteCheckBox->setText(QApplication::translate("CreateFileDialog", "\320\227\320\260\320\277\320\270\321\201\321\214", 0));
        CreateOpenFileLabel->setText(QApplication::translate("CreateFileDialog", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\276\321\202\320\272\321\200\321\213\321\202\320\270\321\217 \321\204\320\260\320\271\320\273\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateFileDialog: public Ui_CreateFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEFILEDIALOG_H
