/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *Login_username;
    QLabel *label_2;
    QLineEdit *Login_password;
    QRadioButton *radioButton_2;
    QPushButton *LoginButton;
    QPushButton *SignUpButton;
    QPushButton *remitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralWidget {\n"
"	background-color: #5D3FD3;\n"
"}\n"
"\n"
"QLabel, QRadioButton {\n"
"	color:  #FFFFFF;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: #5D3FD3;\n"
"	color: #FFFFFF;\n"
"	border-radius: 10px;\n"
"    border: 2px solid #000000;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #000000;\n"
"	color: #FFFFFF;\n"
"    border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #4B2CA7;\n"
"    border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background-color: #FFFFFF;\n"
"	color: #000000;\n"
"	border: 1px solid #000000;\n"
"	border-radius: 5px;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 71, 20));
        Login_username = new QLineEdit(centralWidget);
        Login_username->setObjectName("Login_username");
        Login_username->setGeometry(QRect(150, 50, 180, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 71, 20));
        Login_password = new QLineEdit(centralWidget);
        Login_password->setObjectName("Login_password");
        Login_password->setGeometry(QRect(150, 90, 180, 20));
        Login_password->setEchoMode(QLineEdit::Password);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(240, 130, 89, 20));
        LoginButton = new QPushButton(centralWidget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(70, 200, 80, 30));
        SignUpButton = new QPushButton(centralWidget);
        SignUpButton->setObjectName("SignUpButton");
        SignUpButton->setGeometry(QRect(160, 200, 80, 30));
        remitButton = new QPushButton(centralWidget);
        remitButton->setObjectName("remitButton");
        remitButton->setGeometry(QRect(250, 200, 80, 30));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Group26 - Westernify", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        Login_username->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your username", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        Login_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your password", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        SignUpButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        remitButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
