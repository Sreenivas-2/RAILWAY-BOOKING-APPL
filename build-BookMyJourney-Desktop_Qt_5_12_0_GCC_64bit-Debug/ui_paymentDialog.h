/********************************************************************************
** Form generated from reading UI file 'paymentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTDIALOG_H
#define UI_PAYMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaymentDialog
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_time;
    QLabel *label_12;

    void setupUi(QDialog *PaymentDialog)
    {
        if (PaymentDialog->objectName().isEmpty())
            PaymentDialog->setObjectName(QString::fromUtf8("PaymentDialog"));
        PaymentDialog->resize(796, 575);
        label = new QLabel(PaymentDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 60, 181, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        groupBox = new QGroupBox(PaymentDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 100, 641, 201));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 471, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(500, 40, 121, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7, 0, Qt::AlignRight);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8, 0, Qt::AlignRight);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9, 0, Qt::AlignRight);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10, 0, Qt::AlignRight);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11, 0, Qt::AlignRight);

        checkBox = new QCheckBox(PaymentDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 310, 481, 31));
        QFont font3;
        font3.setPointSize(11);
        checkBox->setFont(font3);
        pushButton = new QPushButton(PaymentDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 400, 111, 25));
        pushButton_2 = new QPushButton(PaymentDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 400, 80, 25));
        label_time = new QLabel(PaymentDialog);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(670, 20, 54, 20));
        label_time->setFont(font3);
        label_12 = new QLabel(PaymentDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(540, 20, 121, 20));
        label_12->setFont(font3);

        retranslateUi(PaymentDialog);

        QMetaObject::connectSlotsByName(PaymentDialog);
    } // setupUi

    void retranslateUi(QDialog *PaymentDialog)
    {
        PaymentDialog->setWindowTitle(QApplication::translate("PaymentDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("PaymentDialog", "Payment Process", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("PaymentDialog", "Ticket Charges :", nullptr));
        label_3->setText(QApplication::translate("PaymentDialog", "Number of Seats Booked :", nullptr));
        label_4->setText(QApplication::translate("PaymentDialog", "Total Charges :", nullptr));
        label_5->setText(QApplication::translate("PaymentDialog", "CGST :", nullptr));
        label_6->setText(QApplication::translate("PaymentDialog", "Net Payable :", nullptr));
        label_7->setText(QApplication::translate("PaymentDialog", "TextLabel", nullptr));
        label_8->setText(QApplication::translate("PaymentDialog", "TextLabel", nullptr));
        label_9->setText(QApplication::translate("PaymentDialog", "TextLabel", nullptr));
        label_10->setText(QApplication::translate("PaymentDialog", "TextLabel", nullptr));
        label_11->setText(QApplication::translate("PaymentDialog", "TextLabel", nullptr));
        checkBox->setText(QApplication::translate("PaymentDialog", "I agree the Terms and Conditions of BOOK MY JOURNEY", nullptr));
        pushButton->setText(QApplication::translate("PaymentDialog", "Confirm Payment", nullptr));
        pushButton_2->setText(QApplication::translate("PaymentDialog", "cancel", nullptr));
        label_time->setText(QApplication::translate("PaymentDialog", "20", nullptr));
        label_12->setText(QApplication::translate("PaymentDialog", "Time remaining:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaymentDialog: public Ui_PaymentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTDIALOG_H
