#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
// #include "studentform.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "insertlogin.h"
#include <QTimer>
#include "mainpage.h"
#include "database.h"
class insertlogin;

namespace Ui {
class MainWindow;
}

/**
 * @author Weiyi Zeng
 * @class MainWindow
 * @brief The MainWindow class provides the main window for the application.
 *
 * This class manages the user interface for the main window and handles the interactions
 * with various buttons and actions, including login, sign up, and timeout handling.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for MainWindow.
     * @param parent The parent widget, default is nullptr.
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot for handling the click event of the login button.
     *
     * This slot is triggered when the user clicks the login button, initiating the login process.
     */
    void on_LoginButton_clicked();

    /**
     * @brief Slot for handling the click event of the sign up button.
     *
     * This slot is triggered when the user clicks the sign up button, initiating the sign-up process.
     */
    void on_SignUpButton_clicked();

    /**
     * @brief Slot for handling the click event of the reset button.
     *
     * This slot is triggered when the user clicks the reset button, clearing the login form.
     */
    void on_remitButton_clicked();

    /**
     * @brief Slot for handling login timeout.
     *
     * This slot is triggered when the login process times out, displaying a timeout message.
     */
    void onLoginTimeout();  // Slot to handle login timeout

public slots:
    /**
     * @brief Slot for handling successful user signup.
     *
     * This slot is triggered when the user successfully signsup.
     */
    void on_successfulSignUp(QString username, QString password); // Slot to get the username from sign up window

signals:
    /**
     * @brief Signal for sending data.
     * @param data The data to be sent.
     */
    void sendData(QString);
private:
    Ui::MainWindow *ui; ///< Pointer to the user interface for MainWindow.
    insertlogin *insertLoginForm; ///< Pointer to the insert login form.
    MainPage *f; ///< Pointer to the main page.
    // manager *m;
    QTimer *loginTimer; ///< Timer for login timeout.

    Database *d; ///< Pointer to access database.
};

#endif // MAINWINDOW_H
