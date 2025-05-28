#include "Song.h"

Song::Song() {}

Song::Song(int _id, string _title, string _artist, float _duration, string _genre) {
    id = _id;
    title = _title;
    artist = _artist;
    duration = _duration;
    genre = _genre;
}

void Song::display() {
    cout << "ID: " << id
         << " | Title: " << title
         << " | Artist: " << artist
         << " | Duration: " << duration << " mins"
         << " | Genre: " << genre << endl;
}

