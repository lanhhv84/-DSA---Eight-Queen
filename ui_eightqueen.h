/********************************************************************************
** Form generated from reading UI file 'eightqueen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EIGHTQUEEN_H
#define UI_EIGHTQUEEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EightQueen
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EightQueen)
    {
        if (EightQueen->objectName().isEmpty())
            EightQueen->setObjectName(QStringLiteral("EightQueen"));
        EightQueen->resize(701, 398);
        centralWidget = new QWidget(EightQueen);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        EightQueen->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EightQueen);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 701, 21));
        EightQueen->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EightQueen);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EightQueen->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EightQueen);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EightQueen->setStatusBar(statusBar);

        retranslateUi(EightQueen);

        QMetaObject::connectSlotsByName(EightQueen);
    } // setupUi

    void retranslateUi(QMainWindow *EightQueen)
    {
        EightQueen->setWindowTitle(QApplication::translate("EightQueen", "EightQueen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EightQueen: public Ui_EightQueen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EIGHTQUEEN_H
