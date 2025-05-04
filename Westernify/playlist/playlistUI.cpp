#include "playlistUI.h"
#include "ui_playlistUI.h"
#include "LoginMainPage/mainpage.h"
using namespace std;

playlistUI::playlistUI(QWidget *parent, QString userName)
    : QMainWindow(parent)
    , ui(new Ui::playlistUI)
{
    ui->setupUi(this);

    this->userName = userName;

    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;

    QPushButton *newPlaylistBtn = new QPushButton("Create Playlist", this);
    newPlaylistBtn->setGeometry(100, 100, 200, 50);
    QPushButton *myPlaylistsBtn = new QPushButton("My Playlists", this);
    myPlaylistsBtn->setGeometry(400, 100, 200, 50);


    connect(newPlaylistBtn, &QPushButton::clicked, this, &playlistUI::createPlaylistPopup);
    connect(myPlaylistsBtn, &QPushButton::clicked, this, &playlistUI::showPlaylists);

}

playlistUI::~playlistUI()
{
    delete ui;
    delete d;
}

void playlistUI::on_goBackButton_clicked()
{   
    MainPage *m;
    this->hide();
    m=new MainPage;
    m->show();
}


// set images and songs folder and default cover image
void playlistUI::setupFolders() {
    // check if the folder containing the covers exists
    struct stat sb;
    if (stat("./images", &sb) != 0) std::filesystem::create_directory("./images");

    // check if the default cover exists
    if (stat("./images/default.jpg", &sb) != 0)
        if (!std::filesystem::copy_file("/Users/maxcap/Downloads/default.jpg", "./images/default.jpg"))
            qDebug() << "default image copy failed";

    // check if the folder containing the songs exists
    if (stat("./songs", &sb) != 0) std::filesystem::create_directory("./songs");
}

// open popup to select name and cover of new playlist
void playlistUI::createPlaylistPopup() {
    // popup
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("New Playlist");
    dialog->resize(200, 300);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(new QLabel("<span style='color: black;'>Playlist name:</span>", dialog));

    // playlist name field
    QLineEdit *inputField = new QLineEdit(dialog); // Set parent explicitly
    layout->addWidget(inputField);

    // select a cover for the playlist
    QPushButton *selectImageButton = new QPushButton("Select Image (optional, jpg only)", dialog);
    layout->addWidget(selectImageButton);

    QLabel *imageLabel = new QLabel(dialog);
    layout->addWidget(imageLabel);

    QString imagePath = "";

    QObject::connect(selectImageButton, &QPushButton::clicked, [dialog, &imagePath]() {
        imagePath = QFileDialog::getOpenFileName(dialog, "Select Image", "", "Images (*.jpg)");
    });

    QPushButton *confirmButton = new QPushButton("Create", dialog);
    layout->addWidget(confirmButton);
    confirmButton->setEnabled(false);

    QObject::connect(inputField, &QLineEdit::textChanged, [confirmButton](const QString &text) {
        confirmButton->setEnabled(!text.isEmpty());
    });

    QObject::connect(confirmButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);

    if (dialog->exec() == QDialog::Accepted) { // Check the result
        QString playlistName = inputField->text();
        d->addNewPlaylist(playlistName, imagePath, userName);
    }

    delete dialog; // Delete the dialog object

    qDebug() << "Dialog closed";
}

// preview of all the playlists created by the user
void playlistUI::showPlaylists() {
    vector<int> playlistIds = d->getUserPlaylists(userName);
    playlists = new vector<Playlist*>();

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("My playlists");
    dialog->resize(500, 500);
    QGridLayout* layout = new QGridLayout(dialog);



    for (int i = 0; i < playlistIds.size(); i++){
        playlists->emplace_back(new Playlist(playlistIds[i]));
        QPushButton* btn = new QPushButton(dialog);
        btn->setLayout(playlists->at(i)->showPreview(dialog));
        btn->setFixedSize(200, 200);
        btn->setProperty("id", i);
        btn->setStyleSheet("background-color: #5D3FD3");
        layout->addWidget(btn, i / 2, i%2);

        connect(btn, &QPushButton::clicked, this, [i, this, &dialog]() {
            int status = this->showPlaylist(i);

            if (status == 1 || status == 2) {
                delete playlists->at(i);
                playlists->erase(playlists->begin() + i);
                this->showPlaylists();
            }
        });
    }

    dialog->setLayout(layout);
    dialog->exec();

    delete playlists;
}

// get preview of a playlist
int playlistUI::showPlaylist(int playlistId) {
    qDebug()<<"The playlist ID pass to showPlaylist is: ";
    qDebug()<<playlistId;
    Playlist *playlist = playlists->at(playlistId);
    qDebug()<<"The playlist ID obtained from the vector is: ";
    qDebug()<<playlist->getId();
    int status = 0; // 0: not modifed; 1: content modified; 2: playlist deleted

    QDialog *dialog = new QDialog(this);
    dialog->setStyleSheet("background-color: #5D3FD3");
    dialog->setWindowTitle(playlist->getName());
    dialog->setFixedSize(600, 800);

    playlist->loadSongs();
    vector<int> songs = playlist->getSongs();

    QPushButton *deleteBtn = new QPushButton("delete playlist", dialog);
    deleteBtn->setFixedSize(150, 50);
    QPushButton *addSongBtn = new QPushButton("add song", dialog);
    addSongBtn->setFixedSize(150, 50);

    QGridLayout *layout = new QGridLayout(dialog); // Set the parent explicitly
    layout->addWidget(deleteBtn, 0, 1);
    layout->addWidget(addSongBtn, 0, 3);

    QPushButton* playBtn;
    QPushButton* deleteSongBtn;
    QPushButton* moveUpBtn;
    QPushButton* moveDownBtn;
    QLabel* title;
    QLabel* artist;

    for (int i = 0; i < songs.size(); i++) {
        playBtn = new QPushButton("play", dialog);
        deleteSongBtn = new QPushButton("delete", dialog);
        moveUpBtn = new QPushButton("pos+1", dialog);
        moveDownBtn = new QPushButton("pos-1", dialog);
        title = new QLabel(d->getSongTitle(songs[i]));
        artist = new QLabel(d->getSongArtist(songs[i]));

        layout->addWidget(title, i + 1, 0);
        layout->addWidget(artist, i + 1, 1);
        layout->addWidget(playBtn, i + 1, 2);
        layout->addWidget(deleteSongBtn, i + 1, 3);
        //layout->addWidget(moveUpBtn, i + 1, 4);
        layout->addWidget(moveDownBtn, i + 1, 4);

        connect(playBtn, &QPushButton::clicked, dialog, [&,songs,i ,this, playlist]() {
            // play music, add next songs to queue

            //playlist->mplayer = new Music(9, this);
            //playlist->mplayer->exec();
            Music *mp = new Music(songs[i],this);
            mp->startPlaying();
            mp->exec();

            //this->hide();
        });

        connect(deleteSongBtn, &QPushButton::clicked, dialog, [playlist, songs, i, &status, &layout]() {
            qDebug()<<"The ID of the playlist you are trying to delete is: :";
            qDebug()<<songs[i];
            playlist->removeFromPlaylist(songs[i]);

            status = 1;
            QLayoutItem *item;
            for (int j = 0; j < 6; j++) {
                item = layout->itemAtPosition(i + 1, j);
                item->widget()->hide();
                layout->removeWidget(item->widget());
                layout->update();
            }
        });

        connect(moveUpBtn, &QPushButton::clicked, dialog, [songs, playlist, i, &status, &layout]() {
            int sId = songs[i];

            if (i == playlist->getSongs().size() - 1) return; // last song already

            playlist->changeOrder(i, i+1);
            status = 1;

            QWidget* item1;
            QWidget* item2;

            for (int j = 0; j < 5; j++) { // pos - is working properly but pos+ not for some reason
                item1 = layout->itemAtPosition(i + 1, j)->widget();
                item2 = layout->itemAtPosition(i + 2, j)->widget();
                layout->removeWidget(item1);
                layout->removeWidget(item2);
                layout->addWidget(item1, i + 2, j);
                layout->addWidget(item2, i + 1, j);
            }
        });

        connect(moveDownBtn, &QPushButton::clicked, dialog, [songs, playlist, i, &status, layout]() {
            int sId = songs[i];

            if (i == 0) return; // first song already

            playlist->changeOrder(i, i-1);
            status = 1;

            QWidget* item1;
            QWidget* item2;

            for (int j = 0; j < 5; j++) {
                item1 = layout->itemAtPosition(i + 1, j)->widget();
                item2 = layout->itemAtPosition(i, j)->widget();
                layout->removeWidget(item1);
                layout->removeWidget(item2);
                layout->addWidget(item1, i, j);
                layout->addWidget(item2, i + 1, j);
            }
        });

    }

    connect(deleteBtn, &QPushButton::clicked, dialog, [playlist, &status, dialog, this]() {
        int id = playlist->getId();
        std::cout << "The value of id is: " << id;
        d->deletePlaylist(id);
        status = 2;
        dialog->done(0);
    });

    connect(addSongBtn, &QPushButton::clicked, dialog, [playlist, songs, &status, this, dialog, layout]() {
        int songId = this->selectSong(playlist->getId());
        if (songId != -1) {

            playlist->addToPlaylist(songId);
            int row = layout->rowCount() + 1;
            QPushButton* playBtn = new QPushButton("play", dialog);
            QPushButton* deleteSongBtn = new QPushButton("delete", dialog);
            QPushButton* moveUpBtn = new QPushButton("pos+1", dialog);
            QPushButton* moveDownBtn = new QPushButton("pos-1", dialog);

            layout->addWidget(new QLabel(d->getSongTitle(songId), dialog), row, 0);
            layout->addWidget(new QLabel(d->getSongArtist(songId), dialog), row, 1);
            layout->addWidget(playBtn, row, 2);
            layout->addWidget(deleteSongBtn, row, 3);
            //layout->addWidget(moveUpBtn, row, 4);
            layout->addWidget(moveDownBtn, row, 4);

            // this part looks pretty bad, should change it later
            connect(playBtn, &QPushButton::clicked, dialog, [&]() {
                // play music, add next songs to queue
            });

            connect(deleteSongBtn, &QPushButton::clicked, dialog, [playlist, row, songs, &status, &layout]() {
                playlist->removeFromPlaylist(songs[row]);
                status = 1;
                QLayoutItem *item;
                for (int j = 0; j < 6; j++) {
                    item = layout->itemAtPosition(row, j);
                    item->widget()->hide();
                    layout->removeWidget(item->widget());
                    layout->update();
                }
            });

            connect(moveUpBtn, &QPushButton::clicked, dialog, [songs, playlist, row, &status, &layout]() {
                int sId = songs[row - 1];

                if (row == playlist->getSongs().size() - 1) return; // last song already

                playlist->changeOrder(row - 1, row);
                status = 1;

                QWidget* item1;
                QWidget* item2;

                for (int j = 0; j < 5; j++) { // pos - is working properly but pos+ not for some reason
                    item1 = layout->itemAtPosition(row, j)->widget();
                    item2 = layout->itemAtPosition(row + 1, j)->widget();
                    layout->removeWidget(item1);
                    layout->removeWidget(item2);
                    layout->addWidget(item1, row + 1, j);
                    layout->addWidget(item2, row, j);
                }
            });

            connect(moveDownBtn, &QPushButton::clicked, dialog, [songs, playlist, row, &status, layout]() {
                int sId = songs[row - 1];

                if (row == 1) return; // first song already

                playlist->changeOrder(row - 1, row - 2);
                status = 1;

                QWidget* item1;
                QWidget* item2;

                for (int j = 0; j < 5; j++) { // not really working for some reason the buttons move in a weird way
                    item1 = layout->itemAtPosition(row, j)->widget();
                    item2 = layout->itemAtPosition(row - 1, j)->widget();
                    layout->removeWidget(item1);
                    layout->removeWidget(item2);
                    layout->addWidget(item1, row - 1, j);
                    layout->addWidget(item2, row, j);
                }
            });

            status = 1;
        }
    });

    dialog->setLayout(layout);
    dialog->exec();
    cout << status << endl;
    delete dialog;
    return status;
}

// select a song to add to a playlist
int playlistUI::selectSong(int playlistId) {
    vector<int> songIds = d->getSongsNotInPlaylist(playlistId);
    //vector<int> songIds = d->getPlaylistSongs(playlistId);

    vector<Song> songs;

    QDialog *dialog = new QDialog(this);
    QGridLayout *layout = new QGridLayout(dialog);
    QPushButton *addSongBtn;
    int songId = -1;

    for (int id: songIds) {
        songs.emplace_back(Song(id));

        addSongBtn = new QPushButton("add", dialog);
        addSongBtn->setStyleSheet("background-color: grey");
        connect(addSongBtn, &QPushButton::clicked, dialog, [dialog, id, &songId]() {
            dialog->accept();
            songId = id;
        });

        layout->addWidget(new QLabel(songs.back().getName(), dialog), songs.size() - 1, 0);
        layout->addWidget(new QLabel(songs.back().getArtist(), dialog), songs.size() - 1, 1);
        layout->addWidget(addSongBtn, songs.size() - 1, 2);
    }
    dialog->setStyleSheet("background-color: #5D3FD3");
    dialog->setLayout(layout);


    dialog->exec();
    delete dialog;
    return songId;
}

void playlistUI::goBack() {
    this->hide();
    //emit pageIsFinished();
}

vector<Playlist*> *playlistUI::getPlaylists() { return playlists; }
