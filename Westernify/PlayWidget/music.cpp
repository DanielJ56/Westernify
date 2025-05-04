#include "music.h"
#include <QGridLayout>
#include <QDialog> // Include QDialog here
#include <QMediaPlayer>
#include <QPushButton>
#include <QAudioOutput>
#include <QProgressBar>
#include <iostream>

Music::Music() {};

void Music::addHistory(const int &song_id) {
    //add to history function, takes in songid and calls  add to song to add to database

    d->addSongToPlaylist(1,song_id,23);
}

Music::Music(const int songID, QWidget *parent)  : QDialog(parent) {
    //setup UI, and title
    setWindowTitle("Music Player");

    std::cerr << "Trying to create player with song id: " << songID;

    resize(200, 200);
    //create a media player object for playing music
    player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput;
    this->player->setAudioOutput(audioOutput);

    //init database and get the path from the SONG ID
    if (!d->establish_connection())
        std::cerr << "Issue connecting to database" << std::endl;
    //get the song path from the database
    QString path = d->getSongPath(songID);
    std::cerr <<"song path is: "<<std::endl;
    std::cerr << path.toStdString();
    //set the source for when we want to play
    this->player->setSource(QUrl::fromLocalFile(path));

    //create rewind and play buttons, format them as well
    QPushButton *playButton = new QPushButton("Play", this);
    QPushButton *pauseButton = new QPushButton("Pause", this);

    playButton->setStyleSheet("QPushButton { color: black; }");
    pauseButton->setStyleSheet("QPushButton { color: black; }");

    //connect these buttons so they perform their intended functions
    connect(playButton, &QPushButton::clicked, player, &QMediaPlayer::play);

    connect(playButton, &QPushButton::clicked, this, [this, songID]() {
        //if a user plays a song, also add it to history
        addHistory(songID);
    });
    connect(pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);

    //add the buttons to the UI
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(playButton, 0, 0);
    layout->addWidget(pauseButton, 0, 1);

    //create and setup a progress bar
    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    
    connect(player, &QMediaPlayer::positionChanged, this, [progressBar](qint64 position) {
        //if the mediaplayer has change position, change the value of the progress bar
        progressBar->setValue(position);
    });

    connect(player, &QMediaPlayer::durationChanged, this, [progressBar](qint64 duration) {
        //set the max of the progress bar to the max duration
        progressBar->setMaximum(duration);
    });

    connect(player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState newState) {
        //emit signal for other processes if the song is finished
        if (newState == QMediaPlayer::StoppedState) {
            emit songFinished();
            std::cerr << "Song finished singla emitted";
        }
    });

    //add progress bar to UI
    layout->addWidget(progressBar, 1, 0, 1, 2);  // Span the progress bar across both columns

    //create rewind and fastforward buttons
    QPushButton *rewindButton = new QPushButton("Rewind 10s", this);
    rewindButton->setStyleSheet("QPushButton { color: black; }");
    QPushButton *fastForwardButton = new QPushButton("Fast Forward 10s", this);
    fastForwardButton->setStyleSheet("QPushButton { color: black; }");


    // Connect the button's clicked signal to a lambda that rewinds the song by 10 seconds
    connect(rewindButton, &QPushButton::clicked, this, [this]() {
        qint64 position = this->player->position();
        position -= 10000;  // Rewind by 10,000 milliseconds (10 seconds)
        if (position < 0) position = 0;  // Don't go past the start of the song
        this->player->setPosition(position);
    });

    connect(fastForwardButton, &QPushButton::clicked, this, [this]() {
        qint64 position = this->player->position();
        position += 10000;  // Fast forward by 10,000 milliseconds (10 seconds)
        if (position > this->player->duration()) position = this->player->duration();  // Don't go past the end of the song
        this->player->setPosition(position);
    });

    // Add the rewind/fastforward button to the layout and style the background
    layout->addWidget(rewindButton, 0, 2);
    layout->addWidget(fastForwardButton, 0, 3);
    this->setStyleSheet("background-color: white;");
    setLayout(layout);

}

void Music::startPlaying() {
    //start playing the song
    if(player) {
        player->play();
    }
}

void Music::closeEvent(QCloseEvent *event) {
    //on close, stop playing the song
    if (player != nullptr) {
    
        player->stop();
    }
}
