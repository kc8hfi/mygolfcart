/********************************************************************************
** Form generated from reading UI file 'remotecontrolbase.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTECONTROLBASE_H
#define UI_REMOTECONTROLBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteControlBase
{
public:
    QAction *actionQuit;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionAbout_Remote_Control;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *forwardButton;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *leftButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QToolButton *rightButton;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *reverseButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QToolButton *turretUpButton;
    QSpacerItem *horizontalSpacer_10;
    QToolButton *turretLeftButton;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *turretRightButton;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *turretDownButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *fireButton;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *RemoteControlBase)
    {
        if (RemoteControlBase->objectName().isEmpty())
            RemoteControlBase->setObjectName(QStringLiteral("RemoteControlBase"));
        RemoteControlBase->resize(538, 564);
        actionQuit = new QAction(RemoteControlBase);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionConnect = new QAction(RemoteControlBase);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(RemoteControlBase);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionAbout_Remote_Control = new QAction(RemoteControlBase);
        actionAbout_Remote_Control->setObjectName(QStringLiteral("actionAbout_Remote_Control"));
        centralwidget = new QWidget(RemoteControlBase);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 211, 251));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 184, 202));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        forwardButton = new QToolButton(layoutWidget);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/vehicleIcons/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon);
        forwardButton->setIconSize(QSize(32, 32));
        forwardButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(forwardButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        leftButton = new QToolButton(layoutWidget);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/vehicleIcons/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon1);
        leftButton->setIconSize(QSize(32, 32));
        leftButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(leftButton, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        rightButton = new QToolButton(layoutWidget);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/vehicleIcons/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon2);
        rightButton->setIconSize(QSize(32, 32));
        rightButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(rightButton, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        reverseButton = new QToolButton(layoutWidget);
        reverseButton->setObjectName(QStringLiteral("reverseButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/vehicleIcons/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        reverseButton->setIcon(icon3);
        reverseButton->setIconSize(QSize(32, 32));
        reverseButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(reverseButton, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 20, 221, 281));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 184, 232));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_9 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        turretUpButton = new QToolButton(layoutWidget1);
        turretUpButton->setObjectName(QStringLiteral("turretUpButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/vehicleIcons/up_turret.png"), QSize(), QIcon::Normal, QIcon::Off);
        turretUpButton->setIcon(icon4);
        turretUpButton->setIconSize(QSize(32, 32));
        turretUpButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(turretUpButton, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        turretLeftButton = new QToolButton(layoutWidget1);
        turretLeftButton->setObjectName(QStringLiteral("turretLeftButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/vehicleIcons/left_turret.png"), QSize(), QIcon::Normal, QIcon::Off);
        turretLeftButton->setIcon(icon5);
        turretLeftButton->setIconSize(QSize(32, 32));
        turretLeftButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(turretLeftButton, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 1, 1, 1);

        turretRightButton = new QToolButton(layoutWidget1);
        turretRightButton->setObjectName(QStringLiteral("turretRightButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/vehicleIcons/right_turret.png"), QSize(), QIcon::Normal, QIcon::Off);
        turretRightButton->setIcon(icon6);
        turretRightButton->setIconSize(QSize(32, 32));
        turretRightButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(turretRightButton, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        turretDownButton = new QToolButton(layoutWidget1);
        turretDownButton->setObjectName(QStringLiteral("turretDownButton"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/vehicleIcons/down_turret.png"), QSize(), QIcon::Normal, QIcon::Off);
        turretDownButton->setIcon(icon7);
        turretDownButton->setIconSize(QSize(32, 32));
        turretDownButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(turretDownButton, 2, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        fireButton = new QPushButton(layoutWidget1);
        fireButton->setObjectName(QStringLiteral("fireButton"));

        gridLayout_2->addWidget(fireButton, 3, 0, 1, 3);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 280, 256, 192));
        RemoteControlBase->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RemoteControlBase);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 538, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        RemoteControlBase->setMenuBar(menubar);
        statusBar = new QStatusBar(RemoteControlBase);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font;
        font.setPointSize(12);
        statusBar->setFont(font);
        RemoteControlBase->setStatusBar(statusBar);
        toolBar = new QToolBar(RemoteControlBase);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(20, 20));
        toolBar->setFont(font);
        RemoteControlBase->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout_Remote_Control);
        toolBar->addSeparator();
        toolBar->addAction(actionConnect);
        toolBar->addAction(actionDisconnect);

        retranslateUi(RemoteControlBase);
        QObject::connect(forwardButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_forward()));
        QObject::connect(forwardButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_forward()));
        QObject::connect(leftButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_left()));
        QObject::connect(leftButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_left()));
        QObject::connect(reverseButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_reverse()));
        QObject::connect(reverseButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_reverse()));
        QObject::connect(rightButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_right()));
        QObject::connect(rightButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_right()));
        QObject::connect(fireButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_fire()));
        QObject::connect(fireButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_fire()));
        QObject::connect(turretDownButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_turret_down()));
        QObject::connect(turretDownButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_turret_down()));
        QObject::connect(turretLeftButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_turret_left()));
        QObject::connect(turretLeftButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_turret_left()));
        QObject::connect(turretRightButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_turret_right()));
        QObject::connect(turretRightButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_turret_right()));
        QObject::connect(turretUpButton, SIGNAL(pressed()), RemoteControlBase, SLOT(start_turret_up()));
        QObject::connect(turretUpButton, SIGNAL(released()), RemoteControlBase, SLOT(stop_turret_up()));
        QObject::connect(actionConnect, SIGNAL(triggered()), RemoteControlBase, SLOT(serverConnect()));
        QObject::connect(actionQuit, SIGNAL(triggered()), RemoteControlBase, SLOT(close()));
        QObject::connect(actionDisconnect, SIGNAL(triggered()), RemoteControlBase, SLOT(serverDisconnect()));
        QObject::connect(actionAbout_Remote_Control, SIGNAL(triggered()), RemoteControlBase, SLOT(about()));

        QMetaObject::connectSlotsByName(RemoteControlBase);
    } // setupUi

    void retranslateUi(QMainWindow *RemoteControlBase)
    {
        RemoteControlBase->setWindowTitle(QApplication::translate("RemoteControlBase", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("RemoteControlBase", "&Quit", 0));
        actionConnect->setText(QApplication::translate("RemoteControlBase", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("RemoteControlBase", "Disconnect", 0));
        actionAbout_Remote_Control->setText(QApplication::translate("RemoteControlBase", "&About Remote Control", 0));
        groupBox->setTitle(QApplication::translate("RemoteControlBase", "Vehicle Controls", 0));
        forwardButton->setText(QApplication::translate("RemoteControlBase", "W", 0));
        leftButton->setText(QApplication::translate("RemoteControlBase", "A", 0));
        rightButton->setText(QApplication::translate("RemoteControlBase", "D", 0));
        reverseButton->setText(QApplication::translate("RemoteControlBase", "S", 0));
        groupBox_2->setTitle(QApplication::translate("RemoteControlBase", "Turret Controls", 0));
        turretUpButton->setText(QApplication::translate("RemoteControlBase", "I", 0));
        turretLeftButton->setText(QApplication::translate("RemoteControlBase", "J", 0));
        turretRightButton->setText(QApplication::translate("RemoteControlBase", "L", 0));
        turretDownButton->setText(QApplication::translate("RemoteControlBase", "K", 0));
        fireButton->setText(QApplication::translate("RemoteControlBase", "FIRE (Enter)", 0));
        menuFile->setTitle(QApplication::translate("RemoteControlBase", "Fi&le", 0));
        menuHelp->setTitle(QApplication::translate("RemoteControlBase", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("RemoteControlBase", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class RemoteControlBase: public Ui_RemoteControlBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTECONTROLBASE_H
