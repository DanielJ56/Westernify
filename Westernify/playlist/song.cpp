//
// Created by Maxime on 05/03/2024.
//

#include "song.h"

using namespace std;

void Song::loadContent() {
    // loads audio
}

Song::Song(int songId) {

    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;

    this->songId = songId;
    this->title = d->getSongTitle(songId);
    this->artistName = d->getSongArtist(songId);
}

Song::~Song() = default;

int Song::getSongId() { return songId; }

void Song::download() { }

QLayout* Song::show(QWidget* parent) {
    return new QGridLayout(parent);
}

QString Song::getName() { return title; }

QString Song::getArtist() { return artistName; }
