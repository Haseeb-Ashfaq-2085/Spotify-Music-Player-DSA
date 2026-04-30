// AVLTree.h
#ifndef AVLTREE_H
#define AVLTREE_H

#include "Song.h"
#include <iostream>

class AVLTree {
private:
    struct Node {
        Song* song;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, Song* song);
    void display(Node* node);

public:
    AVLTree();
    void insertSong(Song* song);
    void display();
    ~AVLTree();
};

#endif
