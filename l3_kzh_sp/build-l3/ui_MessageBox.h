/********************************************************************************
** Form generated from reading UI file 'MessageBox.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBOX_H
#define UI_MESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MessageBox
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *InfoBox;

    void setupUi(QDialog *MessageBox)
    {
        if (MessageBox->objectName().isEmpty())
            MessageBox->setObjectName(QStringLiteral("MessageBox"));
        MessageBox->resize(334, 157);
        buttonBox = new QDialogButtonBox(MessageBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(240, 120, 81, 31));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        InfoBox = new QTextEdit(MessageBox);
        InfoBox->setObjectName(QStringLiteral("InfoBox"));
        InfoBox->setGeometry(QRect(10, 10, 211, 131));
        InfoBox->setReadOnly(true);

        retranslateUi(MessageBox);
        QObject::connect(buttonBox, SIGNAL(accepted()), MessageBox, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MessageBox, SLOT(reject()));

        QMetaObject::connectSlotsByName(MessageBox);
    } // setupUi

    void retranslateUi(QDialog *MessageBox)
    {
        MessageBox->setWindowTitle(QApplication::translate("MessageBox", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class MessageBox: public Ui_MessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBOX_H
