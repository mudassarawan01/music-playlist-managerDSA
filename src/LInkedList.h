#pragma once
#include "Song.h"

class Node {
public:
    Song data;
    Node* next;
    Node* prev;

    Node(Song s); // declaration only
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList();
    void addSong(Song s);
    bool removeSong(int id);
    void displayAll();
    int size();
    Node* getHead();
    void setHead(Node* h);
};

