#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Song {
public:
    string title;
    string artist;

    Song(const string& t, const string& a) : title(t), artist(a) {}
};

class Playlist {
private:
    vector<Song> songs;

public:
    void addSong(const Song& song) {
        songs.push_back(song);
        cout << "Added " << song.title << " by " << song.artist << " to the playlist." << endl;
    }
};

class User {
public:
    string username;
    Playlist playlist;

    User(const string& name) : username(name) {}
};

class MusicStreamingService {
private:
    vector<User> users;

public:
    void addUser(const User& user) {
        users.push_back(user);
    }

    void recommendSong(User* user, const Song& song) const {
        cout << "Recommendation for " << user->username << ": Listen to " << song.title << " by " << song.artist << endl;
    }
};

int main() {
    MusicStreamingService musicService;

    User user1("Alice");
    User user2("Bob");

    musicService.addUser(user1);
    musicService.addUser(user2);

    Song song1("Shape of You", "Ed Sheeran");
    Song song2("Blinding Lights", "The Weeknd");

    user1.playlist.addSong(song1);
    user2.playlist.addSong(song2);

    musicService.recommendSong(&user1, song2);

    return 0;
}
