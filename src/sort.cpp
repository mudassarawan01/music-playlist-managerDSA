#include "LinkedList.h"

// Bubble sort by title (ascending)
void bubbleSort(LinkedList &playlist) {
    int n = playlist.size();
    if (n <= 1) return;

    for (int i = 0; i < n - 1; i++) {
        Node* curr = playlist.getHead();
        for (int j = 0; j < n - i - 1; j++) {
            Node* next = curr->next;
            if (curr->data.title > next->data.title) {
                // Swap song data
                Song temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }
            curr = curr->next;
        }
    }
}
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data.title < b->data.title) {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    } else {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

void split(Node* head, Node** front, Node** back) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
    if (*back != NULL) (*back)->prev = NULL;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;

    Node* a;
    Node* b;

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

