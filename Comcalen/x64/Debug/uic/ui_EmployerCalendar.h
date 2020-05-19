/********************************************************************************
** Form generated from reading UI file 'EmployerCalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYERCALENDAR_H
#define UI_EMPLOYERCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployerCalendar
{
public:

    void setupUi(QWidget *EmployerCalendar)
    {
        if (EmployerCalendar->objectName().isEmpty())
            EmployerCalendar->setObjectName(QString::fromUtf8("EmployerCalendar"));
        EmployerCalendar->resize(499, 393);

        retranslateUi(EmployerCalendar);

        QMetaObject::connectSlotsByName(EmployerCalendar);
    } // setupUi

    void retranslateUi(QWidget *EmployerCalendar)
    {
        EmployerCalendar->setWindowTitle(QCoreApplication::translate("EmployerCalendar", "EmployerCalendar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployerCalendar: public Ui_EmployerCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYERCALENDAR_H
