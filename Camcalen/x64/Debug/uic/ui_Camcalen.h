/********************************************************************************
** Form generated from reading UI file 'Camcalen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMCALEN_H
#define UI_CAMCALEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamcalenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CamcalenClass)
    {
        if (CamcalenClass->objectName().isEmpty())
            CamcalenClass->setObjectName(QString::fromUtf8("CamcalenClass"));
        CamcalenClass->resize(600, 400);
        menuBar = new QMenuBar(CamcalenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CamcalenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CamcalenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CamcalenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CamcalenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CamcalenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CamcalenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CamcalenClass->setStatusBar(statusBar);

        retranslateUi(CamcalenClass);

        QMetaObject::connectSlotsByName(CamcalenClass);
    } // setupUi

    void retranslateUi(QMainWindow *CamcalenClass)
    {
        CamcalenClass->setWindowTitle(QCoreApplication::translate("CamcalenClass", "Camcalen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CamcalenClass: public Ui_CamcalenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMCALEN_H
