#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(Song s) {
    data = s;
    next = NULL;
    prev = NULL;
}

LinkedList::LinkedList() {
    head = tail = NULL;
    count = 0;
}

void LinkedList::addSong(Song s) {
    Node* newNode = new Node(s);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

bool LinkedList::removeSong(int id) {
    Node* temp = head;
    while (temp) {
        if (temp->data.id == id) {
            if (temp == head) head = head->next;
            if (temp == tail) tail = tail->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
            count--;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::displayAll() {
    Node* temp = head;
    while (temp) {
        temp->data.display();
        temp = temp->next;
    }
}

int LinkedList::size() {
    return count;
}

Node* LinkedList::getHead() {
    return head;
}

void LinkedList::setHead(Node* h) {
    head = h;
}

