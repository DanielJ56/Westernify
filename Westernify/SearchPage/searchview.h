#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QWidget>
#include <QStandardItemModel>
#include "database.h"

/**
* @file searchview.h
* @brief Header file for the SearchView class.
* @author Vlad Krstevski
*/
QT_BEGIN_NAMESPACE

namespace Ui {
class SearchView;
}

QT_END_NAMESPACE


/**
* @brief The SearchView class provides a user interface for searching a database.
*
* This class is responsible for displaying a search field and a list of search results.
* It connects to a database and retrieves search results based on the user's input.
* The search results are displayed as custom items in a list widget.
*/
class SearchView : public QWidget
{
    Q_OBJECT

public:
    /**
    * @brief Constructs a SearchView object.
    * @param parent The parent widget.
    */
    SearchView(QWidget *parent = nullptr);

    /**
    * @brief Destroys the SearchView object.
    */
    ~SearchView();

private:
    Database *d = new Database(); /**< The database object used for querying. */

private slots:
    /**
    * @brief Handles the text change event in the search area.
    * @param arg1 The new text in the search area.
    *
    * This function clears the list widget and queries the database with the
    * provided search text. The search results are then displayed as custom
    * items in the list widget.
    */
    void on_SearchArea_textChanged(const QString &arg1);

    /**
    * @brief Handles the click event of the "Go Back" button.
    *
    * This function creates a new instance of the MainPage and shows it,
    * while hiding the current SearchView.
    */
    void on_goBackButton_clicked();
private:
    Ui::SearchView *ui; /**< The user interface object. */
};
#endif // SEARCHVIEW_H
