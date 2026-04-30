// Playlist.h
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <iostream>
class Playlist {
private:
    Song* head;

public:
    Playlist();
    void addSong(std::string name, std::string artist);
    void displayPlaylist();
    ~Playlist();
};

#endif
