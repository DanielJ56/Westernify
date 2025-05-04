#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QDebug>

#include "SearchPage/searchview.h"
#include "UploadFile/uploadfile.h"
#include "playlist/playlistUI.h"
//#include "PlayWidget/queue.h"

namespace Ui {
class MainPage;
}


/**
 * @author Weiyi Zeng, Binhang Zhu
 * @class MainPage
 * @brief The MainPage class provides a widget for the main page of the application.
 *
 * This class manages the user interface for the main page and handles the interactions
 * with the go back button, allowing the user to navigate back to the previous page.
 */
class MainPage : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for MainPage.
     * @param parent The parent widget, default is nullptr.
     */
    explicit MainPage(QWidget *parent = 0);

    /**
     * @brief Destructor for MainPage.
     */
    ~MainPage();

private slots:
    /**
     * @brief Slot for handling the click event of the go back button.
     *
     * This slot is triggered when the user clicks the go back button, allowing them to navigate back to the previous page.
     */
    void on_goBackButton_clicked();

    /**
     * @brief Slot for handling the click event of the search page button.
     *
     * This slot is triggered when the user clicks the search page button, allowing them to navigate to the search page.
     */
    void openSearchPage();

    /**
     * @brief Slot for handling the click event of the upload song button.
     *
     * This slot is triggered when the user clicks the upload song button, allowing them to navigate to the upload page.
     */
    void openUploadView();

    /**
     * @brief Slot for handling the click event of the open playlist button.
     *
     * This slot is triggered when the user clicks the open playlist button, allowing them to navigate to the playlist page.
     */
    void openPlaylistPage();

    /**
     * @brief Slot for handling the click event of returning to main menu.
     *
     * This slot is triggered when the user clicks the go back button, returning to the main menu.
     */
    void showThisPage();

    /**
     * @brief Slot for handling the click event of the upload image button.
     *
     * This slot is triggered when the user clicks the upload image button, allowing them to choose a profile pic.
     */
    void UploadImage();


private:
    Ui::MainPage *ui; ///< Pointer to the user interface for MainPage.

    UploadFile *fileUploadPage;
    SearchView *searchViewPage;
    playlistUI* playlistPage;
    //Queue* queue;

    Database *d;
};

#endif // MAINPAGE_H
