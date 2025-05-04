/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_user;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_image;
    QPushButton *pushButton;
    QPushButton *playlistButton;
    QPushButton *uploadButton;
    QPushButton *searchButton;
    QPushButton *goBackButton;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(448, 385);
        MainPage->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#MainPage {\n"
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
        verticalLayout = new QVBoxLayout(MainPage);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MainPage);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 85));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalWidget = new QWidget(MainPage);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_user = new QLabel(horizontalWidget);
        label_user->setObjectName("label_user");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_user->setFont(font1);
        label_user->setAlignment(Qt::AlignLeading);

        horizontalLayout->addWidget(label_user);

        verticalWidget = new QWidget(horizontalWidget);
        verticalWidget->setObjectName("verticalWidget");
        verticalLayout_2 = new QVBoxLayout(verticalWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_image = new QLabel(verticalWidget);
        label_image->setObjectName("label_image");

        verticalLayout_2->addWidget(label_image);

        pushButton = new QPushButton(verticalWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout->addWidget(verticalWidget);


        verticalLayout->addWidget(horizontalWidget);

        playlistButton = new QPushButton(MainPage);
        playlistButton->setObjectName("playlistButton");

        verticalLayout->addWidget(playlistButton);

        uploadButton = new QPushButton(MainPage);
        uploadButton->setObjectName("uploadButton");

        verticalLayout->addWidget(uploadButton);

        searchButton = new QPushButton(MainPage);
        searchButton->setObjectName("searchButton");

        verticalLayout->addWidget(searchButton);

        goBackButton = new QPushButton(MainPage);
        goBackButton->setObjectName("goBackButton");

        verticalLayout->addWidget(goBackButton);


        retranslateUi(MainPage);
        QObject::connect(searchButton, SIGNAL(clicked()), MainPage, SLOT(openSearchPage()));
        QObject::connect(uploadButton, SIGNAL(clicked()), MainPage, SLOT(openUploadView()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainPage, SLOT(UploadImage()));

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Main Page", nullptr));
        label->setText(QCoreApplication::translate("MainPage", "Westernify", nullptr));
        label_user->setText(QCoreApplication::translate("MainPage", "Welcome back!", nullptr));
        label_image->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainPage", "Upload new image...", nullptr));
        playlistButton->setText(QCoreApplication::translate("MainPage", "Playlist", nullptr));
        uploadButton->setText(QCoreApplication::translate("MainPage", "Upload", nullptr));
        searchButton->setText(QCoreApplication::translate("MainPage", "Search", nullptr));
        goBackButton->setText(QCoreApplication::translate("MainPage", "Go Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
