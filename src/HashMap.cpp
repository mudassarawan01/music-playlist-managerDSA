#include "HashMap.h"

HashEntry::HashEntry(string _key, Song _value) {
    key = _key;
    value = _value;
}

int HashMap::hashFunction(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
    sum += key[i];

    return sum % TABLE_SIZE;
}

HashMap::HashMap() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

void HashMap::insert(string key, Song value) {
    int index = hashFunction(key);
    while (table[index] != NULL && table[index]->key != key) {
        index = (index + 1) % TABLE_SIZE;
    }
    if (table[index] != NULL) delete table[index];
    table[index] = new HashEntry(key, value);
}

Song* HashMap::search(string key) {
    int index = hashFunction(key);
    int start = index;
    while (table[index] != NULL) {
        if (table[index]->key == key)
            return &table[index]->value;
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }
    return NULL;
}

void HashMap::remove(string key) {
    int index = hashFunction(key);
    int start = index;
    while (table[index] != NULL) {
        if (table[index]->key == key) {
            delete table[index];
            table[index] = NULL;
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }
}

