#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include "insertlogin.h"
#include "globle.h"
#include <QTimer>
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    insertLoginForm(nullptr),
    loginTimer(new QTimer(this))
{
    ui->setupUi(this);

    // Connect the database
    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;


    /**
     * These were the reason that two signals were sent
     */



    connect(loginTimer, SIGNAL(timeout()), this, SLOT(onLoginTimeout()));  // Connect the timer's timeout signal


    // Hide password
    ui->Login_password->setEchoMode(QLineEdit::Password);

    // Auto check USER
    ui->radioButton_2->setChecked(true);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete insertLoginForm;
}
void MainWindow::on_LoginButton_clicked(){
    loginTimer->start(5000);  // 5-second timeout
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();

    #ifdef DEBUG
    qDebug() << "username: " << username << ", password: " << password << "\n";
    #endif

   if(ui->radioButton_2->isChecked()) {
        std::vector<std::pair<QString, QString>> combinations = d->retrieveUserLoginInfo();

        bool AuthSuccess = false;
        // Loop thru values
        for (const std::pair<QString, QString> &loginpass : combinations)
        {
            // Set username and password to try
            QString user = loginpass.first;
            QString pass = loginpass.second;
            if(username.compare(user) == 0 && password.compare(pass) == 0){
                loginTimer->stop();
                password_qj = password;
                username_qj = username;
                AuthSuccess = true;
                this->hide();
                QMessageBox::information(this, "Congrats:", "<span style='color: black;'>Login Succeed!</span>");
                f=new MainPage;
                emit sendData(username + "&" + password);
                f->show();
            }
        }

        if(!AuthSuccess){
            loginTimer->stop();
            QMessageBox::information(this, "WARNING:", "<span style='color: black;'>Username or password not correct.</span>");}
   }

}
void MainWindow::on_SignUpButton_clicked()
{
    qDebug() << "Sign Up button clicked";
    
    if (!insertLoginForm) {
        insertLoginForm = new insertlogin();
        connect(insertLoginForm, &insertlogin::signUpSucess, this, &MainWindow::on_successfulSignUp);
        // Optional: Set the form to be modal if desired
        // insertLoginForm->setWindowModality(Qt::ApplicationModal);
    }
    insertLoginForm->show();
}
void MainWindow::on_remitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}
void MainWindow::onLoginTimeout()
{
    // Stop the timer
    loginTimer->stop();

    // Display a timeout message
    QMessageBox::warning(this, "Login Timeout", "<span style='color: black;'>Login attempt timed out. Please try again.</span>");
}


// Set the username and password from the newly created account
void MainWindow::on_successfulSignUp(QString username, QString password) {
    ui->Login_username->setText(username);
    ui->Login_password->setText(password);
}







