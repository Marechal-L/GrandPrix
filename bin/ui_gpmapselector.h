/********************************************************************************
** Form generated from reading UI file 'gpmapselector.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPMAPSELECTOR_H
#define UI_GPMAPSELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GPMapSelector
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listMap;

    void setupUi(QWidget *GPMapSelector)
    {
        if (GPMapSelector->objectName().isEmpty())
            GPMapSelector->setObjectName(QString::fromUtf8("GPMapSelector"));
        GPMapSelector->resize(400, 298);
        verticalLayout = new QVBoxLayout(GPMapSelector);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(GPMapSelector);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listMap = new QListWidget(GPMapSelector);
        listMap->setObjectName(QString::fromUtf8("listMap"));

        verticalLayout->addWidget(listMap);


        retranslateUi(GPMapSelector);

        QMetaObject::connectSlotsByName(GPMapSelector);
    } // setupUi

    void retranslateUi(QWidget *GPMapSelector)
    {
        GPMapSelector->setWindowTitle(QApplication::translate("GPMapSelector", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GPMapSelector", "Map selection :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GPMapSelector: public Ui_GPMapSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPMAPSELECTOR_H
