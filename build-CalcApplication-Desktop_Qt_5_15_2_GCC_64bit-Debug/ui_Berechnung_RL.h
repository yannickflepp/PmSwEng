/********************************************************************************
** Form generated from reading UI file 'Berechnung_RL.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BERECHNUNG_RL_H
#define UI_BERECHNUNG_RL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Berechnung_RL
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Berechnung_RL)
    {
        if (Berechnung_RL->objectName().isEmpty())
            Berechnung_RL->setObjectName(QString::fromUtf8("Berechnung_RL"));
        Berechnung_RL->resize(400, 300);
        label = new QLabel(Berechnung_RL);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 67, 17));
        pushButton = new QPushButton(Berechnung_RL);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 170, 89, 25));

        retranslateUi(Berechnung_RL);

        QMetaObject::connectSlotsByName(Berechnung_RL);
    } // setupUi

    void retranslateUi(QWidget *Berechnung_RL)
    {
        Berechnung_RL->setWindowTitle(QCoreApplication::translate("Berechnung_RL", "Form", nullptr));
        label->setText(QCoreApplication::translate("Berechnung_RL", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Berechnung_RL", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Berechnung_RL: public Ui_Berechnung_RL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BERECHNUNG_RL_H
