//
// Created by Maxime on 05/03/2024.
//

#include "playlist.h"
#include "PlayWidget/music.h"

using namespace std;

Playlist::Playlist(int playlistId) : QObject(nullptr) {

    mplayer = new Music();
    QObject::connect(mplayer, &Music::songFinished, this, &Playlist::onSongFinished);

    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;

    this->playlistId = playlistId;
    this->name = d->getPlaylistName(playlistId);
    this->cover = d->getCover(playlistId);
    songIds = d->getPlaylistSongs(playlistId);
}

Playlist::~Playlist() {};

void Playlist::loadSongs() {
    if (songIds.size() != 0) songs.clear();
    for (int id: songIds) songs.emplace_back(Song(id));
}

void Playlist::deletePlaylist() {
    d->deletePlaylist(playlistId);
}

void Playlist::addToQueue(int songIndex) {
    for (auto it = songs.begin(); it != songs.end(); it++)
        continue; // add song to queue
}

void Playlist::addToPlaylist(int songId) {
    songs.emplace_back(songId);
    d->addSongToPlaylist(playlistId,songId,  (int) songs.size());
}

void Playlist::removeFromPlaylist(int songId) {
    for (auto it = songs.begin(); it != songs.end(); it++) {
        if (it->getSongId() == songId) {
            songs.erase(it);
            qDebug()<<"From inside remove From Playlist, playlist->>playlistId is:";
            qDebug()<<playlistId;
            d->removeSongFromPlaylist( playlistId, songId);
            return;
        }
    }
}

void Playlist::onSongFinished() {
    std::cout << "Song finished signal recieved\n11";
}


/*
void Playlist::share(int senderId, int receiverId) const {
   dbManager::addMessage(senderId, receiverId, "share playlist" + to_string(playlistId));
}

void Playlist::download() {
    for (auto & song : songs) song.download();
}

void Playlist::setName(std::string newName) { this->name = std::move(newName); }

void

Playlist::setCover(std::string newCoverPath) { this->coverPath = std::move(newCoverPath); }
*/

int Playlist::getId() { return playlistId; }

QString Playlist::getName() { return name; }

QPixmap Playlist::getCover() { return cover; }

vector<int> Playlist::getSongs() { return songIds; }

int Playlist::getSongPos(int songId) {
    for (int i = 0; i < songs.size(); i++){
        if (songs[i].getSongId() == songId)
            return i;
    }

    return -1;
}

void Playlist::show() {
    // generate visual representation for the playlist
    qDebug() << "show playlisy " << name;
}

// swap pos of 2 songs
void Playlist::changeOrder(int position, int newPosition) {
    d->changeSongPosition(playlistId, songIds[position], position, newPosition);

    int id = songIds[position];
    songIds[position] = songIds[newPosition];
    songIds[newPosition] = id;

    Song* song = &songs[position];
    songs[position] = songs[newPosition];
    songs[newPosition] = *song;
}

// get widget containing the cover and the title
QLayout* Playlist::showPreview(QWidget* parent) {
    /*
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QPushButton* btn = new QPushButton(widget);
    btn->setIcon(QIcon(QString::fromStdString("./images/" + coverPath)));
    btn->setFixedSize(180, 180);

    QLabel* label = new QLabel(QString::fromStdString(name), widget);

    // QObject::connect(btn, &QPushButton::clicked, this, &Playlist::show);

    layout->addWidget(btn);
    layout->addWidget(label);
    widget->setLayout(layout);
    */
    QVBoxLayout* layout = new QVBoxLayout(parent);

    QLabel* imageLabel = new QLabel(parent);
    QPixmap previewImage = cover.scaled(180, 180);
    if (previewImage.isNull()) qDebug() << "error loading playlist cover";
    imageLabel->setPixmap(previewImage);

    QLabel* textLabel = new QLabel(name, parent);
    textLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(imageLabel);
    layout->addWidget(textLabel);

    return layout;
}
