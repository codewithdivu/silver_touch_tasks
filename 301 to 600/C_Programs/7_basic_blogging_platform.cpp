#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Post
{
public:
    Post(const string &title, const string &content) : title(title), content(content) {}

    void display() const
    {
        cout << "Title: " << title << "\nContent: " << content << "\n\n";
    }

private:
    string title;
    string content;
};

class Blog
{
public:
    void addPost(const string &title, const string &content)
    {
        posts.emplace_back(title, content);
    }

    void displayAllPosts() const
    {
        for (const auto &post : posts)
        {
            post.display();
        }
    }

private:
    vector<Post> posts;
};

int main()
{
    Blog myBlog;

    myBlog.addPost("First Post", "This is my first blog post.");
    myBlog.addPost("Another Day", "Writing about another day in my life.");
    myBlog.addPost("Programming Adventures", "Today I learned a new programming language!");

    cout << "All Posts:\n";
    myBlog.displayAllPosts();

    return 0;
}
