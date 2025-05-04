#include "insertlogin.h"
#include "ui_insertlogin.h"
#include <QMessageBox>
//#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include <QTimer>
// #include "userlogin.h"

insertlogin::insertlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertlogin)
{
    ui->setupUi(this);

    // Connect the database
    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;

}

insertlogin::~insertlogin()
{
    delete ui;
}

void insertlogin::on_insertloginButton_clicked()
{

    QString username = ui->insert_namelineEdit_->text();
    QString password = ui->insert_passwordlineEdit->text();

    // Check if values are too short
    if (username.length() < 3) {
        QMessageBox::information(this, tr("Warning:"), tr("<span style='color: black;'>Username too short!</span>"));
        return;
    }
    else if (password.length() < 3) {
        QMessageBox::information(this, tr("Warning:"), tr("<span style='color: black;'>Password too short!</span>"));
        return;
    }

    // Try to sign the user up
    DB::RetCodes returnVal = d->signUserUp(username, password);// QString id = ui->inster_IdlineEdit->text();


    // Check the return value
    switch (returnVal) {
    case DB::DB_USERNAME_EXISTS:
        QMessageBox::information(this, tr("Warning:"), tr("<span style='color: black;'>This username exists!</span>"));
        break;
    case DB::DB_SUCCESS:
        QMessageBox::information(this, tr("Warning:"), tr("<span style='color: black;'>Sign up succeed!</span>"));

        // Alert MainWindow of sucess
        emit signUpSucess(username, password);

        this->destroy();

        break;
    case DB::DB_FAILURE:
        QMessageBox::information(this, tr("Warning:"), tr("<span style='color: black;'>Sign up Failed!</span>"));
        break;
    }
}





