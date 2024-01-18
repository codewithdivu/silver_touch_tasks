#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class User
{
public:
    string username;
    vector<string> posts;

    User(const string &name) : username(name) {}

    void addPost(const string &post)
    {
        posts.push_back(post);
    }
};

class SocialNetwork
{
private:
    unordered_map<string, User> users;

public:
    void addUser(const string &username)
    {
        users.emplace(username, User(username));
    }

    void addPost(const string &username, const string &post)
    {
        auto it = users.find(username);
        if (it != users.end())
        {
            it->second.addPost(post);
        }
        else
        {
            cout << "User not found!\n";
        }
    }

    void displayUserPosts(const string &username)
    {
        auto it = users.find(username);
        if (it != users.end())
        {
            cout << "Posts for user " << username << ":\n";
            for (const auto &post : it->second.posts)
            {
                cout << "- " << post << "\n";
            }
        }
        else
        {
            cout << "User not found!\n";
        }
    }
};

int main()
{
    SocialNetwork myNetwork;

    myNetwork.addUser("Divyesh");
    myNetwork.addUser("Mitul");

    myNetwork.addPost("Divyesh", "Hello, World!");
    myNetwork.addPost("Mitul", "Nice day!");

    myNetwork.displayUserPosts("Divyesh");
    myNetwork.displayUserPosts("Mitul");

    return 0;
}
