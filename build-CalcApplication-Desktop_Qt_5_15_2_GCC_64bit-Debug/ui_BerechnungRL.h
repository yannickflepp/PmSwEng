/********************************************************************************
** Form generated from reading UI file 'BerechnungRL.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BERECHNUNGRL_H
#define UI_BERECHNUNGRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BerechnungRL
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *BerechnungRL)
    {
        if (BerechnungRL->objectName().isEmpty())
            BerechnungRL->setObjectName(QString::fromUtf8("BerechnungRL"));
        BerechnungRL->resize(600, 400);
        label = new QLabel(BerechnungRL);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 17));
        pushButton = new QPushButton(BerechnungRL);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 350, 89, 25));

        retranslateUi(BerechnungRL);
        QObject::connect(pushButton, SIGNAL(pressed()), BerechnungRL, SLOT(close()));

        QMetaObject::connectSlotsByName(BerechnungRL);
    } // setupUi

    void retranslateUi(QWidget *BerechnungRL)
    {
        BerechnungRL->setWindowTitle(QCoreApplication::translate("BerechnungRL", "Form", nullptr));
        label->setText(QCoreApplication::translate("BerechnungRL", "RL_Berechnung", nullptr));
        pushButton->setText(QCoreApplication::translate("BerechnungRL", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BerechnungRL: public Ui_BerechnungRL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BERECHNUNGRL_H
