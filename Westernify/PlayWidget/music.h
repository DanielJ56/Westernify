#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QString> // Include for QString
#include <QDialog> // Include QDialog here
#include <QMediaPlayer>
#include <QAudioOutput>

#include "database.h"
///
/// \brief The Music class is the object that handles the pop up when someone tries to play music
///
/// The music class is called by other classes in the program and is the pop up that contains
/// both the UI elements and the media player elements for playing a piece of music
/// It allows rewind, fast forward,e tc
///
class Music : public QDialog {
    Q_OBJECT

public:
    ///

    explicit Music();
    explicit Music(const int songID, QWidget *parent = nullptr);
    /// \brief Music::addHistory takes in a song, and adds it into the history playlist
    ///
    /// Add History takes in a song and calls the databases function addtoplaylist to add to the
    /// playlist with ID 1, This playlist is the designated history playlist.
    /// @param SongId, the ID of the song being added
    ///
    /// @author Yuan Chun Jiang
    void addHistory(const int &song_id);
    void startPlaying();
private:
    QAudioOutput *audioOutput;
    QMediaPlayer *player;
private:
    ///
    /// \brief d is a database object, necessary for querying the data
    ///
    /// d is used by music.cpp to get songs from database, store songs to playlists in database, etc
    ///
    /// @author Yuan Chun Jiang
    Database *d = new Database();

protected:
    ///
    /// \brief closeEvent is a function that occurs when the window is closed
    ///
    /// closeEvent is necessary to ensure that the QDialog object is properly closed and does not
    /// for instance, keep playing music after it is closed
    /// \param event is the event that signals the closing of the window
    /// @author Yuan Chun Jiang
    void closeEvent(QCloseEvent *event) override;


signals:
    ///
    /// \brief songFinished is a function that is called when a song is finished playing
    ///
    /// It is used to emit signals to alert other processes that the song has finished and that
    /// those processes can start whatever operation they need to perform
    /// @author Yuan Chun Jiang
    void songFinished();

};

#endif
