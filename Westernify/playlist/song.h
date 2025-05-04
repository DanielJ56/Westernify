//
// Created by Maxime on 05/03/2024.
//

#ifndef PROJECT_SONG_H
#define PROJECT_SONG_H

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "database.h"

/*
 * Class to represent and handle information related to songs easily for the playlist representation
 *  @author: maxime
 */
class Song {
private:
    int songId;
    QString title;
    QString artistName;


public:
    /*
     * Constructor method
     * @param songId: ID of the song
     */
    explicit Song(int songId);
    ~Song();

    void loadContent();
    /*
     * Gets ID of the song
     */
    int getSongId();

    /*
     * download default song
     */
    void download();

    /*
     * show parent
     */
    QLayout* show(QWidget* parent);

    /*
     * Gets song name
     */
    QString getName();

    /*
     * Gets artist
     */
    QString getArtist();

    /*
     * Reference to the database
     */
    Database *d;
};


#endif //PROJECT_SONG_H
