// Song.cpp
#include "Song.h"
#include <iostream>
Song::Song(std::string name, std::string artist_name)
    : songName(name), artist(artist_name), playCount(0), next(nullptr) {}

Song::~Song() {
    std::cout << "Song: " << songName << " deleted!" << std::endl;
}
