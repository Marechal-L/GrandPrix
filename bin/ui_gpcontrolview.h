/********************************************************************************
** Form generated from reading UI file 'gpcontrolview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPCONTROLVIEW_H
#define UI_GPCONTROLVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "gpmapselector.h"

QT_BEGIN_NAMESPACE

class Ui_GPControlView
{
public:
    QVBoxLayout *verticalLayout;
    GPMapSelector *gpMapSelector;
    QGroupBox *driverGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *delaySlider;
    QSpinBox *delaySpinBox;
    QRadioButton *randomRadioButton;
    QRadioButton *deterministRadioButton;
    QRadioButton *sequentialRadioButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *runbutton;
    QPushButton *abortbutton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *GPControlView)
    {
        if (GPControlView->objectName().isEmpty())
            GPControlView->setObjectName(QString::fromUtf8("GPControlView"));
        GPControlView->resize(250, 366);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GPControlView->sizePolicy().hasHeightForWidth());
        GPControlView->setSizePolicy(sizePolicy);
        GPControlView->setMinimumSize(QSize(250, 0));
        GPControlView->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(GPControlView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gpMapSelector = new GPMapSelector(GPControlView);
        gpMapSelector->setObjectName(QString::fromUtf8("gpMapSelector"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(gpMapSelector->sizePolicy().hasHeightForWidth());
        gpMapSelector->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(gpMapSelector);

        driverGroupBox = new QGroupBox(GPControlView);
        driverGroupBox->setObjectName(QString::fromUtf8("driverGroupBox"));
        sizePolicy1.setHeightForWidth(driverGroupBox->sizePolicy().hasHeightForWidth());
        driverGroupBox->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(driverGroupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(GPControlView);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        delaySlider = new QSlider(GPControlView);
        delaySlider->setObjectName(QString::fromUtf8("delaySlider"));
        delaySlider->setMaximum(20);
        delaySlider->setPageStep(1);
        delaySlider->setSliderPosition(1);
        delaySlider->setOrientation(Qt::Horizontal);
        delaySlider->setTickPosition(QSlider::NoTicks);
        delaySlider->setTickInterval(2);

        horizontalLayout_2->addWidget(delaySlider);

        delaySpinBox = new QSpinBox(GPControlView);
        delaySpinBox->setObjectName(QString::fromUtf8("delaySpinBox"));
        delaySpinBox->setMaximum(20);
        delaySpinBox->setValue(1);

        horizontalLayout_2->addWidget(delaySpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        randomRadioButton = new QRadioButton(GPControlView);
        randomRadioButton->setObjectName(QString::fromUtf8("randomRadioButton"));
        randomRadioButton->setChecked(true);

        verticalLayout->addWidget(randomRadioButton);

        deterministRadioButton = new QRadioButton(GPControlView);
        deterministRadioButton->setObjectName(QString::fromUtf8("deterministRadioButton"));

        verticalLayout->addWidget(deterministRadioButton);

        sequentialRadioButton = new QRadioButton(GPControlView);
        sequentialRadioButton->setObjectName(QString::fromUtf8("sequentialRadioButton"));

        verticalLayout->addWidget(sequentialRadioButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        runbutton = new QPushButton(GPControlView);
        runbutton->setObjectName(QString::fromUtf8("runbutton"));

        horizontalLayout->addWidget(runbutton);

        abortbutton = new QPushButton(GPControlView);
        abortbutton->setObjectName(QString::fromUtf8("abortbutton"));

        horizontalLayout->addWidget(abortbutton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GPControlView);
        QObject::connect(delaySpinBox, SIGNAL(valueChanged(int)), delaySlider, SLOT(setValue(int)));
        QObject::connect(delaySlider, SIGNAL(valueChanged(int)), delaySpinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(GPControlView);
    } // setupUi

    void retranslateUi(QWidget *GPControlView)
    {
        GPControlView->setWindowTitle(QApplication::translate("GPControlView", "Form", 0, QApplication::UnicodeUTF8));
        driverGroupBox->setTitle(QApplication::translate("GPControlView", "Driver selection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GPControlView", "Delay:", 0, QApplication::UnicodeUTF8));
        randomRadioButton->setText(QApplication::translate("GPControlView", "Al\303\251atoire", 0, QApplication::UnicodeUTF8));
        deterministRadioButton->setText(QApplication::translate("GPControlView", "D\303\251terministe", 0, QApplication::UnicodeUTF8));
        sequentialRadioButton->setText(QApplication::translate("GPControlView", "S\303\251quentiel", 0, QApplication::UnicodeUTF8));
        runbutton->setText(QApplication::translate("GPControlView", "Run", 0, QApplication::UnicodeUTF8));
        abortbutton->setText(QApplication::translate("GPControlView", "Abort", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GPControlView: public Ui_GPControlView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPCONTROLVIEW_H
