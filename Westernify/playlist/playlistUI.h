#ifndef PLAYLISTUI_H
#define PLAYLISTUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <sys/stat.h>
#include <filesystem>
#include <QGridLayout>
#include <QScrollArea>

#include "playlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class playlistUI;
}
QT_END_NAMESPACE

/*
 * Playlist UI class
 * Handles the playlist window
 * Allows to create, delete and modify playlists
 *
 *  @author: maxime, Binhang Zhu
 */
class playlistUI : public QMainWindow
{
    Q_OBJECT

public:
    /*
     * Constructor method
     *
     * @param parent:   parent widget
     * @param userName: name of the user
     */
    playlistUI(QWidget *parent, QString userName);
    ~playlistUI();

    /*
     * Get the playlists
     */
    std::vector<Playlist*> *getPlaylists();

signals:
    void pageIsFinished();

private slots:
    void goBack();

    /*
     * Goes back to the main page
     */
    void on_goBackButton_clicked();
private:
    Ui::playlistUI *ui;
    std::vector<Playlist *> *playlists;

    /*
     * name of the user currently connected
     */
    QString userName;

    /*
     * Reference to the database
     */
    Database *d;
    
    /*
     *  Opens a popup window to select the name and cover of the new playlist
     */
    void createPlaylistPopup();

    /*
     * Opens a window containing all the playlists created by the user
     */
    void showPlaylists();

    /*
     * Sets up the images and songs folder
     */
    void setupFolders();

    /*
     * Open a window containing the songs of a playlist, allows to modify a playlist
     *
     * @param playlistId: ID of the playlist to show
     * @return:           0: no modification; 1: content modified; 2: playlist deleted
     */
    int showPlaylist(int playlistId);

    /*
     * Opens a window that allows to select a song that is not in the playlist to add it to the playlist
     *
     * @param playlistId: ID of the playlist
     * @return:           ID of the song selected
     */
    int selectSong(int playlistId);
};
#endif // PLAYLISTUI_H
