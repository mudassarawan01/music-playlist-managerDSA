#include "LinkedList.h"
Song* linearSearch(LinkedList &playlist, string title) {
    Node* temp = playlist.getHead();
    while (temp != NULL) {
        if (temp->data.title == title) {
            return &temp->data;
        }
        temp = temp->next;
    }
    return NULL;
}

