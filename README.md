
# Westernify

Westernify is an innovative music player and library management system, designed to provide an intuitive and comprehensive digital music experience. It integrates advanced software features, including user-friendly playback controls and a sophisticated music database for efficient song and artist searches, as well as the capability for users to upload their own MP3 files. The project also considers the inclusion of hardware elements, specifically a Raspberry Pi kit, to potentially serve as a server for database management and other backend processes. This integration of software with potential hardware support, like the Raspberry Pi kit, is aimed at enhancing the system's performance and reliability, making Westernify a versatile platform for music enthusiasts. The decision to use a departmental Raspberry Pi kit will depend on the final requirements of the system's software architecture and the overall goals of the project.


## Dependencies

- install Qt6 with (can use sudo)
    - source code 
    - QMultimedia library
    - QAudioOutput library
    - QMySQL Driver
- install MySQL

## Instructions
- Run westernify_dump.sql on chosen MySQL account
```
mysql -u root -ppassword <westernify_dump.sql
```
- Update username, password to those chosen by user for MySQL in the database.cpp file
```
db.setHostName("127.0.0.1");
db.setUserName("root"); 
db.setPassword("password");
```
Then do 
```
qmake ./Westernify.pro
```
```
make
```
```
./Westernify
```

## Bugs

- If you do more than one action in the playlist menu the program will crash when you try to go back to main menu

- If you add a new song to the playlist, moving its position immediately after adding will crash the program

- Forgot to change the name of "Chill Vibes" to History. This playlist is the history playlist

- Test functionality with username: crazyfrogger password: 123
