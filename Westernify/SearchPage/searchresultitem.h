#ifndef SEARCHRESULTITEM_H
#define SEARCHRESULTITEM_H

#include <QFrame>
#include <QPixmap>
#include <QBitmap>
#include <QPushButton>
#include "database.h"

/**
* @file searchview.h
* @brief Custom search list item header file
* @author Vlad Krstevski
*/
namespace Ui {
class SearchResultItem;
}

/**
* @brief The SearchResultItem class represents a custom widget for displaying search results
*
* This class inherits from QFrame and displays the search result information, including
* an image, type, and three argument strings used for varying purposes. It also includes a button that can be used to
* perform an action based on the search result like play the song.
*/
class SearchResultItem : public QFrame
{
    Q_OBJECT

public:
    /**
    * @brief Constructs a SearchResultItem object.
    * @param type The type of the search result.
    * @param image The image associated with the search result.
    * @param str1 The first argument string of the search result.
    * @param str2 The second argument string of the search result.
    * @param str3 The third argument string of the search result.
    * @param id The ID associated with the search result.
    * @param parent The parent widget.
    */
    explicit SearchResultItem(DB::Flags, QPixmap, QString, QString,QString, int id = NULL, QWidget *parent = nullptr);

    /**
    * @brief Destroys the SearchResultItem object.
    */
    ~SearchResultItem();
private slots:
    /**
    * @brief Handles the button click event.
    * @param songid The ID of the song associated with the button click.
    *
    * This slot function is called when the button in the SearchResultItem is clicked.
    * It can be used to perform an action based on the song ID like playing this particular song.
    */
    void handleButton(int songid);
private:
    Ui::SearchResultItem *ui; /**< The user interface object. */
    QPushButton *myButton;  /**< The button in the SearchResultItem. */

};

#endif // SEARCHRESULTITEM_H
