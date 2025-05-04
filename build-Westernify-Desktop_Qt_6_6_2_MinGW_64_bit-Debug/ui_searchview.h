/********************************************************************************
** Form generated from reading UI file 'searchview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHVIEW_H
#define UI_SEARCHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchView
{
public:
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *goBackButton;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *SearchArea;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;

    void setupUi(QWidget *SearchView)
    {
        if (SearchView->objectName().isEmpty())
            SearchView->setObjectName("SearchView");
        SearchView->resize(697, 798);
        SearchView->setStyleSheet(QString::fromUtf8("background-color: #1C1B1F;"));
        verticalWidget = new QWidget(SearchView);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(0, 0, 701, 801));
        verticalWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName("verticalLayout");
        goBackButton = new QPushButton(verticalWidget);
        goBackButton->setObjectName("goBackButton");
        goBackButton->setStyleSheet(QString::fromUtf8("QPushButton#goBackButton {\n"
"	color: #E6E1E5;\n"
"	margin: 10px;\n"
"	border: 2px solid;\n"
"	border-color: #D0BCFF;\n"
"	border-radius: 15px;\n"
"	padding: 10px;\n"
"}"));

        verticalLayout->addWidget(goBackButton);

        verticalSpacer_2 = new QSpacerItem(10, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        SearchArea = new QLineEdit(verticalWidget);
        SearchArea->setObjectName("SearchArea");
        SearchArea->setMinimumSize(QSize(500, 0));
        SearchArea->setMaximumSize(QSize(500, 16777215));
        QFont font;
        font.setPointSize(18);
        SearchArea->setFont(font);
        SearchArea->setStyleSheet(QString::fromUtf8("QLineEdit#SearchArea {\n"
"	color: #E6E1E5;\n"
"	margin: 20px;\n"
"	border: 2px solid;\n"
"	border-color: #D0BCFF;\n"
"	border-radius: 30px;\n"
"	padding: 20px;\n"
"}"));

        verticalLayout->addWidget(SearchArea, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(10, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        listWidget = new QListWidget(verticalWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget::item::selected {\n"
"	background: #111111;\n"
"}"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(SearchView);

        QMetaObject::connectSlotsByName(SearchView);
    } // setupUi

    void retranslateUi(QWidget *SearchView)
    {
        SearchView->setWindowTitle(QCoreApplication::translate("SearchView", "SearchView", nullptr));
        goBackButton->setText(QCoreApplication::translate("SearchView", "Go Back", nullptr));
        SearchArea->setPlaceholderText(QCoreApplication::translate("SearchView", "Search...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchView: public Ui_SearchView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHVIEW_H
