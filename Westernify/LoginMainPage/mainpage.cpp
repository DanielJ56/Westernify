#include "ui_mainpage.h"
#include "mainwindow.h"
#include "globle.h"
#include  <QtDebug>
#include "mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

    //queue = new Queue(username_qj);
    
    fileUploadPage = new UploadFile();
    fileUploadPage->hide();

    searchViewPage = new SearchView();
    searchViewPage->hide();

    playlistPage = new playlistUI(this, username_qj);
    playlistPage->hide();

    QLabel *lab= ui->label_user;
    lab->setText("Welcome back,\n" + username_qj);
    setWindowTitle(QString("Group26 - Westernify"));

    // Connect the database
    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;

    QPixmap userImage = d->getUserImage(username_qj);

    ui->label_image->setScaledContents(true);
    ui->label_image->setPixmap(userImage.scaled(ui->label_image->size(), Qt::KeepAspectRatioByExpanding));
    //ui->label_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QObject::connect(fileUploadPage, &UploadFile::pageIsFinished, this, &MainPage::showThisPage);
    connect(ui->playlistButton, &QPushButton::clicked, this, &MainPage::openPlaylistPage);
}

void MainPage::UploadImage() {
    QString filename = QFileDialog::getOpenFileName(
        this,
        "Open File",
        QDir::homePath(),
        "All Files (*.*)"
    );

    if (!filename.isEmpty()) {
        QFileInfo fileInfo(filename);
        long long fileSizeBytes = fileInfo.size();
        long long fileSizeMB = fileSizeBytes / (1024 * 1024);

        if (fileSizeMB >= 50) {
            QMessageBox::information(this, "Error", "<span style='color: black;'>File size too large!</span>");
        }
        else if (!filename.endsWith(".png")) {
            QMessageBox::warning(this, "Error", "<span style='color: black;'>Please select a PNG file.</span>");
        } else {
            QPixmap userImage = QPixmap(filename);

            ui->label_image->setScaledContents(true);
            ui->label_image->setPixmap(userImage.scaled(ui->label_image->size(), Qt::KeepAspectRatio));
        }

    }
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_goBackButton_clicked()
{
    MainWindow *h;
    this->hide();
    h=new MainWindow ;

    h->show();
}

void MainPage::openSearchPage() {
    this->hide();

    searchViewPage->show();
}


void MainPage::openUploadView() {
    this->hide();

    fileUploadPage->show();
}

void MainPage::openPlaylistPage() {
    playlistPage->show();
    this->hide();
}

void MainPage::showThisPage() {
    this->show();
}
