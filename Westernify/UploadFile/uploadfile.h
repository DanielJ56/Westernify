#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "AddArtist/addartist.h"
#include "database.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class UploadFile;
}
QT_END_NAMESPACE

class UploadFile : public QWidget
{
    Q_OBJECT

public:
    UploadFile(QWidget *parent = nullptr);
    ~UploadFile();

signals:
    void pageIsFinished();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void goBack();

    void on_pushButton_5_clicked();

private:
    Ui::UploadFile *ui;
    AddArtist *addArtistForm;
    QLineEdit *lineEdit_songName;
    QLineEdit *lineEdit_year;
    QLineEdit *lineEdit_songPath;
    QLineEdit *lineEdit_artist;
    QSqlDatabase myDB;
    QString queryInsert;
    Database *d;

};
#endif // UPLOADFILE_H
