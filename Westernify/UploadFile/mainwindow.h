#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit_songName;
    QLineEdit *lineEdit_year;
    QLineEdit *lineEdit_songPath;
    QSqlDatabase myDB;
    QString queryInsert;
    bool connectDB();
};
#endif // MAINWINDOW_H
