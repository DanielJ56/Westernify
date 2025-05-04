#include "uploadfile.h"
#include "ui_uploadfile.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

#include "SearchPage/searchview.h"

UploadFile::UploadFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UploadFile)
{
    ui->setupUi(this);

    //Sets up the variables for the form that user will fill out
    QIntValidator *yearValidator = new QIntValidator(this);
    ui->lineEdit_year->setValidator(yearValidator);
    lineEdit_songName = ui->lineEdit_song;
    lineEdit_year = ui->lineEdit_year;
    lineEdit_songPath = ui->lineEdit;
    lineEdit_artist = ui->lineEdit_artist;

    addArtistForm = new AddArtist();
    addArtistForm->hide();

    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;


    this->show();
}

UploadFile::~UploadFile()
{
    delete ui;
}



void UploadFile::on_pushButton_clicked()
{
    //Obtains file path of user's selected song
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Open File",
                                                    QDir::homePath(),
                                                    "All Files (*.*)");
    //Ensures that field isn't empty, verifies mp3 file and its size doesn't exceed 50 Mb.
    if (!filename.isEmpty()) {
        QFileInfo fileInfo(filename);
        long long fileSizeBytes = fileInfo.size();
        long long fileSizeMB = fileSizeBytes / (1024 * 1024);
        if (filename.endsWith(".mp3") && fileSizeMB <= 50) {
            QMessageBox::information(this, "Success", "<span style='color: black;'>You selected an MP3 file!</span>");
            lineEdit_songPath->setText(filename);
        } else {
            if (!filename.endsWith(".mp3")){
                QMessageBox::warning(this, "Error", "<span style='color: black;'>Please select an MP3 file.</span>");
            }else{
                QMessageBox::warning(this, "Error", "<span style='color: black;'>File size exceeds 50 MB!</span>");
            }

        }

    }
}

//Clears all fields
void UploadFile::on_pushButton_4_clicked()
{
    lineEdit_songName->clear();
    lineEdit_year->clear();
    lineEdit_songPath->clear();
    lineEdit_artist->clear();
}


//Upload button, checks if all fields are filled out before uploading
void UploadFile::on_pushButton_2_clicked()
{
    if (lineEdit_songName->text().isEmpty() ||
        lineEdit_year->text().isEmpty() ||
        lineEdit_songPath->text().isEmpty() ||
        lineEdit_artist->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "<span style='color: black;'>Please complete all fields.</span>");
        return;
    }

    // Aquire data
    QString songName = lineEdit_songName->text();
    int year = lineEdit_year->text().toInt();
    QString songPath = lineEdit_songPath->text();
    QString artistName = lineEdit_artist->text();
    int artistId = d->getArtistId(artistName);

    if (artistId == -1) {
        QMessageBox::warning(this, "Artist not found", "<span style='color: black;'>Please add the artist to the database first.</span>");
        return;
    }
    // Execute query to add song
    DB::RetCodes returnCode = d->addNewSong(songName, year, songPath, artistId);

    // Check if query was a success
    if (returnCode & DB::DB_SUCCESS) {
        QMessageBox::information(this, "Success", "<span style='color: black;'>Song added to database.</span>");
        lineEdit_songName->clear();
        lineEdit_year->clear();
        lineEdit_songPath->clear();
        lineEdit_artist->clear();
    } else {
        QMessageBox::critical(this, "Error", "<span style='color: black;'>Failed to insert song into database.</span>");
    }
}


void UploadFile::on_pushButton_3_clicked()
{
    //Placeholder for back button
}


void UploadFile::goBack() {
    // Hide this page
    this->hide();
    addArtistForm->hide();
    // Alert that this page is finished
    emit pageIsFinished();
}


void UploadFile::on_pushButton_5_clicked()
{
    addArtistForm->show();
}
