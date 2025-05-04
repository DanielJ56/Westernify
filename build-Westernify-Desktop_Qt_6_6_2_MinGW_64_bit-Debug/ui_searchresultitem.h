/********************************************************************************
** Form generated from reading UI file 'searchresultitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULTITEM_H
#define UI_SEARCHRESULTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchResultItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *iconLbl;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *primaryLabel;
    QLabel *secondaryLabel;
    QPushButton *nextButton;

    void setupUi(QFrame *SearchResultItem)
    {
        if (SearchResultItem->objectName().isEmpty())
            SearchResultItem->setObjectName("SearchResultItem");
        SearchResultItem->resize(514, 116);
        SearchResultItem->setMaximumSize(QSize(16777215, 116));
        SearchResultItem->setStyleSheet(QString::fromUtf8("QFrame#SearchResultItem {\n"
"	margin: 5px 20px;\n"
"	background-color: #49454F;\n"
"	border-radius: 20px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(SearchResultItem);
        horizontalLayout->setObjectName("horizontalLayout");
        iconLbl = new QLabel(SearchResultItem);
        iconLbl->setObjectName("iconLbl");
        iconLbl->setMaximumSize(QSize(100, 100));
        iconLbl->setStyleSheet(QString::fromUtf8("background-color: #49454F;\n"
"margin: 5px"));
        iconLbl->setScaledContents(true);

        horizontalLayout->addWidget(iconLbl);

        widget = new QWidget(SearchResultItem);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 100));
        widget->setStyleSheet(QString::fromUtf8("background-color: #49454F;"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        primaryLabel = new QLabel(widget);
        primaryLabel->setObjectName("primaryLabel");
        primaryLabel->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"color: #E6E1E5;"));

        verticalLayout->addWidget(primaryLabel);

        secondaryLabel = new QLabel(widget);
        secondaryLabel->setObjectName("secondaryLabel");
        secondaryLabel->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"color: #E6E1E5;"));

        verticalLayout->addWidget(secondaryLabel);


        horizontalLayout->addWidget(widget);

        nextButton = new QPushButton(SearchResultItem);
        nextButton->setObjectName("nextButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy);
        nextButton->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font.setPointSize(45);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setKerning(true);
        nextButton->setFont(font);
        nextButton->setStyleSheet(QString::fromUtf8("background-color: #492532;\n"
"color: #AA0000;"));
        nextButton->setIconSize(QSize(48, 48));
        nextButton->setFlat(true);

        horizontalLayout->addWidget(nextButton);


        retranslateUi(SearchResultItem);

        QMetaObject::connectSlotsByName(SearchResultItem);
    } // setupUi

    void retranslateUi(QFrame *SearchResultItem)
    {
        SearchResultItem->setWindowTitle(QCoreApplication::translate("SearchResultItem", "Frame", nullptr));
        iconLbl->setText(QString());
        primaryLabel->setText(QString());
        secondaryLabel->setText(QString());
        nextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchResultItem: public Ui_SearchResultItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULTITEM_H
