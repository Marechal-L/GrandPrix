/********************************************************************************
** Form generated from reading UI file 'finishdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHDIALOG_H
#define UI_FINISHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FinnishDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *results;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *pseudo;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendButton;
    QPushButton *abortButton;

    void setupUi(QDialog *FinnishDialog)
    {
        if (FinnishDialog->objectName().isEmpty())
            FinnishDialog->setObjectName(QString::fromUtf8("FinnishDialog"));
        FinnishDialog->resize(400, 300);
        gridLayout = new QGridLayout(FinnishDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        results = new QLabel(FinnishDialog);
        results->setObjectName(QString::fromUtf8("results"));

        horizontalLayout_3->addWidget(results);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        splitter = new QSplitter(FinnishDialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        pseudo = new QLineEdit(splitter);
        pseudo->setObjectName(QString::fromUtf8("pseudo"));
        splitter->addWidget(pseudo);

        horizontalLayout_2->addWidget(splitter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendButton = new QPushButton(FinnishDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        abortButton = new QPushButton(FinnishDialog);
        abortButton->setObjectName(QString::fromUtf8("abortButton"));

        horizontalLayout->addWidget(abortButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FinnishDialog);
        QObject::connect(sendButton, SIGNAL(clicked()), FinnishDialog, SLOT(accept()));
        QObject::connect(abortButton, SIGNAL(clicked(bool)), FinnishDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FinnishDialog);
    } // setupUi

    void retranslateUi(QDialog *FinnishDialog)
    {
        FinnishDialog->setWindowTitle(QApplication::translate("FinnishDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        results->setText(QApplication::translate("FinnishDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FinnishDialog", "Pseudo:", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("FinnishDialog", "Send results to the server", 0, QApplication::UnicodeUTF8));
        abortButton->setText(QApplication::translate("FinnishDialog", "Abort", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FinnishDialog: public Ui_FinnishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHDIALOG_H
