#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class User;

class ChatRoom
{
public:
    virtual void addUser(User *user) const = 0;
    virtual void sendMessage(User *user, string msg) const = 0;
};

int main()
{

    return 0;
}