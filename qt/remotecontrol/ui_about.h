/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About_Base
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *programName;
    QLabel *programLocation;
    QTextEdit *license;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *About_Base)
    {
        if (About_Base->objectName().isEmpty())
            About_Base->setObjectName(QStringLiteral("About_Base"));
        About_Base->resize(483, 353);
        verticalLayout = new QVBoxLayout(About_Base);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        programName = new QLabel(About_Base);
        programName->setObjectName(QStringLiteral("programName"));
        QFont font;
        font.setPointSize(18);
        programName->setFont(font);
        programName->setTextFormat(Qt::RichText);
        programName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(programName);

        programLocation = new QLabel(About_Base);
        programLocation->setObjectName(QStringLiteral("programLocation"));
        QFont font1;
        font1.setPointSize(12);
        programLocation->setFont(font1);
        programLocation->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(programLocation);

        license = new QTextEdit(About_Base);
        license->setObjectName(QStringLiteral("license"));
        license->setReadOnly(true);

        verticalLayout->addWidget(license);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(About_Base);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(About_Base);
        QObject::connect(closeButton, SIGNAL(clicked()), About_Base, SLOT(close()));

        QMetaObject::connectSlotsByName(About_Base);
    } // setupUi

    void retranslateUi(QWidget *About_Base)
    {
        About_Base->setWindowTitle(QApplication::translate("About_Base", "About Remote Control", 0));
        programName->setText(QApplication::translate("About_Base", "program name", 0));
        programLocation->setText(QApplication::translate("About_Base", "https://github.com/kc8hfi/powerwheels/", 0));
        closeButton->setText(QApplication::translate("About_Base", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class About_Base: public Ui_About_Base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
