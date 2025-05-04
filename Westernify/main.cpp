#include "SearchPage/searchview.h"

// #include <QApplication> no need for this anymore

#include <QApplication>
#include <QtCore5Compat/QTextCodec>
#include "LoginMainPage/mainwindow.h"
#include "LoginMainPage/insertlogin.h"

const int W = 700;
const int H = 800;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
     * This would create a search view
    SearchView w;
    */

    MainWindow w;

    //w.setMinimumSize(QSize(W, H));
    //w.setMaximumSize(QSize(W, H));


    w.show();
    return a.exec();
}
