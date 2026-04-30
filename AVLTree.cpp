// AVLTree.cpp
#include "AVLTree.h"
#include <iostream>
#include <algorithm>

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node* node) {
    return node == nullptr ? 0 : node->height;
}

int AVLTree::balanceFactor(Node* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

AVLTree::Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLTree::Node* AVLTree::insert(Node* node, Song* song) {
    if (node == nullptr) {
        Node* newNode = new Node{song, nullptr, nullptr, 1};
        return newNode;
    }

    if (song->songName < node->song->songName)
        node->left = insert(node->left, song);
    else if (song->songName > node->song->songName)
        node->right = insert(node->right, song);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && song->songName < node->left->song->songName)
        return rotateRight(node);

    if (balance < -1 && song->songName > node->right->song->songName)
        return rotateLeft(node);

    if (balance > 1 && song->songName > node->left->song->songName) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && song->songName < node->right->song->songName) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insertSong(Song* song) {
    root = insert(root, song);
}

void AVLTree::display(Node* node) {
    if (node != nullptr) {
        display(node->left);
        std::cout << node->song->songName << std::endl;
        display(node->right);
    }
}

void AVLTree::display() {
    display(root);
}

AVLTree::~AVLTree() {
    // Memory cleanup is handled by the destructor of each song object.
}
