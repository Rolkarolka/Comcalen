/********************************************************************************
** Form generated from reading UI file 'EmployeeCalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEECALENDAR_H
#define UI_EMPLOYEECALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeCalendar
{
public:

    void setupUi(QWidget *EmployeeCalendar)
    {
        if (EmployeeCalendar->objectName().isEmpty())
            EmployeeCalendar->setObjectName(QString::fromUtf8("EmployeeCalendar"));
        EmployeeCalendar->resize(400, 300);

        retranslateUi(EmployeeCalendar);

        QMetaObject::connectSlotsByName(EmployeeCalendar);
    } // setupUi

    void retranslateUi(QWidget *EmployeeCalendar)
    {
        EmployeeCalendar->setWindowTitle(QCoreApplication::translate("EmployeeCalendar", "EmployeeCalendar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeCalendar: public Ui_EmployeeCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEECALENDAR_H
