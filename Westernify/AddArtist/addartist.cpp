#include "addartist.h"
#include "ui_addartist.h"
#include <QMessageBox>

AddArtist::AddArtist(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddArtist)
{
    ui->setupUi(this);
    lineEdit_artistName = ui->lineEdit; //Sets up variable to access line edit
    if (!d->establish_connection()) //Display error if cannot connect to db
        std::cerr << "Issue connecting to database" << std::endl;

}


//Deconstructor for addartist
AddArtist::~AddArtist()
{
    delete ui;
}


//Back button
void AddArtist::on_pushButton_clicked()
{
    this->hide();
    lineEdit_artistName->clear();
}


//Add button pressed
void AddArtist::on_pushButton_2_clicked()
{
    if (lineEdit_artistName->text().isEmpty())  //Checks if artist name is filled in
    {
        QMessageBox::warning(this, "Error", "<span style='color: black;'>Please complete all fields.</span>");
        return;
    }

    //Obtain the info inputted by user
    QDate selectedDate = ui->dateEdit->date();
    QString artistName = lineEdit_artistName->text();
    QString formattedDate = selectedDate.toString("yyyy-MM-dd");

    //Call SQL query to add the artist
    DB::RetCodes result = d->addNewArtist(artistName, formattedDate);

    //Show message depending on the result of the query
    if (result == DB::DB_SUCCESS) {
        QMessageBox::information(this, "Success", "<span style='color: black;'>Artist added successfully.</span>");
        lineEdit_artistName->clear();
    } else if (result == DB::DB_ARTIST_EXISTS) {
        QMessageBox::warning(this, "Error", "<span style='color: black;'>Artist already exists.</span>");
    } else {
        QMessageBox::critical(this, "Error", "<span style='color: black;'>Failed to add new artist!</span>");
    }
}

