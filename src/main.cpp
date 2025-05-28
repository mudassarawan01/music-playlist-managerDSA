#include <iostream>
#include <string>
#include "LinkedList.h"
#include "HashMap.h"

// Forward declarations of external functions
void bubbleSort(LinkedList &playlist);
void mergeSort(Node** headRef);
Song* linearSearch(LinkedList &playlist, string title);

using namespace std;

int main() {
    LinkedList playlist;
    HashMap songMap;

    int choice;
    int songIdCounter = 1;

    while (true) {
        cout << "\n=== Music Playlist Manager ===\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. View Playlist\n";
        cout << "4. Sort Playlist (Bubble Sort)\n";
        cout << "5. Sort Playlist (Merge Sort)\n";
        cout << "6. Search Song (Linear Search)\n";
        cout << "7. Search Song (HashMap Lookup)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting... Thanks for using Playlist Manager!\n";
            break;
        }

        switch (choice) {
            case 1: {
                cin.ignore();
                string title, artist, genre;
                float duration;

                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter duration (in mins): ";
                cin >> duration;
                cin.ignore();
                cout << "Enter genre: ";
                getline(cin, genre);

                Song newSong(songIdCounter++, title, artist, duration, genre);
                playlist.addSong(newSong);
                songMap.insert(title, newSong);

                cout << "Song added successfully!\n";
                break;
            }

            case 2: {
                int id;
                cout << "Enter song ID to delete: ";
                cin >> id;
                if (playlist.removeSong(id)) {
                    cout << "Song deleted from playlist.\n";
                } else {
                    cout << "Song not found.\n";
                }
                break;
            }

            case 3: {
                cout << "\n--- Playlist ---\n";
                playlist.displayAll();
                break;
            }

            case 4: {
                bubbleSort(playlist);
                cout << "Playlist sorted using Bubble Sort.\n";
                break;
            }

            case 5: {
                Node* head = playlist.getHead();
                mergeSort(&head);
                cout << "Playlist sorted using Merge Sort.\n";
                break;
            }

            case 6: {
                cin.ignore();
                string title;
                cout << "Enter song title to search (Linear): ";
                getline(cin, title);
                Song* result = linearSearch(playlist, title);
                if (result != NULL) {
                    cout << "Song found:\n";
                    result->display();
                } else {
                    cout << "Song not found.\n";
                }
                break;
            }

            case 7: {
                cin.ignore();
                string title;
                cout << "Enter song title to search (HashMap): ";
                getline(cin, title);
                Song* result = songMap.search(title);
                if (result != NULL) {
                    cout << "Song found:\n";
                    result->display();
                } else {
                    cout << "Song not found.\n";
                }
                break;
            }

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

