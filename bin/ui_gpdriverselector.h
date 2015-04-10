/********************************************************************************
** Form generated from reading UI file 'gpdriverselector.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPDRIVERSELECTOR_H
#define UI_GPDRIVERSELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GPDriverSelector
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *debug;
    QLabel *info;

    void setupUi(QWidget *GPDriverSelector)
    {
        if (GPDriverSelector->objectName().isEmpty())
            GPDriverSelector->setObjectName(QString::fromUtf8("GPDriverSelector"));
        GPDriverSelector->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GPDriverSelector->sizePolicy().hasHeightForWidth());
        GPDriverSelector->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(GPDriverSelector);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(GPDriverSelector);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(GPDriverSelector);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        debug = new QCheckBox(GPDriverSelector);
        debug->setObjectName(QString::fromUtf8("debug"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(debug->sizePolicy().hasHeightForWidth());
        debug->setSizePolicy(sizePolicy1);
        debug->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(debug);

        info = new QLabel(GPDriverSelector);
        info->setObjectName(QString::fromUtf8("info"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(info->sizePolicy().hasHeightForWidth());
        info->setSizePolicy(sizePolicy2);
        info->setText(QString::fromUtf8(""));
        info->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(info);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(GPDriverSelector);

        QMetaObject::connectSlotsByName(GPDriverSelector);
    } // setupUi

    void retranslateUi(QWidget *GPDriverSelector)
    {
        GPDriverSelector->setWindowTitle(QApplication::translate("GPDriverSelector", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GPDriverSelector", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        debug->setToolTip(QApplication::translate("GPDriverSelector", "Affiche stderr dans la console et les positions atteignables sur la carte", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        debug->setText(QApplication::translate("GPDriverSelector", "Mode debug", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GPDriverSelector: public Ui_GPDriverSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPDRIVERSELECTOR_H
