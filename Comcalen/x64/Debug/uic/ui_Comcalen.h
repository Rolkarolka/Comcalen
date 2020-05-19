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
    QGroupBox *groupBox;
    QPushButton *login_button;
    QLineEdit *ID_line;
    QLabel *label;
    QPushButton *signin_button;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ComcalenClass)
    {
        if (ComcalenClass->objectName().isEmpty())
            ComcalenClass->setObjectName(QString::fromUtf8("ComcalenClass"));
        ComcalenClass->resize(495, 364);
        centralWidget = new QWidget(ComcalenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(140, 60, 331, 121));
        login_button = new QPushButton(groupBox);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(82, 79, 231, 31));
        ID_line = new QLineEdit(groupBox);
        ID_line->setObjectName(QString::fromUtf8("ID_line"));
        ID_line->setGeometry(QRect(82, 38, 231, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(32, 34, 31, 41));
        signin_button = new QPushButton(centralWidget);
        signin_button->setObjectName(QString::fromUtf8("signin_button"));
        signin_button->setGeometry(QRect(230, 230, 221, 28));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 190, 241, 31));
        ComcalenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ComcalenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ComcalenClass->setStatusBar(statusBar);

        retranslateUi(ComcalenClass);

        QMetaObject::connectSlotsByName(ComcalenClass);
    } // setupUi

    void retranslateUi(QMainWindow *ComcalenClass)
    {
        ComcalenClass->setWindowTitle(QCoreApplication::translate("ComcalenClass", "Comcalen", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ComcalenClass", "Sign In", nullptr));
        login_button->setText(QCoreApplication::translate("ComcalenClass", "Sign In", nullptr));
        label->setText(QCoreApplication::translate("ComcalenClass", "ID:", nullptr));
        signin_button->setText(QCoreApplication::translate("ComcalenClass", "Sign Up", nullptr));
        label_2->setText(QCoreApplication::translate("ComcalenClass", "You are new here?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComcalenClass: public Ui_ComcalenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMCALEN_H
