/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QWidget *centralWidget;
    QPushButton *goButton;
    QPushButton *brakeButton;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QPushButton *ignitionOnButton;
    QPushButton *ignitionOffButton;
    QGroupBox *groupBox_2;
    QLabel *revolutions;
    QLabel *label_3;
    QLabel *heading;
    QLabel *label_5;
    QLabel *label;
    QLabel *ticks;
    QToolButton *leftButton;
    QToolButton *rightButton;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QMenu *menuConnect;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(616, 449);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        goButton = new QPushButton(centralWidget);
        goButton->setObjectName(QStringLiteral("goButton"));
        goButton->setGeometry(QRect(330, 270, 101, 51));
        brakeButton = new QPushButton(centralWidget);
        brakeButton->setObjectName(QStringLiteral("brakeButton"));
        brakeButton->setGeometry(QRect(470, 270, 101, 51));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 120, 256, 61));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 261, 80));
        ignitionOnButton = new QPushButton(groupBox);
        ignitionOnButton->setObjectName(QStringLiteral("ignitionOnButton"));
        ignitionOnButton->setGeometry(QRect(20, 30, 82, 23));
        ignitionOffButton = new QPushButton(groupBox);
        ignitionOffButton->setObjectName(QStringLiteral("ignitionOffButton"));
        ignitionOffButton->setGeometry(QRect(170, 30, 82, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 10, 301, 151));
        revolutions = new QLabel(groupBox_2);
        revolutions->setObjectName(QStringLiteral("revolutions"));
        revolutions->setGeometry(QRect(99, 73, 151, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 49, 81, 20));
        heading = new QLabel(groupBox_2);
        heading->setObjectName(QStringLiteral("heading"));
        heading->setGeometry(QRect(99, 31, 151, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 70, 91, 20));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 28, 71, 20));
        ticks = new QLabel(groupBox_2);
        ticks->setObjectName(QStringLiteral("ticks"));
        ticks->setGeometry(QRect(99, 52, 151, 20));
        leftButton = new QToolButton(centralWidget);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(50, 270, 101, 51));
        leftButton->setMinimumSize(QSize(101, 0));
        QIcon icon;
        icon.addFile(QStringLiteral("resources/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon);
        leftButton->setIconSize(QSize(32, 32));
        leftButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        rightButton = new QToolButton(centralWidget);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(170, 270, 101, 51));
        rightButton->setMinimumSize(QSize(61, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral("resources/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon1);
        rightButton->setIconSize(QSize(32, 32));
        rightButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 240, 61, 15));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 240, 101, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 240, 66, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(480, 240, 66, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 21));
        menuConnect = new QMenu(menuBar);
        menuConnect->setObjectName(QStringLiteral("menuConnect"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConnect->menuAction());
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "This is the title", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        goButton->setText(QApplication::translate("MainWindow", "J", 0));
        brakeButton->setText(QApplication::translate("MainWindow", "L", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ignition", 0));
        ignitionOnButton->setText(QApplication::translate("MainWindow", "Start", 0));
        ignitionOffButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Status", 0));
        revolutions->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Ticks", 0));
        heading->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "revolutions", 0));
        label->setText(QApplication::translate("MainWindow", "Heading", 0));
        ticks->setText(QString());
        leftButton->setText(QApplication::translate("MainWindow", "A", 0));
        rightButton->setText(QApplication::translate("MainWindow", "D", 0));
        label_2->setText(QApplication::translate("MainWindow", "Turn Left", 0));
        label_4->setText(QApplication::translate("MainWindow", "Turn Right", 0));
        label_6->setText(QApplication::translate("MainWindow", "Throttle", 0));
        label_7->setText(QApplication::translate("MainWindow", "Brake", 0));
        menuConnect->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
