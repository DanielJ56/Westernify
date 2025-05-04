#ifndef INSERTLOGIN_H
#define INSERTLOGIN_H
#include "globle.h"
//#include "mainwindow.h"
#include <QWidget>
#include <database.h>

namespace Ui {
class insertlogin;
class MainWindow;
}

/**
 * @author Weiyi Zeng, Binhang Zhu
 * @class insertlogin
 * @brief The insertlogin class provides a widget for inserting login credentials.
 *
 * This class manages the user interface for inserting login credentials and handles the interactions
 * with the corresponding buttons for querying and inserting login information.
 */
class insertlogin : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for insertlogin.
     * @param parent The parent widget, default is nullptr.
     */
    explicit insertlogin(QWidget *parent = 0);
    /**
     * @brief Destructor for insertlogin.
     */
    ~insertlogin();

private slots:
    /**
     * @brief Slot for handling the click event of the insert login button.
     *
     * This slot is triggered when the user clicks the button to insert new login credentials into the database.
     */
    void on_insertloginButton_clicked();


signals:
    void signUpSucess(QString username, QString password); // When sign up was sucessful

private:
    Ui::insertlogin *ui; ///< Pointer to the user interface for insertlogin.
    Database *d;
};

#endif // INSERTLOGIN_H
