/********************************************************************************
** Form generated from reading UI file 'playlistUI.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTUI_H
#define UI_PLAYLISTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playlistUI
{
public:
    QWidget *centralwidget;
    QPushButton *goBackButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *playlistUI)
    {
        if (playlistUI->objectName().isEmpty())
            playlistUI->setObjectName("playlistUI");
        playlistUI->resize(800, 600);
        centralwidget = new QWidget(playlistUI);
        centralwidget->setObjectName("centralwidget");
        goBackButton = new QPushButton(centralwidget);
        goBackButton->setObjectName("goBackButton");
        goBackButton->setGeometry(QRect(10, 10, 100, 30));
        playlistUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(playlistUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        playlistUI->setMenuBar(menubar);
        statusbar = new QStatusBar(playlistUI);
        statusbar->setObjectName("statusbar");
        playlistUI->setStatusBar(statusbar);

        retranslateUi(playlistUI);

        QMetaObject::connectSlotsByName(playlistUI);
    } // setupUi

    void retranslateUi(QMainWindow *playlistUI)
    {
        playlistUI->setWindowTitle(QCoreApplication::translate("playlistUI", "playlistUI", nullptr));
        goBackButton->setText(QCoreApplication::translate("playlistUI", "Go Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playlistUI: public Ui_playlistUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTUI_H
