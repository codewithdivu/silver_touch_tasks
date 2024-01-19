#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Post {
private:
    string content;
    int likes;

public:
    Post(const string& postContent) : content(postContent), likes(0) {}

    const string& getContent() const {
        return content;
    }

    int getLikes() const {
        return likes;
    }

    void like() {
        likes++;
    }
};

class User {
private:
    string username;
    vector<Post> posts;

public:
    User(const string& name) : username(name) {}

    const string& getUsername() const {
        return username;
    }

    const vector<Post>& getPosts() const {
        return posts;
    }

    void createPost(const string& content) {
        posts.emplace_back(content);
        cout << "User " << username << " created a post: " << content << "\n";
    }

    void likePost(const Post& post) {
        // Use a const reference to Post
        const_cast<Post&>(post).like();  // Remove const-ness to like the post
        cout << "User " << username << " liked a post: " << post.getContent() << "\n";
    }
};

class Network {
private:
    vector<User> users;

public:
    void addUser(const string& username) {
        users.emplace_back(username);
        cout << "User " << username << " has joined the network.\n";
    }

    void connectUsers(const string& username1, const string& username2) {
        auto user1 = findUser(username1);
        auto user2 = findUser(username2);

        if (user1 && user2) {
            cout << "Users " << username1 << " and " << username2 << " are now connected.\n";
        } else {
            cout << "One or both users not found.\n";
        }
    }

    User* findUser(const string& username) {
        auto it = find_if(users.begin(), users.end(), [&username](const User& user) {
            return user.getUsername() == username;
        });

        return (it != users.end()) ? &(*it) : nullptr;
    }

    void displayInfluentialUsers() const {
        cout << "Influential Users:\n";
        cout << "------------------------\n";
        for (const User& user : users) {
            const vector<Post>& posts = user.getPosts();
            int totalLikes = 0;
            for (const Post& post : posts) {
                totalLikes += post.getLikes();
            }
            cout << "User " << user.getUsername() << " - Total Likes: " << totalLikes << "\n";
        }
        cout << "------------------------\n";
    }

    void displayPopularPosts() const {
        cout << "Popular Posts:\n";
        cout << "------------------------\n";
        for (const User& user : users) {
            const vector<Post>& posts = user.getPosts();
            for (const Post& post : posts) {
                cout << "Post by User " << user.getUsername() << ": " << post.getContent() << " - Likes: " << post.getLikes() << "\n";
            }
        }
        cout << "------------------------\n";
    }
};

int main() {
    Network socialNetwork;

    socialNetwork.addUser("Alice");
    socialNetwork.addUser("Bob");
    socialNetwork.addUser("Charlie");

    socialNetwork.connectUsers("Alice", "Bob");
    socialNetwork.connectUsers("Bob", "Charlie");

    User* alice = socialNetwork.findUser("Alice");
    User* bob = socialNetwork.findUser("Bob");
    User* charlie = socialNetwork.findUser("Charlie");

    if (alice && bob && charlie) {
        alice->createPost("Having a great day!");
        bob->createPost("Just finished reading a good book.");
        charlie->createPost("Excited about the new project!");

        alice->likePost(bob->getPosts().front());
        bob->likePost(charlie->getPosts().front());

        socialNetwork.displayInfluentialUsers();
        socialNetwork.displayPopularPosts();
    }

    return 0;
}
