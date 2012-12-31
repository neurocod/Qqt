/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created: Tue 1. Jan 00:17:57 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestMainWindowClass)
    {
        if (TestMainWindowClass->objectName().isEmpty())
            TestMainWindowClass->setObjectName(QString::fromUtf8("TestMainWindowClass"));
        TestMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(TestMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TestMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TestMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestMainWindowClass->setStatusBar(statusBar);

        retranslateUi(TestMainWindowClass);

        QMetaObject::connectSlotsByName(TestMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestMainWindowClass)
    {
        TestMainWindowClass->setWindowTitle(QApplication::translate("TestMainWindowClass", "TestMainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestMainWindowClass: public Ui_TestMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
