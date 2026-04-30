// Top10List.h
#ifndef TOP10LIST_H
#define TOP10LIST_H

#include "Song.h"
#include <vector>
#include <algorithm>
#include <iostream>
class Top10List {
private:
    std::vector<Song*> songs;

public:
    void addSong(Song* song);
    void displayTop10();
};

#endif
