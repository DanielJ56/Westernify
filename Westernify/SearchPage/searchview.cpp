#include "searchview.h"
#include "ui_searchview.h"
#include "SearchPage/searchresultitem.h"
#include "LoginMainPage/mainpage.h"
#include <database.h>

SearchView::SearchView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchView)
{
    ui->setupUi(this);


    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;


    // Query the database with just an empty string
    on_SearchArea_textChanged("");

}

SearchView::~SearchView()
{
    delete ui;
    delete d;
}
void SearchView::on_goBackButton_clicked()
{   
    MainPage *h;
    this->hide();
    h=new MainPage;
    h->show();
}

void SearchView::on_SearchArea_textChanged(const QString &arg1)
{
    // reset ui->listWidget
    ui->listWidget->clear();

    // get results
    std::vector<SearchResult> results = d->searchDatabase(arg1);

    for (auto &result : results) {
        // Add an item
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        QPixmap image(result.image);

        SearchResultItem *customItem = new SearchResultItem(result.type, image, result.str1, result.str2, result.str3, result.id);
        ui->listWidget->setItemWidget(item, customItem);
        item->setSizeHint(QSize(customItem->width(), customItem->height()));
    }


}

