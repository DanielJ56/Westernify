#include "database.h"
#include <iostream>
Database::Database() {}

SearchResult::SearchResult(DB::Flags type, QPixmap image, QString str1, QString str2, QString str3, int id) : type(type), image(image), str1(str1), str2(str2), str3(str3), id(id) {}



bool Database::establish_connection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Replace with your database host
    db.setPort(3306); // Default MySQL/MariaDB port
    db.setDatabaseName("Westernify"); // Replace with your database name
    db.setUserName("root"); // Replace with your database username
    db.setPassword("password"); // Replace with your database password

    if (!db.open()) {
        std::cerr << "Error connecting to database. Are your credentials correct? Error trace:\n" << db.lastError().text().toStdString() << std::endl;
        return false;
    }

    std::cout << "Database connection established!" << std::endl;

    return true;
}

std::vector<SearchResult> Database::searchDatabase(QString sSearch, DB::Flags f) {
    std::vector<SearchResult> res;


    if (f & DB::ARTIST) {
        // Add artists with matching names
        QSqlQuery query("SELECT * FROM artist WHERE name LIKE \"%" + sSearch + "%\";");
        while (query.next()) {
            QByteArray bimage = query.value("image").toByteArray();
            QPixmap image;
            image.loadFromData(bimage);

            QString str1 = query.value("name").toString();

            res.push_back(SearchResult(DB::ARTIST, image, str1));
        }
    }

    if (f & DB::TITLE) {
        // Add matching songs
        QSqlQuery query("SELECT song.title, artist.name, song.image, song.filepath, song.songid FROM song JOIN artist ON song.artistid=artist.artistid WHERE song.title LIKE \"%" + sSearch + "%\";");
        while (query.next()) {
            QByteArray bimage = query.value("image").toByteArray();
            QPixmap image;
            image.loadFromData(bimage);

            QString str1 = query.value("song.title").toString();

            QString str2 = query.value("artist.name").toString();

            QString str3 = query.value("song.filepath").toString();

            int id = query.value("song.songid").toInt();

            res.push_back(SearchResult(DB::TITLE, image, str1, str2, str3, id));
        }

        // Add songs based on artist name
        QSqlQuery query2("SELECT s.title, a.name, s.image, s.filepath, s.songid FROM artist a JOIN song s ON s.artistid=a.artistid WHERE a.name LIKE \"%" + sSearch + "%\";");
        while (query2.next()) {
            QByteArray bimage2 = query2.value("image").toByteArray();
            QPixmap image2;
            image2.loadFromData(bimage2);

            QString str12 = query2.value("s.title").toString();
            QString str22 = query2.value("a.name").toString();
            QString str32 = query2.value("s.filepath").toString();

            int id2 = query2.value("s.songid").toInt();

            res.push_back(SearchResult(DB::TITLE, image2, str12, str22, str32, id2));
        }
    }

    if (f & DB::PLAYLIST) {
        QSqlQuery query("SELECT playlist.playlistname, playlist.image FROM playlist WHERE playlist.playlistname LIKE \"%" + sSearch + "%\";");
        while (query.next()) {
            QByteArray bimage = query.value("image").toByteArray();
            QPixmap image;
            image.loadFromData(bimage);

            QString str1 = query.value("playlistname").toString();

            res.push_back(SearchResult(DB::PLAYLIST, image, str1));
        }
    }





    return res;
};


std::vector<std::pair<QString, QString>> Database::retrieveUserLoginInfo() {

    std::vector<std::pair<QString, QString>> logininfo;

    QSqlQuery query("SELECT username, password FROM user;");

    while (query.next()) {
        QString usr = query.value("username").toString();
        QString pwd = query.value("password").toString();

        logininfo.push_back(std::make_pair(usr, pwd));
    }

    return logininfo;
}



DB::RetCodes Database::signUserUp(QString username, QString password) {


    QSqlQuery query;

    query.prepare("INSERT INTO user (username, password) VALUES (:username, :password);");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        // Check if the error is due to a unique constraint violation (username already exists)
        QSqlError error = query.lastError();

        // Check for constant violation code
        if (error.nativeErrorCode().contains("1062")) {
            return DB::DB_USERNAME_EXISTS;
        } else {
            std::cerr << "Database error:" << error.text().toStdString();
            return DB::DB_FAILURE;
        }
    }

    return DB::DB_SUCCESS;
}


DB::RetCodes Database::addNewSong(QString songName, int year, QString songPath, int artistid) {

    QSqlQuery query;

    QString queryInsert = "INSERT INTO song (title, datereleased, filepath, artistid) VALUES (:songName, :year, :songPath, :artistID)";

    query.prepare(queryInsert);
    query.bindValue(":songName", songName);
    query.bindValue(":year", QString::number(year) + "-11-11");
    query.bindValue(":songPath", songPath);

    // Handle the case where no artist is specified for a given song
    if (artistid == -1) {
        // TODO: add some sort of deafult artist or remove foreign key dependancy
        artistid = UNKNOWN_ARTIST_ID;
    }

    query.bindValue(":artistID", artistid);

    if (artistExists(artistid)) {
        // Artist exists, we can add the song
        if (!query.exec())
            // Uncaptured failure, should not happen
            std::cerr << "Error executing query: " << query.lastError().text().toStdString() << std::endl;
        else
            // Sucess
            return DB::DB_SUCCESS;
    }

    return DB::DB_FAILURE;
}


int Database::getArtistId(QString artistName){
    QSqlQuery q("SELECT artistid FROM artist WHERE name =\"" + artistName + "\";");
    //q.bindValue(":artistName", artistName);
    if (!q.exec()) {
        qDebug() << "Error retrieving artist ID:" << q.lastError();
        return -1; // Indicate failure
    }
    // 5. Check if the artist was found
    if (q.next()) {
        // Artist found, return the ID
        return q.value(0).toInt();
    } else {
        // Artist not found, log a message and return -1
        qDebug() << "Artist not found:" << artistName;
        return -1;
    }
}


DB::RetCodes Database::addNewArtist(QString artistName, QString dateOfBirth) {
    //Check if the artist already exists
    QSqlQuery query;
    query.prepare("SELECT artistid FROM artist WHERE name = :artistName");
    query.bindValue(":artistName", artistName);

    if (!query.exec()) {
        qDebug() << "Error checking for existing artist:" << query.lastError();
        return DB::DB_FAILURE;
    }

    if (query.next()) {
        // Artist exists
        return DB::DB_ARTIST_EXISTS;
    }

    // 2. Insert the new artist
    query.prepare("INSERT INTO artist (name, dateofbirth) VALUES (:artistName, :dateOfBirth)");
    query.bindValue(":artistName", artistName);
    query.bindValue(":dateOfBirth", dateOfBirth);

    if (!query.exec()) {
        qDebug() << "Error inserting new artist:" << query.lastError();
        return DB::DB_FAILURE;
    }

    return DB::DB_SUCCESS;
}


bool Database::artistExists(int artistID) {
    // Check if artist with provided ID exists
    QSqlQuery q("SELECT 1 FROM artist WHERE artistid = " + QString::number(artistID) + ";");
    bool ok = q.exec();

    return (ok && q.next());
}


DB::RetCodes Database::addNewPlaylist(QString playlistName, QString coverPath, QString userName) {
    QSqlQuery q;
    q.prepare("INSERT INTO playlist (playlistname, image, user) VALUES (:playlistName, :coverPath, :userName)");
    q.bindValue(":playlistName", playlistName);
    q.bindValue(":coverPath", coverPath);
    q.bindValue(":userName", userName);

    if (!q.exec()) { qDebug() << "error while adding new playlist: " << q.lastError(); return DB::DB_FAILURE; }
    return DB::DB_SUCCESS;
}

DB::RetCodes Database::deletePlaylist(int playlistId) {
    QSqlQuery q;
    q.prepare("DELETE FROM playlist_songs WHERE playlistid = :playlistid");
    q.bindValue(":playlistid", playlistId);

    if (!q.exec()) { qDebug() << "error while deleting playlist: " << q.lastError(); return DB::DB_FAILURE; }
    return DB::DB_SUCCESS;
}

DB::RetCodes Database::addSongToPlaylist(int playlistId, int songId, int songPos) {
    QString str = "INSERT INTO playlist_songs VALUES ("+ QString::number(playlistId) + "," + QString::number(songId) +",\"2024-03-06 00:00:00\");";
    QSqlQuery q(str);
    //q.bindValue(":playlistid", QString::number(playlistId));
    // q.bindValue(":songid", QString::number(songId));
    //q.bindValue(":pos", QString::number(songPos));

    if (!q.exec()) { qDebug() << "error while adding song to playlist: " << q.lastError(); return DB::DB_FAILURE; }
    return DB::DB_SUCCESS;
}

DB::RetCodes Database::removeSongFromPlaylist(int playlistId, int songId) {
    QString str = "DELETE FROM playlist_songs WHERE playlistid ="+ QString::number(playlistId)+" AND songid =" +QString::number(songId)+";";
    qDebug() << str;
    QSqlQuery q(str);
    //q.bindValue(":playlistid", QString::number(playlistId));
    //q.bindValue(":songid", QString::number(songId));

    if (!q.exec()) { qDebug() << "error while deleting song from playlist" << q.lastError(); return DB::DB_FAILURE; }
    return DB::DB_SUCCESS;
}

DB::RetCodes Database::changeSongPosition(int playlistId, int songId, int pos, int newPos) {
    QSqlQuery query;
    QString command = "UPDATE playlist_song SET pos = :newpos WHERE playlistid = :playlistid AND pos = :pos;";

    if (pos < newPos) {
        for (int i = newPos; i > pos; i--) {
            query.prepare(command);
            query.bindValue(":newpos", QString::number(i - 1));
            query.bindValue(":playlistid", QString::number(playlistId));
            query.bindValue(":pos", QString::number(i));

            if (!query.exec()) { qDebug() << "error changing song pos: " << query.lastError(); return DB::DB_FAILURE; }
        }
    }
    else {
        for (int i = newPos; i < pos; i++) {
            query.prepare(command);
            query.bindValue(":newpos", QString::number(i + 1));
            query.bindValue(":playlistid", QString::number(playlistId));
            query.bindValue(":pos", QString::number(i));

            if (!query.exec()) { qDebug() << "error changing song pos: " << query.lastError(); return DB::DB_FAILURE; }
        }
    }

    query.prepare("UPDATE playlist_song SET pos = :newpos WHERE playlistid = :playlistid AND pos = :pos AND songid = :songid;");
    query.bindValue(":newpos", QString::number(newPos));
    query.bindValue(":playlistid", QString::number(playlistId));
    query.bindValue(":pos", QString::number(pos));
    query.bindValue(":songid", QString::number(songId));

    if (!query.exec()) { qDebug() << "error changing song pos: " << query.lastError(); return DB::DB_FAILURE; }

    return DB::DB_SUCCESS;
}

bool Database::isSonginPlaylist(int playlistId, int songId) {
    QSqlQuery q("SELECT 1 FROM playlist_songs WHERE playlistid = :playlistid AND songid = :songid ;");
    q.bindValue(":playlistid", QString::number(playlistId));
    q.bindValue("songid", QString::number(songId));

    if (!q.exec()) { qDebug() << "error while checking if song in playlist: " << q.lastError(); return false; }

    return (q.next());
}

std::vector<int> Database::getPlaylistSongs(int playlistId) {
    QString str = "SELECT songId FROM playlist_songs WHERE playlistId =\"" + QString::number(playlistId) + "\";";
    QSqlQuery q(str);
    //q.bindValue(":playlisid", QString::number(playlistId));
    std::vector<int> songIds;

    if (!q.exec()) { qDebug() << "error while getting playlist songs: " << q.lastError(); return songIds; }

    while (q.next()) songIds.push_back(q.value(0).toInt());

    return songIds;
}

std::vector<int> Database::getUserPlaylists(QString userName) {
    QString str = "SELECT playlistid from playlist WHERE user =\"" + userName + "\";";
    QSqlQuery q(str);
    std::vector<int> playlistIds;

    if (!q.exec()) { qDebug() << "error while getting user's playlists: " << q.lastError(); return playlistIds; }

    while (q.next()) {
        playlistIds.push_back(q.value(0).toInt()) ;
    }

    return playlistIds;
}

QString Database::getSongTitle(int songId) {
    QSqlQuery q("SELECT title FROM song WHERE songid = " + QString::number(songId) + ";");
    if (!q.exec()) { qDebug() << "error while getting song title: " << q.lastError(); return ""; }

    q.next();
    return q.value(0).toString();
}

QString Database::getSongPath(int songId) {
    QSqlQuery q("SELECT filepath FROM song WHERE songid = " + QString::number(songId) + ";");

    std::cerr << "SELECT filepath FROM song WHERE songid = " + QString::number(songId).toStdString() + ";";

    if (!q.exec()) { qDebug() << "error while getting song file path: " << q.lastError(); return ""; }

    q.next();
    return q.value(0).toString();
}

QString Database::getSongArtist(int songId) {
    QSqlQuery q("SELECT artist.name FROM song JOIN artist ON song.artistid=artist.artistid WHERE song.songid = " + QString::number(songId) + ";");
    if (!q.exec()) { qDebug() << "error while gettting song artist: " << q.lastError(); return ""; }

    q.next();
    return q.value(0).toString();
}

QString Database::getPlaylistName(int playlistId) {
    QSqlQuery q("SELECT playlistname FROM playlist WHERE playlistid = " + QString::number(playlistId) + ";");
    if (!q.exec()) { qDebug() << "error while getting playlist name: " << q.lastError(); return ""; }

    q.next();
    return q.value(0).toString();
}

QPixmap Database::getCover(int playlistId) {
    QSqlQuery q("SELECT image FROM playlist WHERE playlistid = " + QString::number(playlistId) + ";");
    QPixmap image;

    if (!q.exec()) { qDebug() << "error while getting playlist cover: " << q.lastError(); return image; }

    QByteArray bimage = q.value("image").toByteArray();
    image.loadFromData(bimage);
    return image;
}

QPixmap Database::getUserImage(QString username) {
    QSqlQuery q;
    QPixmap image;

    q.prepare("SELECT image FROM user WHERE username=:username;");

    q.bindValue(":username", username);

    if (!q.exec()) { qDebug() << "error while getting user image: " << q.lastError(); }

    q.next();
    QByteArray bimage = q.value(0).toByteArray();

    if (!bimage.isNull()) {
        image.loadFromData(bimage);
        return image;
    } else {
        return QPixmap(":/res/default.png");
    }
}


std::vector<int> Database::getSongsNotInPlaylist(int playlistId) {
    QSqlQuery q(("SELECT song.songid FROM song WHERE song.songid NOT IN (SELECT songId FROM playlist_songs WHERE playlistId = " +
                 QString::number(playlistId) + ");"));
    std::vector<int> songIds;

    if (!q.exec()) { qDebug() << "error while getting playlist songs: " << q.lastError(); return songIds; }

    while (q.next()) songIds.push_back(q.value(0).toInt());

    return songIds;
}

