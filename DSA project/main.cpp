#include <iostream>
#include <string>
#include "User.h"
#include "Playlist.h"
#include "AVLTree.h"
#include "SongQueue.h"
#include "Settings.h"
#include "Top10List.h"

void displayMenu() {
    std::cout << "==========================================" << std::endl;
    std::cout << "      Welcome to Spotify Music Player     " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "1. Authenticate User" << std::endl;
    std::cout << "2. Create a Playlist" << std::endl;
    std::cout << "3. View Playlist" << std::endl;
    std::cout << "4. Add Song to AVL Tree (Sorted Library)" << std::endl;
    std::cout << "5. Display Sorted Song Library" << std::endl;
    std::cout << "6. Add Song to Queue" << std::endl;
    std::cout << "7. Play Next Song from Queue" << std::endl;
    std::cout << "8. View Top 10 Songs" << std::endl;
    std::cout << "9. Access Settings" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    // Authentication setup
    User user("user@example.com", "password123");

    // Components
    Playlist playlist;
    AVLTree songLibrary;
    SongQueue songQueue;
    Top10List top10;
    Settings* settings = Settings::getInstance();

    bool authenticated = false;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Authenticate User
                std::string email, password;
                std::cout << "Enter email: ";
                std::cin >> email;
                std::cout << "Enter password: ";
                std::cin >> password;

                if (user.authenticate(email, password)) {
                    std::cout << "Authentication Successful!" << std::endl;
                    authenticated = true;
                } else {
                    std::cout << "Invalid credentials. Please try again." << std::endl;
                }
                break;
            }
            case 2: {
                // Add song to playlist
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                std::string songName, artist;
                std::cout << "Enter song name: ";
                std::cin.ignore();
                std::getline(std::cin, songName);
                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);

                playlist.addSong(songName, artist);
                std::cout << "Song added to playlist!" << std::endl;
                break;
            }
            case 3: {
                // View playlist
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                playlist.displayPlaylist();
                break;
            }
            case 4: {
                // Add song to AVL Tree
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                std::string songName, artist;
                std::cout << "Enter song name: ";
                std::cin.ignore();
                std::getline(std::cin, songName);
                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);

                Song* newSong = new Song(songName, artist);
                songLibrary.insertSong(newSong);
                top10.addSong(newSong); // Add to top 10 list
                std::cout << "Song added to library!" << std::endl;
                break;
            }
            case 5: {
                // Display AVL Tree
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                songLibrary.display();
                break;
            }
            case 6: {
                // Add song to queue
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                std::string songName, artist;
                std::cout << "Enter song name: ";
                std::cin.ignore();
                std::getline(std::cin, songName);
                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);

                Song* newSong = new Song(songName, artist);
                songQueue.addSongToQueue(newSong);
                std::cout << "Song added to queue!" << std::endl;
                break;
            }
            case 7: {
                // Play next song
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                Song* nextSong = songQueue.popSongFromQueue();
                if (nextSong) {
                    std::cout << "Now playing: " << nextSong->songName << " by " << nextSong->artist << std::endl;
                } else {
                    std::cout << "Queue is empty!" << std::endl;
                }
                break;
            }
            case 8: {
                // View top 10 songs
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                top10.displayTop10();
                break;
            }
            case 9: {
                // Access settings
                if (!authenticated) {
                    std::cout << "Please authenticate first!" << std::endl;
                    break;
                }
                settings->displaySettings();
                break;
            }
            case 10: {
                // Exit
                std::cout << "Thank you for using Spotify Music Player. Goodbye!" << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
