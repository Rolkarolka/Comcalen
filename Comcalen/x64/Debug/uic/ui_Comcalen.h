/********************************************************************************
** Form generated from reading UI file 'Comcalen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMCALEN_H
#define UI_COMCALEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComcalenClass
{
public:
    QWidget *centralWidget;
    QGroupBox *sibox;
    QPushButton *login_button;
    QLineEdit *ID_line;
    QLabel *label;
    QPushButton *signin_button;
    QLabel *label_2;
    QFrame *employee_menu;
    QPushButton *employee_new_shift_button;
    QPushButton *employee_calendar_button;
    QFrame *employer_menu;
    QPushButton *employer_news_button;
    QPushButton *employer_calendar_button;
    QPushButton *manage_database;
    QPushButton *manage_shifts;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ComcalenClass)
    {
        if (ComcalenClass->objectName().isEmpty())
            ComcalenClass->setObjectName(QString::fromUtf8("ComcalenClass"));
        ComcalenClass->resize(515, 385);
        centralWidget = new QWidget(ComcalenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sibox = new QGroupBox(centralWidget);
        sibox->setObjectName(QString::fromUtf8("sibox"));
        sibox->setGeometry(QRect(140, 60, 341, 231));
        login_button = new QPushButton(sibox);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(82, 79, 231, 31));
        ID_line = new QLineEdit(sibox);
        ID_line->setObjectName(QString::fromUtf8("ID_line"));
        ID_line->setGeometry(QRect(82, 38, 231, 31));
        label = new QLabel(sibox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(32, 34, 31, 41));
        signin_button = new QPushButton(sibox);
        signin_button->setObjectName(QString::fromUtf8("signin_button"));
        signin_button->setGeometry(QRect(80, 180, 231, 28));
        label_2 = new QLabel(sibox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 241, 31));
        employee_menu = new QFrame(centralWidget);
        employee_menu->setObjectName(QString::fromUtf8("employee_menu"));
        employee_menu->setGeometry(QRect(90, 40, 341, 271));
        employee_menu->setAcceptDrops(false);
        employee_menu->setFrameShape(QFrame::StyledPanel);
        employee_menu->setFrameShadow(QFrame::Raised);
        employee_new_shift_button = new QPushButton(employee_menu);
        employee_new_shift_button->setObjectName(QString::fromUtf8("employee_new_shift_button"));
        employee_new_shift_button->setGeometry(QRect(40, 180, 261, 61));
        employee_calendar_button = new QPushButton(employee_menu);
        employee_calendar_button->setObjectName(QString::fromUtf8("employee_calendar_button"));
        employee_calendar_button->setGeometry(QRect(40, 60, 261, 81));
        employer_menu = new QFrame(centralWidget);
        employer_menu->setObjectName(QString::fromUtf8("employer_menu"));
        employer_menu->setGeometry(QRect(10, -10, 481, 381));
        employer_menu->setAcceptDrops(false);
        employer_menu->setFrameShape(QFrame::StyledPanel);
        employer_menu->setFrameShadow(QFrame::Raised);
        employer_news_button = new QPushButton(employer_menu);
        employer_news_button->setObjectName(QString::fromUtf8("employer_news_button"));
        employer_news_button->setGeometry(QRect(80, 190, 321, 61));
        employer_calendar_button = new QPushButton(employer_menu);
        employer_calendar_button->setObjectName(QString::fromUtf8("employer_calendar_button"));
        employer_calendar_button->setGeometry(QRect(80, 70, 321, 81));
        manage_database = new QPushButton(employer_menu);
        manage_database->setObjectName(QString::fromUtf8("manage_database"));
        manage_database->setGeometry(QRect(80, 280, 151, 41));
        QFont font;
        font.setPointSize(8);
        manage_database->setFont(font);
        manage_shifts = new QPushButton(employer_menu);
        manage_shifts->setObjectName(QString::fromUtf8("manage_shifts"));
        manage_shifts->setGeometry(QRect(240, 280, 161, 41));
        ComcalenClass->setCentralWidget(centralWidget);
        employee_menu->raise();
        sibox->raise();
        employer_menu->raise();
        statusBar = new QStatusBar(ComcalenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ComcalenClass->setStatusBar(statusBar);

        retranslateUi(ComcalenClass);

        QMetaObject::connectSlotsByName(ComcalenClass);
    } // setupUi

    void retranslateUi(QMainWindow *ComcalenClass)
    {
        ComcalenClass->setWindowTitle(QCoreApplication::translate("ComcalenClass", "Comcalen", nullptr));
        sibox->setTitle(QCoreApplication::translate("ComcalenClass", "Sign In", nullptr));
        login_button->setText(QCoreApplication::translate("ComcalenClass", "Sign In", nullptr));
        label->setText(QCoreApplication::translate("ComcalenClass", "ID:", nullptr));
        signin_button->setText(QCoreApplication::translate("ComcalenClass", "Sign Up", nullptr));
        label_2->setText(QCoreApplication::translate("ComcalenClass", "You are new here?", nullptr));
        employee_new_shift_button->setText(QCoreApplication::translate("ComcalenClass", "Take shift", nullptr));
        employee_calendar_button->setText(QCoreApplication::translate("ComcalenClass", "My calendar", nullptr));
        employer_news_button->setText(QCoreApplication::translate("ComcalenClass", "News", nullptr));
        employer_calendar_button->setText(QCoreApplication::translate("ComcalenClass", "My calendar", nullptr));
        manage_database->setText(QCoreApplication::translate("ComcalenClass", "Manage database", nullptr));
        manage_shifts->setText(QCoreApplication::translate("ComcalenClass", "Manage shifts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComcalenClass: public Ui_ComcalenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMCALEN_H
