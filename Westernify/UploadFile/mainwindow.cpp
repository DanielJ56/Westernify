#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator *yearValidator = new QIntValidator(this);
    ui->lineEdit_year->setValidator(yearValidator);
    lineEdit_songName = ui->lineEdit_song;
    lineEdit_year = ui->lineEdit_year;
    lineEdit_songPath = ui->lineEdit;
    queryInsert = "INSERT INTO songs (name, year, filepath) "
                       "VALUES (:songName, :year, :songPath)";
    connectDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,
                                                   "Open File",
                                                   QDir::homePath(),
                                                   "All Files (*.*)");
    if (!filename.isEmpty()) {
        QFileInfo fileInfo(filename);
        long long fileSizeBytes = fileInfo.size();
        long long fileSizeMB = fileSizeBytes / (1024 * 1024);
        if (filename.endsWith(".mp3") && fileSizeMB <= 50) {
            QMessageBox::information(this, "Success", "You selected an MP3 file!");
            lineEdit_songPath->setText(filename);
        } else {
            if (!filename.endsWith(".mp3")){
                QMessageBox::warning(this, "Error", "Please select an MP3 file.");
            }else{
                QMessageBox::warning(this, "Error", "File size exceeds 50 MB!");
            }

        }

    }
}
bool MainWindow::connectDB(){
    myDB = QSqlDatabase::addDatabase("QMYSQL");
    myDB.setHostName("localhost"); // Replace with your MySQL Server address if needed
    myDB.setDatabaseName("test");
    myDB.setUserName("root");
    myDB.setPassword("1234");

    if (!myDB.open()) {
        qDebug() << "Error: Failed to connect to database.";
        return false;
    } else {
        QMessageBox::information(this, "Connection", "Successfully connected to database!");
        return true;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    lineEdit_songName->clear();
    lineEdit_year->clear();
    lineEdit_songPath->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (lineEdit_songName->text().isEmpty() ||
        lineEdit_year->text().isEmpty() ||
        lineEdit_songPath->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please complete all fields.");
        return;
    }
    QSqlQuery query(myDB);
    query.prepare(queryInsert);
    query.bindValue(":songName", lineEdit_songName->text());
    query.bindValue(":year", lineEdit_year->text().toInt());
    query.bindValue(":songPath", lineEdit_songPath->text());
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to insert song into database: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Song added to database.");
        lineEdit_songName->clear();
        lineEdit_year->clear();
        lineEdit_songPath->clear();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    //Placeholder for back button
}

