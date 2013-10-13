/********************************************************************************
** Form generated from reading UI file 'anothermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOTHERMAINWINDOW_H
#define UI_ANOTHERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnotherMainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *OpenedFilesList;
    QPushButton *CreateButton;
    QPushButton *CloseButton;
    QPushButton *CreateDir;
    QGroupBox *CurDirBox;
    QListWidget *DirContainList;
    QPushButton *UpdateFileButton;
    QLabel *label;
    QLineEdit *DurationBox;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnotherMainWindow)
    {
        if (AnotherMainWindow->objectName().isEmpty())
            AnotherMainWindow->setObjectName(QStringLiteral("AnotherMainWindow"));
        AnotherMainWindow->resize(800, 600);
        centralwidget = new QWidget(AnotherMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        OpenedFilesList = new QListWidget(centralwidget);
        OpenedFilesList->setObjectName(QStringLiteral("OpenedFilesList"));
        OpenedFilesList->setGeometry(QRect(30, 40, 131, 192));
        CreateButton = new QPushButton(centralwidget);
        CreateButton->setObjectName(QStringLiteral("CreateButton"));
        CreateButton->setGeometry(QRect(180, 40, 131, 23));
        CloseButton = new QPushButton(centralwidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(180, 100, 131, 23));
        CreateDir = new QPushButton(centralwidget);
        CreateDir->setObjectName(QStringLiteral("CreateDir"));
        CreateDir->setGeometry(QRect(440, 40, 121, 23));
        CurDirBox = new QGroupBox(centralwidget);
        CurDirBox->setObjectName(QStringLiteral("CurDirBox"));
        CurDirBox->setGeometry(QRect(570, 40, 211, 201));
        DirContainList = new QListWidget(CurDirBox);
        DirContainList->setObjectName(QStringLiteral("DirContainList"));
        DirContainList->setGeometry(QRect(10, 20, 191, 171));
        UpdateFileButton = new QPushButton(centralwidget);
        UpdateFileButton->setObjectName(QStringLiteral("UpdateFileButton"));
        UpdateFileButton->setGeometry(QRect(180, 70, 131, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 240, 141, 31));
        label->setAlignment(Qt::AlignCenter);
        DurationBox = new QLineEdit(centralwidget);
        DurationBox->setObjectName(QStringLiteral("DurationBox"));
        DurationBox->setGeometry(QRect(30, 280, 41, 20));
        DurationBox->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 280, 46, 13));
        AnotherMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnotherMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AnotherMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AnotherMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AnotherMainWindow->setStatusBar(statusbar);

        retranslateUi(AnotherMainWindow);

        QMetaObject::connectSlotsByName(AnotherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AnotherMainWindow)
    {
        AnotherMainWindow->setWindowTitle(QApplication::translate("AnotherMainWindow", "MainWindow", 0));
        CreateButton->setText(QApplication::translate("AnotherMainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214/\320\276\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        CloseButton->setText(QApplication::translate("AnotherMainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        CreateDir->setText(QApplication::translate("AnotherMainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", 0));
        CurDirBox->setTitle(QApplication::translate("AnotherMainWindow", "GroupBox", 0));
        UpdateFileButton->setText(QApplication::translate("AnotherMainWindow", "\320\237\320\265\321\200\320\265\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        label->setText(QApplication::translate("AnotherMainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\271 \n"
"\320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", 0));
        label_2->setText(QApplication::translate("AnotherMainWindow", "\320\274\321\201", 0));
    } // retranslateUi

};

namespace Ui {
    class AnotherMainWindow: public Ui_AnotherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHERMAINWINDOW_H
