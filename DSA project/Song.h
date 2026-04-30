// Song.h
#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
class Song {
public:
    std::string songName;
    std::string artist;
    int playCount;  // Used for sorting in the top 10 list
    Song* next;

    Song(std::string name, std::string artist_name);
    ~Song();
};

#endif
