#pragma once
#include "Song.h"

const int TABLE_SIZE = 100;

class HashEntry {
public:
    string key;
    Song value;

    HashEntry(string _key, Song _value);
};

class HashMap {
private:
    HashEntry* table[TABLE_SIZE];
    int hashFunction(string key);

public:
    HashMap();
    void insert(string key, Song value);
    Song* search(string key);
    void remove(string key);
};

