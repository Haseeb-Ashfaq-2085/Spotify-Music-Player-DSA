// SongQueue.cpp
#include "SongQueue.h"
#include <iostream>

void SongQueue::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index]->songName < heap[parent]->songName) {
        std::swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void SongQueue::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild]->songName < heap[smallest]->songName)
        smallest = leftChild;
    if (rightChild < heap.size() && heap[rightChild]->songName < heap[smallest]->songName)
        smallest = rightChild;

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void SongQueue::addSongToQueue(Song* song) {
    heap.push_back(song);
    heapifyUp(heap.size() - 1);
}

Song* SongQueue::popSongFromQueue() {
    if (heap.empty()) return nullptr;

    Song* song = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return song;
}
