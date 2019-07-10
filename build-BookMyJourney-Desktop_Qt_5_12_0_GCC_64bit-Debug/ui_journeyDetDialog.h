/********************************************************************************
** Form generated from reading UI file 'journeyDetDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNEYDETDIALOG_H
#define UI_JOURNEYDETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JourneyDetDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_from;
    QComboBox *comboBox_to;
    QDateEdit *dateEdit;
    QPushButton *pushButton_2;
    QToolButton *toolButton;

    void setupUi(QDialog *JourneyDetDialog)
    {
        if (JourneyDetDialog->objectName().isEmpty())
            JourneyDetDialog->setObjectName(QString::fromUtf8("JourneyDetDialog"));
        JourneyDetDialog->resize(762, 528);
        pushButton = new QPushButton(JourneyDetDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 380, 101, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        label = new QLabel(JourneyDetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 40, 181, 61));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        verticalLayoutWidget = new QWidget(JourneyDetDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 130, 171, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        verticalLayoutWidget_2 = new QWidget(JourneyDetDialog);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(319, 130, 251, 141));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_from = new QComboBox(verticalLayoutWidget_2);
        comboBox_from->addItem(QString());
        comboBox_from->addItem(QString());
        comboBox_from->addItem(QString());
        comboBox_from->addItem(QString());
        comboBox_from->addItem(QString());
        comboBox_from->setObjectName(QString::fromUtf8("comboBox_from"));

        verticalLayout_2->addWidget(comboBox_from);

        comboBox_to = new QComboBox(verticalLayoutWidget_2);
        comboBox_to->addItem(QString());
        comboBox_to->addItem(QString());
        comboBox_to->addItem(QString());
        comboBox_to->addItem(QString());
        comboBox_to->addItem(QString());
        comboBox_to->setObjectName(QString::fromUtf8("comboBox_to"));

        verticalLayout_2->addWidget(comboBox_to);

        dateEdit = new QDateEdit(verticalLayoutWidget_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setEnabled(true);

        verticalLayout_2->addWidget(dateEdit);

        pushButton_2 = new QPushButton(JourneyDetDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(650, 20, 80, 25));
        toolButton = new QToolButton(JourneyDetDialog);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(580, 230, 24, 24));

        retranslateUi(JourneyDetDialog);

        QMetaObject::connectSlotsByName(JourneyDetDialog);
    } // setupUi

    void retranslateUi(QDialog *JourneyDetDialog)
    {
        JourneyDetDialog->setWindowTitle(QApplication::translate("JourneyDetDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("JourneyDetDialog", "Search", nullptr));
        label->setText(QApplication::translate("JourneyDetDialog", "Plan Your Journey", nullptr));
        label_3->setText(QApplication::translate("JourneyDetDialog", "Boarding Point", nullptr));
        label_2->setText(QApplication::translate("JourneyDetDialog", "Destination", nullptr));
        label_4->setText(QApplication::translate("JourneyDetDialog", "Journey Date", nullptr));
        comboBox_from->setItemText(0, QApplication::translate("JourneyDetDialog", "Mumbai", nullptr));
        comboBox_from->setItemText(1, QApplication::translate("JourneyDetDialog", "Delhi", nullptr));
        comboBox_from->setItemText(2, QApplication::translate("JourneyDetDialog", "Chennai", nullptr));
        comboBox_from->setItemText(3, QApplication::translate("JourneyDetDialog", "Kolkata", nullptr));
        comboBox_from->setItemText(4, QApplication::translate("JourneyDetDialog", "Bangalore", nullptr));

        comboBox_to->setItemText(0, QApplication::translate("JourneyDetDialog", "Mumbai", nullptr));
        comboBox_to->setItemText(1, QApplication::translate("JourneyDetDialog", "Delhi", nullptr));
        comboBox_to->setItemText(2, QApplication::translate("JourneyDetDialog", "Chennai", nullptr));
        comboBox_to->setItemText(3, QApplication::translate("JourneyDetDialog", "Kolkata", nullptr));
        comboBox_to->setItemText(4, QApplication::translate("JourneyDetDialog", "Bangalore", nullptr));

        pushButton_2->setText(QApplication::translate("JourneyDetDialog", "LOGOUT", nullptr));
        toolButton->setText(QApplication::translate("JourneyDetDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JourneyDetDialog: public Ui_JourneyDetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNEYDETDIALOG_H
