/********************************************************************************
** Form generated from reading UI file 'EmployeeWelcome.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEWELCOME_H
#define UI_EMPLOYEEWELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeWelcome
{
public:

    void setupUi(QWidget *EmployeeWelcome)
    {
        if (EmployeeWelcome->objectName().isEmpty())
            EmployeeWelcome->setObjectName(QString::fromUtf8("EmployeeWelcome"));
        EmployeeWelcome->resize(400, 300);

        retranslateUi(EmployeeWelcome);

        QMetaObject::connectSlotsByName(EmployeeWelcome);
    } // setupUi

    void retranslateUi(QWidget *EmployeeWelcome)
    {
        EmployeeWelcome->setWindowTitle(QCoreApplication::translate("EmployeeWelcome", "EmployeeWelcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeWelcome: public Ui_EmployeeWelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWELCOME_H
