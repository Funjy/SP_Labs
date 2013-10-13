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
    QGroupBox *CurDirGroup;
    QLineEdit *CurDirBox;
    QPushButton *UpdateFileButton;
    QLabel *label;
    QLineEdit *DurationBox;
    QLabel *label_2;
    QPushButton *changeDirButton;
    QPushButton *deleteDirButton;
    QPushButton *DoTaskButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnotherMainWindow)
    {
        if (AnotherMainWindow->objectName().isEmpty())
            AnotherMainWindow->setObjectName(QStringLiteral("AnotherMainWindow"));
        AnotherMainWindow->resize(598, 344);
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
        CreateDir->setGeometry(QRect(320, 40, 121, 23));
        CurDirGroup = new QGroupBox(centralwidget);
        CurDirGroup->setObjectName(QStringLiteral("CurDirGroup"));
        CurDirGroup->setGeometry(QRect(180, 130, 401, 51));
        CurDirBox = new QLineEdit(CurDirGroup);
        CurDirBox->setObjectName(QStringLiteral("CurDirBox"));
        CurDirBox->setGeometry(QRect(10, 20, 381, 20));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        CurDirBox->setFont(font);
        CurDirBox->setReadOnly(true);
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
        changeDirButton = new QPushButton(centralwidget);
        changeDirButton->setObjectName(QStringLiteral("changeDirButton"));
        changeDirButton->setGeometry(QRect(320, 70, 121, 23));
        deleteDirButton = new QPushButton(centralwidget);
        deleteDirButton->setObjectName(QStringLiteral("deleteDirButton"));
        deleteDirButton->setGeometry(QRect(320, 100, 121, 23));
        DoTaskButton = new QPushButton(centralwidget);
        DoTaskButton->setObjectName(QStringLiteral("DoTaskButton"));
        DoTaskButton->setGeometry(QRect(450, 40, 131, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        DoTaskButton->setFont(font1);
        DoTaskButton->setCursor(QCursor(Qt::PointingHandCursor));
        DoTaskButton->setAutoFillBackground(false);
        AnotherMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnotherMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 598, 21));
        AnotherMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AnotherMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AnotherMainWindow->setStatusBar(statusbar);

        retranslateUi(AnotherMainWindow);

        QMetaObject::connectSlotsByName(AnotherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AnotherMainWindow)
    {
        AnotherMainWindow->setWindowTitle(QApplication::translate("AnotherMainWindow", "Main Window in da house", 0));
        CreateButton->setText(QApplication::translate("AnotherMainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214/\320\276\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        CloseButton->setText(QApplication::translate("AnotherMainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        CreateDir->setText(QApplication::translate("AnotherMainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", 0));
        CurDirGroup->setTitle(QApplication::translate("AnotherMainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217", 0));
        UpdateFileButton->setText(QApplication::translate("AnotherMainWindow", "\320\237\320\265\321\200\320\265\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        label->setText(QApplication::translate("AnotherMainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\271 \n"
"\320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", 0));
        label_2->setText(QApplication::translate("AnotherMainWindow", "\320\274\321\201", 0));
        changeDirButton->setText(QApplication::translate("AnotherMainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", 0));
        deleteDirButton->setText(QApplication::translate("AnotherMainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", 0));
#ifndef QT_NO_TOOLTIP
        DoTaskButton->setToolTip(QApplication::translate("AnotherMainWindow", "<html><head/><body><p>Press Me</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        DoTaskButton->setText(QApplication::translate("AnotherMainWindow", "Dramatic Big \n"
"Button", 0));
    } // retranslateUi

};

namespace Ui {
    class AnotherMainWindow: public Ui_AnotherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHERMAINWINDOW_H
