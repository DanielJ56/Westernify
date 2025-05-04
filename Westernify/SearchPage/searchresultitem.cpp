#include "searchresultitem.h"
#include "ui_searchresultitem.h"
#include "PlayWidget/music.h"
#include <iostream>

SearchResultItem::SearchResultItem(DB::Flags type, QPixmap icon, QString str1, QString str2, QString str3, int id, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SearchResultItem)
{
    ui->setupUi(this);

    ui->iconLbl->setPixmap(icon);
    ui->primaryLabel->setText(str1);
    ui->secondaryLabel->setText(str2);

    this->setMaximumHeight(80);

    // Hide the next button for everything BUT a song
    if (!(type & DB::TITLE))
        ui->nextButton->setHidden(true);
    else {
        // Recolor the button to match theme
        QPixmap recolor(":/res/next.png");
        QBitmap mask = recolor.createMaskFromColor(QColor("black"), Qt::MaskOutColor);
        recolor.fill(QColor(230,225,229));
        recolor.setMask(mask);

        ui->nextButton->setIcon(QIcon(recolor));

        // Initialize the button
        // myButton = new QPushButton("My Button", this);
        // QVBoxLayout *layout = new QVBoxLayout;
        // layout->addWidget(myButton);
        // this->setLayout(layout);

        connect(ui->nextButton, &QPushButton::clicked, this, [this, id]() { handleButton(id); });

    }

    if (type & DB::ARTIST || type & DB::PLAYLIST)
        ui->secondaryLabel->setHidden(true);
}

SearchResultItem::~SearchResultItem()
{
    delete ui;
}

void SearchResultItem::handleButton(int songID)
{
    std::cout << "print is working" << std::endl;
    //std::cout << "The path is : ||"<<str3.toStdString() << "||" <<std::endl;
    Music *newwindow = new Music(songID, this);
    newwindow->exec();
}
