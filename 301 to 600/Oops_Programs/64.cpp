#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Post {
public:
    string content;
    string author;

    Post(const string& c, const string& a) : content(c), author(a) {}
};

class Friendship {
private:
    vector<string> friends;

public:
    void addFriend(const string& friendName) {
        friends.push_back(friendName);
        cout << friendName << " added as a friend." << endl;
    }

    void removeFriend(const string& friendName) {
        
        cout << friendName << " removed as a friend." << endl;
    }
};

class User {
private:
    string username;
    vector<Post> posts;
    Friendship friendship;

public:
    User(const string& name) : username(name) {}

    void createPost(const string& content) {
        posts.emplace_back(content, username);
        cout << "Post created by " << username << ": " << content << endl;
    }

    void addFriend(const string& friendName) {
        friendship.addFriend(friendName);
    }

    void removeFriend(const string& friendName) {
        friendship.removeFriend(friendName);
    }
};

int main() {
    User user1("Alice");
    User user2("Bob");

    user1.createPost("Hello, world!");
    user2.addFriend("Alice");

    return 0;
}
