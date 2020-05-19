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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComcalenClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *login_button;
    QLineEdit *ID_line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ComcalenClass)
    {
        if (ComcalenClass->objectName().isEmpty())
            ComcalenClass->setObjectName(QString::fromUtf8("ComcalenClass"));
        ComcalenClass->resize(600, 400);
        centralWidget = new QWidget(ComcalenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 60, 261, 201));
        login_button = new QPushButton(groupBox);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(30, 150, 201, 31));
        ID_line = new QLineEdit(groupBox);
        ID_line->setObjectName(QString::fromUtf8("ID_line"));
        ID_line->setGeometry(QRect(30, 120, 191, 21));
        ComcalenClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ComcalenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        ComcalenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ComcalenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ComcalenClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ComcalenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ComcalenClass->setStatusBar(statusBar);

        retranslateUi(ComcalenClass);

        QMetaObject::connectSlotsByName(ComcalenClass);
    } // setupUi

    void retranslateUi(QMainWindow *ComcalenClass)
    {
        ComcalenClass->setWindowTitle(QCoreApplication::translate("ComcalenClass", "Comcalen", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ComcalenClass", "GroupBox", nullptr));
        login_button->setText(QCoreApplication::translate("ComcalenClass", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComcalenClass: public Ui_ComcalenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMCALEN_H
