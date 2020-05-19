/********************************************************************************
** Form generated from reading UI file 'EmployerWelcome.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYERWELCOME_H
#define UI_EMPLOYERWELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployerWelcome
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *EmployerWelcome)
    {
        if (EmployerWelcome->objectName().isEmpty())
            EmployerWelcome->setObjectName(QString::fromUtf8("EmployerWelcome"));
        EmployerWelcome->resize(400, 300);
        pushButton = new QPushButton(EmployerWelcome);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 110, 93, 28));

        retranslateUi(EmployerWelcome);

        QMetaObject::connectSlotsByName(EmployerWelcome);
    } // setupUi

    void retranslateUi(QWidget *EmployerWelcome)
    {
        EmployerWelcome->setWindowTitle(QCoreApplication::translate("EmployerWelcome", "EmployerWelcome", nullptr));
        pushButton->setText(QCoreApplication::translate("EmployerWelcome", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployerWelcome: public Ui_EmployerWelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYERWELCOME_H
