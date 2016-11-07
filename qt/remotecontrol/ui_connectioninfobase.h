/********************************************************************************
** Form generated from reading UI file 'connectioninfobase.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONINFOBASE_H
#define UI_CONNECTIONINFOBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionInfoBase
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ipLabel;
    QLineEdit *ipText;
    QHBoxLayout *horizontalLayout;
    QLabel *portLabel;
    QLineEdit *portText;

    void setupUi(QDialog *ConnectionInfoBase)
    {
        if (ConnectionInfoBase->objectName().isEmpty())
            ConnectionInfoBase->setObjectName(QStringLiteral("ConnectionInfoBase"));
        ConnectionInfoBase->resize(400, 163);
        buttonBox = new QDialogButtonBox(ConnectionInfoBase);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 100, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(ConnectionInfoBase);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 20, 222, 64));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ipLabel = new QLabel(widget);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));

        horizontalLayout_2->addWidget(ipLabel);

        ipText = new QLineEdit(widget);
        ipText->setObjectName(QStringLiteral("ipText"));

        horizontalLayout_2->addWidget(ipText);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        portLabel = new QLabel(widget);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        horizontalLayout->addWidget(portLabel);

        portText = new QLineEdit(widget);
        portText->setObjectName(QStringLiteral("portText"));

        horizontalLayout->addWidget(portText);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConnectionInfoBase);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectionInfoBase, SLOT(okClicked()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectionInfoBase, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectionInfoBase);
    } // setupUi

    void retranslateUi(QDialog *ConnectionInfoBase)
    {
        ConnectionInfoBase->setWindowTitle(QApplication::translate("ConnectionInfoBase", "Dialog", 0));
        ipLabel->setText(QApplication::translate("ConnectionInfoBase", "TextLabel", 0));
        portLabel->setText(QApplication::translate("ConnectionInfoBase", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectionInfoBase: public Ui_ConnectionInfoBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONINFOBASE_H
