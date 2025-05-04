/********************************************************************************
** Form generated from reading UI file 'insertlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTLOGIN_H
#define UI_INSERTLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertlogin
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *insert_namelineEdit_;
    QLabel *label_4;
    QLineEdit *insert_passwordlineEdit;
    QPushButton *insertloginButton;

    void setupUi(QWidget *insertlogin)
    {
        if (insertlogin->objectName().isEmpty())
            insertlogin->setObjectName("insertlogin");
        insertlogin->resize(400, 300);
        insertlogin->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#insertlogin {\n"
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
        label = new QLabel(insertlogin);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 20, 121, 16));
        label_3 = new QLabel(insertlogin);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 70, 71, 16));
        insert_namelineEdit_ = new QLineEdit(insertlogin);
        insert_namelineEdit_->setObjectName("insert_namelineEdit_");
        insert_namelineEdit_->setGeometry(QRect(130, 70, 220, 20));
        label_4 = new QLabel(insertlogin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 110, 71, 16));
        insert_passwordlineEdit = new QLineEdit(insertlogin);
        insert_passwordlineEdit->setObjectName("insert_passwordlineEdit");
        insert_passwordlineEdit->setGeometry(QRect(130, 110, 220, 20));
        insertloginButton = new QPushButton(insertlogin);
        insertloginButton->setObjectName("insertloginButton");
        insertloginButton->setGeometry(QRect(160, 160, 80, 30));

        retranslateUi(insertlogin);

        QMetaObject::connectSlotsByName(insertlogin);
    } // setupUi

    void retranslateUi(QWidget *insertlogin)
    {
        insertlogin->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("insertlogin", "Sign UP", nullptr));
        label_3->setText(QCoreApplication::translate("insertlogin", "Username:", nullptr));
        label_4->setText(QCoreApplication::translate("insertlogin", "Password:", nullptr));
        insertloginButton->setText(QCoreApplication::translate("insertlogin", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertlogin: public Ui_insertlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTLOGIN_H
