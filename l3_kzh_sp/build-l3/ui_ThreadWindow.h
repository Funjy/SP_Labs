/********************************************************************************
** Form generated from reading UI file 'ThreadWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADWINDOW_H
#define UI_THREADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreadWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *NiceEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *RunStopButton;
    QPushButton *ChangePriority;
    QComboBox *PrioritySelector;
    QComboBox *ThreadSelector;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ThreadWindow)
    {
        if (ThreadWindow->objectName().isEmpty())
            ThreadWindow->setObjectName(QStringLiteral("ThreadWindow"));
        ThreadWindow->resize(513, 410);
        ThreadWindow->setTabShape(QTabWidget::Triangular);
        ThreadWindow->setDockNestingEnabled(true);
        ThreadWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(ThreadWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        NiceEdit = new QTextEdit(centralwidget);
        NiceEdit->setObjectName(QStringLiteral("NiceEdit"));
        NiceEdit->setGeometry(QRect(10, 10, 491, 251));
        NiceEdit->setReadOnly(true);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 270, 491, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RunStopButton = new QPushButton(horizontalLayoutWidget);
        RunStopButton->setObjectName(QStringLiteral("RunStopButton"));

        horizontalLayout->addWidget(RunStopButton);

        ChangePriority = new QPushButton(horizontalLayoutWidget);
        ChangePriority->setObjectName(QStringLiteral("ChangePriority"));

        horizontalLayout->addWidget(ChangePriority);

        PrioritySelector = new QComboBox(horizontalLayoutWidget);
        PrioritySelector->setObjectName(QStringLiteral("PrioritySelector"));

        horizontalLayout->addWidget(PrioritySelector);

        ThreadSelector = new QComboBox(horizontalLayoutWidget);
        ThreadSelector->setObjectName(QStringLiteral("ThreadSelector"));

        horizontalLayout->addWidget(ThreadSelector);

        ThreadWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ThreadWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 513, 21));
        ThreadWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ThreadWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ThreadWindow->setStatusBar(statusbar);

        retranslateUi(ThreadWindow);

        QMetaObject::connectSlotsByName(ThreadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ThreadWindow)
    {
        ThreadWindow->setWindowTitle(QApplication::translate("ThreadWindow", "MainWindow", 0));
        RunStopButton->setText(QApplication::translate("ThreadWindow", "PushButton", 0));
        ChangePriority->setText(QApplication::translate("ThreadWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreadWindow: public Ui_ThreadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADWINDOW_H
