/********************************************************************************
** Form generated from reading UI file 'addartist.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDARTIST_H
#define UI_ADDARTIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddArtist
{
public:
    QDateEdit *dateEdit;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AddArtist)
    {
        if (AddArtist->objectName().isEmpty())
            AddArtist->setObjectName("AddArtist");
        AddArtist->resize(400, 141);
        AddArtist->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#AddArtist {\n"
"            background-color: #5D3FD3;\n"
"        }\n"
"\n"
"        QLabel {\n"
"            color:  #FFFFFF;\n"
"            font-weight: bold;\n"
"        }\n"
"\n"
"        QPushButton {\n"
"            background-color: #5D3FD3;\n"
"            color: #FFFFFF;\n"
"            border-radius: 10px;\n"
"            border: 2px solid #000000;\n"
"            font-weight: bold;\n"
"            padding: 5px;\n"
"        }\n"
"\n"
"        QPushButton:hover {\n"
"            background-color: #000000;\n"
"            color: #FFFFFF;\n"
"            border: 2px solid #FFFFFF;\n"
"        }\n"
"\n"
"        QPushButton:pressed {\n"
"            background-color: #4B2CA7;\n"
"            border: 2px solid #FFFFFF;\n"
"        }\n"
"    "));
        dateEdit = new QDateEdit(AddArtist);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(170, 80, 110, 22));
        label = new QLabel(AddArtist);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 70, 111, 41));
        lineEdit = new QLineEdit(AddArtist);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 40, 111, 20));
        label_2 = new QLabel(AddArtist);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 40, 37, 20));
        pushButton = new QPushButton(AddArtist);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 80, 31));
        pushButton_2 = new QPushButton(AddArtist);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 110, 80, 31));

        retranslateUi(AddArtist);

        QMetaObject::connectSlotsByName(AddArtist);
    } // setupUi

    void retranslateUi(QWidget *AddArtist)
    {
        AddArtist->setWindowTitle(QCoreApplication::translate("AddArtist", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddArtist", "Date of Birth:", nullptr));
        label_2->setText(QCoreApplication::translate("AddArtist", "Name:", nullptr));
        pushButton->setText(QCoreApplication::translate("AddArtist", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddArtist", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddArtist: public Ui_AddArtist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDARTIST_H
