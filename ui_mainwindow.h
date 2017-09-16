/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *numQueenEdit;
    QLabel *numQueenLabel;
    QLineEdit *delayTimeEdit;
    QLabel *delayTimeLabel;
    QPushButton *startButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(341, 250);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        numQueenEdit = new QLineEdit(centralwidget);
        numQueenEdit->setObjectName(QStringLiteral("numQueenEdit"));
        numQueenEdit->setGeometry(QRect(160, 60, 113, 20));
        numQueenLabel = new QLabel(centralwidget);
        numQueenLabel->setObjectName(QStringLiteral("numQueenLabel"));
        numQueenLabel->setGeometry(QRect(30, 60, 81, 16));
        delayTimeEdit = new QLineEdit(centralwidget);
        delayTimeEdit->setObjectName(QStringLiteral("delayTimeEdit"));
        delayTimeEdit->setGeometry(QRect(160, 100, 113, 20));
        delayTimeLabel = new QLabel(centralwidget);
        delayTimeLabel->setObjectName(QStringLiteral("delayTimeLabel"));
        delayTimeLabel->setGeometry(QRect(30, 100, 91, 16));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(130, 150, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 341, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        numQueenLabel->setText(QApplication::translate("MainWindow", "S\341\273\221 qu\303\242n h\341\272\255u", Q_NULLPTR));
        delayTimeLabel->setText(QApplication::translate("MainWindow", "Th\341\273\235i gian tr\341\273\205 (ms)", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "B\341\272\257t \304\221\341\272\247u", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
