/********************************************************************************
** Form generated from reading UI file 'uploadfile.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADFILE_H
#define UI_UPLOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadFile
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLineEdit *lineEdit_song;
    QLabel *label_3;
    QLineEdit *lineEdit_year;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLineEdit *lineEdit_artist;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *UploadFile)
    {
        if (UploadFile->objectName().isEmpty())
            UploadFile->setObjectName("UploadFile");
        UploadFile->resize(800, 600);
        UploadFile->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#UploadFile {\n"
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
        centralwidget = new QWidget(UploadFile);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 591, 411));
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#centralwidget {\n"
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 120, 161, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 120, 231, 31));
        QFont font1;
        font1.setPointSize(12);
        lineEdit->setFont(font1);
        lineEdit->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 20, 221, 71));
        label->setMaximumSize(QSize(221, 71));
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(true);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(420, 370, 131, 41));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 30, 111, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 170, 111, 61));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_song = new QLineEdit(centralwidget);
        lineEdit_song->setObjectName("lineEdit_song");
        lineEdit_song->setGeometry(QRect(330, 190, 231, 31));
        lineEdit_song->setMaxLength(255);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(270, 250, 41, 31));
        label_3->setFont(font);
        lineEdit_year = new QLineEdit(centralwidget);
        lineEdit_year->setObjectName("lineEdit_year");
        lineEdit_year->setGeometry(QRect(330, 250, 231, 31));
        lineEdit_year->setMaxLength(4);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(230, 370, 131, 41));
        pushButton_4->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 310, 41, 31));
        label_4->setFont(font);
        lineEdit_artist = new QLineEdit(centralwidget);
        lineEdit_artist->setObjectName("lineEdit_artist");
        lineEdit_artist->setGeometry(QRect(330, 310, 231, 31));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(120, 310, 121, 31));
        menubar = new QMenuBar(UploadFile);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        statusbar = new QStatusBar(UploadFile);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(UploadFile);
        QObject::connect(pushButton_3, SIGNAL(clicked()), UploadFile, SLOT(goBack()));

        QMetaObject::connectSlotsByName(UploadFile);
    } // setupUi

    void retranslateUi(QWidget *UploadFile)
    {
        UploadFile->setWindowTitle(QCoreApplication::translate("UploadFile", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("UploadFile", "Browse", nullptr));
        label->setText(QCoreApplication::translate("UploadFile", "Upload Song", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UploadFile", "Upload", nullptr));
        pushButton_3->setText(QCoreApplication::translate("UploadFile", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("UploadFile", "Song Name:", nullptr));
        label_3->setText(QCoreApplication::translate("UploadFile", "Year:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("UploadFile", "Clear Entires", nullptr));
        label_4->setText(QCoreApplication::translate("UploadFile", "Artist:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("UploadFile", "Add New Artist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UploadFile: public Ui_UploadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILE_H
