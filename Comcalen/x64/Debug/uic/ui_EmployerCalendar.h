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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployerCalendar
{
public:
    QCalendarWidget *calendar_employer;
    QLabel *day_label;

    void setupUi(QWidget *EmployerCalendar)
    {
        if (EmployerCalendar->objectName().isEmpty())
            EmployerCalendar->setObjectName(QString::fromUtf8("EmployerCalendar"));
        EmployerCalendar->resize(499, 393);
        calendar_employer = new QCalendarWidget(EmployerCalendar);
        calendar_employer->setObjectName(QString::fromUtf8("calendar_employer"));
        calendar_employer->setGeometry(QRect(10, 10, 341, 371));
        calendar_employer->setGridVisible(true);
        calendar_employer->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendar_employer->setNavigationBarVisible(true);
        day_label = new QLabel(EmployerCalendar);
        day_label->setObjectName(QString::fromUtf8("day_label"));
        day_label->setGeometry(QRect(380, 43, 91, 281));
        QFont font;
        font.setFamily(QString::fromUtf8("Old English Text MT"));
        font.setPointSize(13);
        day_label->setFont(font);
        day_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        retranslateUi(EmployerCalendar);
        QObject::connect(calendar_employer, SIGNAL(clicked(QDate)), EmployerCalendar, SLOT(show_label()));

        QMetaObject::connectSlotsByName(EmployerCalendar);
    } // setupUi

    void retranslateUi(QWidget *EmployerCalendar)
    {
        EmployerCalendar->setWindowTitle(QCoreApplication::translate("EmployerCalendar", "EmployerCalendar", nullptr));
        day_label->setText(QCoreApplication::translate("EmployerCalendar", "Choose day", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployerCalendar: public Ui_EmployerCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYERCALENDAR_H
