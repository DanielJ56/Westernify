/**
 * @file database.h
 * @brief Header for the database class used for sending and retrieving information to and from an SQL database.
 * @author Vlad Krstevski, Binhang Zhu, Daniel Jiang, Weiyi Zeng, Maxime Capdouz
 */
#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QString>
#include <QPixmap>
#include <QVariant>

#include <vector>
#include <iostream>
#include <utility> // std::pair

#define UNKNOWN_ARTIST_ID 1

// Flags for searching
namespace DB {

  /**
    * @brief Enum for flags used in searching the database.
    */
enum Flags {
    TITLES = 0b0001,
    TITLE = 0b0001,
    ARTISTS = 0b0010,
    ARTIST = 0b0010,
    PLAYLISTS = 0b0100,
    PLAYLIST = 0b0100,
    ALBUMS = 0b1000,
    ALBUM = 0b1000,
    ALL = 0b1111,
};

  /**
    * @brief Enum for return codes from database operations.
    */
enum RetCodes {
    DB_SUCCESS          = 0b0001,
    DB_USERNAME_EXISTS  = 0b0010,
    DB_ARTIST_EXISTS    = 0b1000,
    DB_FAILURE          = 0b0100
};
}

/**
* @brief Constructor for the SearchResult struct.
*
* @param type The type of the search result (artist, title, or playlist).
* @param image The image associated with the search result.
* @param str1 The primary string associated with the search result (e.g., artist name, song title, or playlist name).
* @param str2 An optional secondary string associated with the search result (e.g., artist name for a song).
* @param str3 An optional tertiary string associated with the search result (e.g., song file path).
* @param id An optional identifier associated with the search result (e.g., song ID).
*/
struct SearchResult {
    SearchResult(DB::Flags type, QPixmap image, QString str1, QString str2 = NULL, QString str3 = NULL, int id = NULL);
    DB::Flags type;
    QPixmap image;
    QString str1;
    QString str2;
    QString str3;
    int id;
};


class Database
{

private:
    /**
    * @brief Checks if an artist with the given ID exists in the database.
    *
    * This function queries the artist table to check if an artist with the provided ID exists.
    *
    * @param artistID The ID of the artist to check.
    * @return true if the artist exists, false otherwise.
    */
    bool artistExists(int artistID);

public:
    Database();


    /**
    * @brief Establishes a connection to the MySQL database.
    *
    * This function sets up the connection to the MySQL database using the provided credentials
    * and database parameters. It creates a QSqlDatabase object, sets the necessary connection
    * parameters, and attempts to open the connection.
    *
    * @return true if the connection is established successfully, false otherwise.
    */
    bool establish_connection();

    /**
    * @brief Searches the database for matching artists, songs, or playlists.
    *
    * This function does a search based on the provided search string and flags.
    * It queries the artist, song, and playlist tables to find matches based on the specified flags
    * and returns a vector of SearchResult objects containing the matching results.
    *
    * @param sSearch The search string to match against artist names, song titles, or playlist names.
    * @param f Flags indicating which entities to search for (artists, songs, or playlists).
    * @return A vector of SearchResult objects containing the matching results.
    */
    std::vector<SearchResult> searchDatabase(QString sSearch, DB::Flags f = DB::Flags::ALL);

    /**
    * @brief Retrieves the login information (username and password) for all users.
    *
    * This function queries the user table and retrieves the username and password for all users
    * in the database. The username and password pairs are stored in a vector of pairs.
    *
    * @return A vector of pairs, where each pair contains a username and its corresponding password.
    */
    std::vector<std::pair<QString, QString>> retrieveUserLoginInfo();

    /**
    * @brief Signs up a new user by adding their username and password to the database.
    *
    * This function attempts to insert a new user into the user table with the provided username and password.
    * If the username already exists, it returns an error code.
    *
    * @param username The username of the new user.
    * @param password The password of the new user.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the user was added successfully
    *         - DB::DB_USERNAME_EXISTS if the username already exists in the database
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes signUserUp(QString username, QString password);

    /**
    * @brief Adds a new song to the database.
    *
    * This function inserts a new song into the song table with the provided details.
    *
    * @param songName The title of the song.
    * @param year The year the song was released.
    * @param songPath The file path of the song.
    * @param artistid The ID of the artist associated with the song.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the song was added successfully
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes addNewSong(QString songName, int year, QString songPath, int artistid = -1);


    /**
    * @brief Get the songs not in current playlist.
    *
    * This function obtains the songs that are not in the current playlist id.
    *
    * @param playlistId The playlist id of the current playlist.
    * @return a vector of the songs that are not in the current playlist.
    */
    std::vector<int> getSongsNotInPlaylist(int playlistId);//not in playlist songs

    /**
    * @brief Adds a new playlist to the database.
    *
    * This function inserts a new playlist into the playlist table with the provided name, cover path, and user.
    *
    * @param playlistName The name of the playlist.
    * @param coverPath The file path of the playlist cover image.
    * @param userName The username of the user who created the playlist.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the playlist was added successfully
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes addNewPlaylist(QString playlistName, QString coverPath, QString userName);

    /**
    * @brief Deletes a playlist from the database.
    *
    * This function removes a playlist from the playlist and playlist_songs tables based on the provided playlist ID.
    *
    * @param playlistId The ID of the playlist to delete.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the playlist was deleted successfully
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes deletePlaylist(int playlistId);

    /**
    * @brief Adds a song to a playlist.
    *
    * This function adds a song to a playlist in the playlist_songs table.
    *
    * @param playlistId The ID of the playlist to which the song will be added.
    * @param songId The ID of the song to be added.
    * @param songPos The position of the song in the playlist.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the song was added to the playlist successfully
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes addSongToPlaylist(int playlistId, int songId, int pos);

    /**
    * @brief Removes a song from a playlist.
    *
    * This function removes a song from a playlist in the playlist_songs table.
    *
    * @param playlistId The ID of the playlist from which the song will be removed.
    * @param songId The ID of the song to be removed.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the song was removed from the playlist successfully
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes removeSongFromPlaylist(int playlistId, int songId);

    /**
    * @brief Changes the position of a song in a playlist.
    *
    * This function updates the position of a song in a playlist by adjusting the positions of other songs as needed.
    *
    * @param playlistId The ID of the playlist in which the song position will be changed.
    * @param songId The ID of the song whose position will be changed.
    * @param pos The current position of the song in the playlist.
    * @param newPos The new position of the song in the playlist.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the song position was changed successfully
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes changeSongPosition(int playlistId, int songId, int pos, int newPos);

    /**
    * @brief Adds a new artist to the database.
    *
    * This function inserts a new artist into the artist table with the provided name and date of birth.
    * If the artist already exists, it returns an appropriate error code.
    *
    * @param artistName The name of the artist.
    * @param dateOfBirth The date of birth of the artist.
    * @return A DB::RetCodes value indicating the success or failure of the operation:
    *         - DB::DB_SUCCESS if the artist was added successfully
    *         - DB::DB_ARTIST_EXISTS if the artist already exists in the database
    *         - DB::DB_FAILURE if there was an error during the operation
    */
    DB::RetCodes addNewArtist(QString artistName, QString date);

    /**
    * @brief Checks if a song is present in a playlist.
    *
    * This function checks if a song with the given ID is present in a playlist with the specified ID.
    *
    * @param playlistId The ID of the playlist to check.
    * @param songId The ID of the song to check.
    * @return true if the song is present in the playlist, false otherwise.
    */
    bool isSonginPlaylist(int playlistId, int songId);

    /**
    * @brief Retrieves the list of songs in a playlist.
    *
    * This function retrieves the IDs of all songs present in a playlist with the specified ID.
    *
    * @param playlistId The ID of the playlist.
    * @return A vector containing the IDs of the songs in the playlist.
    */
    std::vector<int> getPlaylistSongs(int playlistId);


    /**
    * @brief Retrieves the list of playlists for a user.
    *
    * This function retrieves the IDs of all playlists belonging to a user with the specified username.
    *
    * @param userName The username of the user.
    * @return A vector containing the IDs of the user's playlists.
    */
    std::vector<int> getUserPlaylists(QString userName);


    /**
    * @brief Retrieves the cover image of a playlist.
    *
    * @param playlistId The ID of the playlist.
    * @return The cover image of the playlist.
    */
    QPixmap getCover(int playlistId);

    /**
    * @brief Retrieves the name of a playlist.
    *
    * @param playlistId The ID of the playlist.
    * @return The name of the playlist.
    */
    QString getPlaylistName(int playlistId);

    /**
    * @brief Retrieves the artist name of a song.
    *
    * @param songId The ID of the song.
    * @return The name of the artist associated with the song.
    */
    QString getSongArtist(int songId);

    /**
    * @brief Retrieves the title of a song.
    *
    * @param songId The ID of the song.
    * @return The title of the song.
    */
    QString getSongTitle(int songId);

    /**
    * @brief Retrieves the file path of a song.
    *
    * @param songId The ID of the song.
    * @return The file path of the song.
    */
    QString getSongPath(int songId);

    /**
    * @brief Retrieves the artistid of an artist.
    *
    * @param artistName The name of the artist.
    * @return The artist id.
    */
    int getArtistId(QString artistName);


    /**
    * @brief Retrieves the user image (profile picture) for a given username.
    *
    * @param username The username of the user.
    * @return The user image (profile picture) associated with the username.
    */
    QPixmap getUserImage(QString username);
};

#endif // DATABASE_H
