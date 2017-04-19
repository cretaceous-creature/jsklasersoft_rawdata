/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInsert_Plot;
    QAction *actionSave_Document;
    QAction *actionSAVE;
    QAction *actionEXIT;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QScrollBar *verticalScrollBar;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *label;
    QScrollBar *horizontalScrollBar_3;
    QScrollBar *horizontalScrollBar_5;
    QLCDNumber *lcdNumber_3;
    QLabel *label_3;
    QScrollBar *horizontalScrollBar_2;
    QLCDNumber *lcdNumber_7;
    QLCDNumber *lcdNumber_5;
    QScrollBar *horizontalScrollBar_4;
    QScrollBar *horizontalScrollBar_6;
    QLCDNumber *lcdNumber_4;
    QScrollBar *horizontalScrollBar_7;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_6;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QScrollBar *horizontalScrollBar;
    QPushButton *pushButton_3;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(790, 607);
        actionInsert_Plot = new QAction(MainWindow);
        actionInsert_Plot->setObjectName(QStringLiteral("actionInsert_Plot"));
        actionSave_Document = new QAction(MainWindow);
        actionSave_Document->setObjectName(QStringLiteral("actionSave_Document"));
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName(QStringLiteral("actionSAVE"));
        actionEXIT = new QAction(MainWindow);
        actionEXIT->setObjectName(QStringLiteral("actionEXIT"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalScrollBar, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 40, 50, 12));
        horizontalScrollBar_3 = new QScrollBar(widget);
        horizontalScrollBar_3->setObjectName(QStringLiteral("horizontalScrollBar_3"));
        horizontalScrollBar_3->setGeometry(QRect(150, 110, 160, 16));
        horizontalScrollBar_3->setOrientation(Qt::Horizontal);
        horizontalScrollBar_5 = new QScrollBar(widget);
        horizontalScrollBar_5->setObjectName(QStringLiteral("horizontalScrollBar_5"));
        horizontalScrollBar_5->setGeometry(QRect(150, 210, 160, 16));
        horizontalScrollBar_5->setOrientation(Qt::Horizontal);
        lcdNumber_3 = new QLCDNumber(widget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(80, 200, 64, 23));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 90, 50, 12));
        horizontalScrollBar_2 = new QScrollBar(widget);
        horizontalScrollBar_2->setObjectName(QStringLiteral("horizontalScrollBar_2"));
        horizontalScrollBar_2->setGeometry(QRect(150, 60, 160, 16));
        horizontalScrollBar_2->setOrientation(Qt::Horizontal);
        lcdNumber_7 = new QLCDNumber(widget);
        lcdNumber_7->setObjectName(QStringLiteral("lcdNumber_7"));
        lcdNumber_7->setGeometry(QRect(80, 350, 64, 23));
        lcdNumber_5 = new QLCDNumber(widget);
        lcdNumber_5->setObjectName(QStringLiteral("lcdNumber_5"));
        lcdNumber_5->setGeometry(QRect(80, 150, 64, 23));
        horizontalScrollBar_4 = new QScrollBar(widget);
        horizontalScrollBar_4->setObjectName(QStringLiteral("horizontalScrollBar_4"));
        horizontalScrollBar_4->setGeometry(QRect(150, 160, 160, 16));
        horizontalScrollBar_4->setOrientation(Qt::Horizontal);
        horizontalScrollBar_6 = new QScrollBar(widget);
        horizontalScrollBar_6->setObjectName(QStringLiteral("horizontalScrollBar_6"));
        horizontalScrollBar_6->setGeometry(QRect(160, 300, 160, 16));
        horizontalScrollBar_6->setOrientation(Qt::Horizontal);
        lcdNumber_4 = new QLCDNumber(widget);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(80, 110, 64, 23));
        horizontalScrollBar_7 = new QScrollBar(widget);
        horizontalScrollBar_7->setObjectName(QStringLiteral("horizontalScrollBar_7"));
        horizontalScrollBar_7->setGeometry(QRect(160, 350, 160, 16));
        horizontalScrollBar_7->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 190, 50, 12));
        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(80, 60, 64, 23));
        lcdNumber_6 = new QLCDNumber(widget);
        lcdNumber_6->setObjectName(QStringLiteral("lcdNumber_6"));
        lcdNumber_6->setGeometry(QRect(80, 300, 64, 23));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 140, 50, 12));
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(183, 430, 91, 23));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 430, 111, 20));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 280, 121, 16));

        verticalLayout->addWidget(widget);


        gridLayout->addLayout(verticalLayout, 0, 3, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);

        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 790, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSAVE);
        menuFile->addAction(actionEXIT);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCustomPlot Scrollbar Axis Range Control Demo", 0));
        actionInsert_Plot->setText(QApplication::translate("MainWindow", "Insert Plot", 0));
        actionSave_Document->setText(QApplication::translate("MainWindow", "Save Document...", 0));
        actionSAVE->setText(QApplication::translate("MainWindow", "Save", 0));
        actionEXIT->setText(QApplication::translate("MainWindow", "Exit", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "SAMPLE READ", 0));
        label->setText(QApplication::translate("MainWindow", "SR", 0));
        label_3->setText(QApplication::translate("MainWindow", "Dofs", 0));
        label_2->setText(QApplication::translate("MainWindow", "Vofs", 0));
        label_4->setText(QApplication::translate("MainWindow", "a", 0));
        label_5->setText(QApplication::translate("MainWindow", "Sampling Count", 0));
        label_6->setText(QApplication::translate("MainWindow", "Pulse Number", 0));
        pushButton->setText(QApplication::translate("MainWindow", "RESET PIXEL", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "PULSE", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
