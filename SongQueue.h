// SongQueue.h
#ifndef SONGQUEUE_H
#define SONGQUEUE_H

#include "Song.h"
#include <vector>
#include <iostream>
class SongQueue {
private:
    std::vector<Song*> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void addSongToQueue(Song* song);
    Song* popSongFromQueue();
};

#endif
