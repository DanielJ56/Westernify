//
// Created by Maxime on 05/03/2024.
//

#ifndef PROJECT_PLAYLIST_H
#define PROJECT_PLAYLIST_H

#include <QObject>
#include <QWidget>

#include <iostream>
#include <vector>

#include "song.h"
#include "../PlayWidget/music.h"


/*
 *  Playlist class
 *  Allows to handle the modifications made to the playlist by modifying the content of this object and the database
 *  Allows to get a preview of the playlist
 *
 *  @author: maxime, Binhang Zhu
 */
class Playlist : public QObject {
private:
    Q_OBJECT

public:
    Music *mplayer;

private:
    // Player object

    QString name;
    int playlistId;
    QPixmap cover;
    std::vector<int> songIds; // thus we don't need to load every song when we just need a preview of the playlist
    std::vector<Song> songs;
    QString userName;
    Database* d;

public:
    /*
     * Constructor method
     *
     * @param playlistId: ID of the playlist
     */
    Playlist(int playlistId);
    ~Playlist();

    /*
     * Loads every song contained in the playlist and store them in the vector songs
     */
    void loadSongs();

    std::string getOwner();
    int getId();

    /*
     * Deletes a playlist from the databse
     */

    void deletePlaylist();
    /*
     * Adds songs of the playlist to the queue of the music player
     *
     * @param songIndex: index of the first song to add to the queue
     *                   the songs from songIndex to size-1 will be added to the queue
     */
    void addToQueue(int songIndex = 0);

    /*
     * Adds a song to the playlist
     *
     * @param songId: ID of the song to add
     */
    void addToPlaylist(int songId);

    /*
     * Removes a song from the playlist
     *
     * @param songId: ID of the song to add
     */
    void removeFromPlaylist(int songId);

    void share(int senderId, int receiverId);
    void download();
    void setName(std::string newName);
    void setCover(std::string newCoverPath);

    /*
     * Gets the name of the playlist
     */
    QString getName();

    /*
     * Gets the cover of the playlist
     */
    QPixmap getCover();

    /*
     * Gets the IDs of the songs of the playlist
     */
    std::vector<int> getSongs();

    void show();

    /*
     * Changes the position in the playlist of songs
     *
     * @param position:    initial position of the song to move
     * @param newPosition: new position of the song
     */
    void changeOrder(int position, int newPosition);

    /*
     * Generates a preview of the playlist containing the cover and the name
     *
     * @param parent: parent widget
     * @return:       Layout containing the cover and the name of the playlist
     */
    QLayout* showPreview(QWidget* parent);

    /*
     * Gets the position in the playlist of a song
     *
     * @param songId: ID of the song
     * @return:       position in the playlist of this song
     *                -1 if the song is not in the playlist
     */
    int getSongPos(int songId);

public slots:
    /*
     * Checks that the signal is received
     */
    void onSongFinished();
};


#endif //PROJECT_PLAYLIST_H
