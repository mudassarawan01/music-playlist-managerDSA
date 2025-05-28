#pragma once
#include <iostream>
using namespace std;

class Song {
public:
    int id;
    string title;
    string artist;
    float duration;
    string genre;

    Song();
    Song(int _id, string _title, string _artist, float _duration, string _genre);
    void display();
};

