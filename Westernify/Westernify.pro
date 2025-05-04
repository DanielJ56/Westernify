QT       += core gui
QT       += sql
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddArtist/addartist.cpp \
    PlayWidget/music.cpp\
    LoginMainPage/globle.cpp \
    LoginMainPage/insertlogin.cpp \
    LoginMainPage/mainpage.cpp \
    LoginMainPage/mainwindow.cpp \
    playlist/playlist.cpp \
    playlist/playlistUI.cpp \
    playlist/song.cpp \
    SearchPage/searchresultitem.cpp \
    SearchPage/searchview.cpp \
    UploadFile/uploadfile.cpp \
    database.cpp \
    main.cpp

HEADERS += \
    AddArtist/addartist.h \
    PlayWidget/music.h\
    LoginMainPage/globle.h \
    LoginMainPage/insertlogin.h \
    LoginMainPage/mainpage.h \
    LoginMainPage/mainwindow.h \
    playlist/playlist.h \
    playlist/playlistUI.h \
    playlist/song.h \
    SearchPage/searchresultitem.h \
    SearchPage/searchview.h \
    UploadFile/uploadfile.h \
    database.h

FORMS += \
    AddArtist/addartist.ui \
    LoginMainPage/insertlogin.ui \
    LoginMainPage/mainpage.ui \
    LoginMainPage/mainwindow.ui \
    playlist/playlistUI.ui \
    SearchPage/searchresultitem.ui \
    SearchPage/searchview.ui \
    UploadFile/uploadfile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    testimage.qrc

