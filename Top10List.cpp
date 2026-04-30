// Top10List.cpp
#include "Top10List.h"
#include <iostream>
#include <algorithm>

void Top10List::addSong(Song* song) {
    songs.push_back(song);
    std::sort(songs.begin(), songs.end(), [](Song* a, Song* b) {
        return a->playCount > b->playCount;
    });
    if (songs.size() > 10) {
        songs.pop_back(); // Keep only top 10 songs
    }
}

void Top10List::displayTop10() {
    std::cout << "Top 10 Songs:" << std::endl;
    for (auto& song : songs) {
        std::cout << song->songName << " by " << song->artist << " | Play count: " << song->playCount << std::endl;
    }
}
