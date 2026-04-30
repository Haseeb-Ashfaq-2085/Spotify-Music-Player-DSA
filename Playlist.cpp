// Playlist.cpp
#include "Playlist.h"
#include <iostream>

Playlist::Playlist() : head(nullptr) {}

void Playlist::addSong(std::string name, std::string artist) {
    Song* newSong = new Song(name, artist);
    newSong->next = head;
    head = newSong;
}

void Playlist::displayPlaylist() {
    Song* temp = head;
    while (temp != nullptr) {
        std::cout << "Song: " << temp->songName << " by " << temp->artist << std::endl;
        temp = temp->next;
    }
}

Playlist::~Playlist() {
    Song* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
