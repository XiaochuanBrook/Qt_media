/********************************************************************************
** Form generated from reading ui file 'daytime4.ui'
**
** Created: Mon Sep 29 08:32:03 2008
**      by: Qt User Interface Compiler version 4.4.0-rc1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DAYTIME4_H
#define UI_DAYTIME4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "analogclock.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QCalendarWidget *calendarWidget;
    //QLabel *label_2;
    AnalogClock *analogClock;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(640, 480);
    label = new QLabel(Form);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(0, 0, 640, 480));
    label->setPixmap(QPixmap(QString::fromUtf8(":/icon/bgw3.jpg")));
    label->setScaledContents(false);
    calendarWidget = new QCalendarWidget(Form);
    calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
    calendarWidget->setGeometry(QRect(0, 0, 481, 201));
    //label_2 = new QLabel(Form);
    //label_2->setObjectName(QString::fromUtf8("label_2"));
   // label_2->setGeometry(QRect(70, 260, 161, 171));
   // label_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/200807240937338302.png")));
    analogClock = new AnalogClock(Form);
    analogClock->setObjectName(QString::fromUtf8("analogClock"));
    analogClock->setGeometry(QRect(20, 220, 280, 255));

    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "DayTime", 0, QApplication::UnicodeUTF8));
    label->setText(QString());
   // label_2->setText(QString());

#ifndef QT_NO_TOOLTIP
    analogClock->setToolTip(QApplication::translate("Form", "The current time", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_WHATSTHIS
    analogClock->setWhatsThis(QApplication::translate("Form", "The analog clock widget displays the current time.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYTIME4_H
