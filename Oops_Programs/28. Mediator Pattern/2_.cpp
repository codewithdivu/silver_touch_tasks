#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User;

class ChatRoom
{
public:
    virtual void addUser(User *user) = 0;
    virtual void sendMessage(User *user, const string &msg) = 0;
    virtual ~ChatRoom() {}
};

class User
{
private:
    ChatRoom *mediator;
    string username;

public:
    User(ChatRoom *mediator, const string &username) : mediator(mediator), username(username)
    {
    }

    void registerWithMediator()
    {
        mediator->addUser(this);
    }

    string getUsername() const
    {
        return username;
    }

    void sendChatMessage(const string &message)
    {
        mediator->sendMessage(this, message);
    }

    void receiveChatMessage(User *sender, const string &message)
    {
        cout << username << " received a message from " << sender->getUsername() << ": " << message << endl;
    }
};

class ConcreteChatRoom : public ChatRoom
{
private:
    vector<User *> users;

public:
    ConcreteChatRoom() {}

    void addUser(User *user) override
    {
        users.push_back(user);
    }

    void sendMessage(User *sender, const string &message) override
    {
        cout << sender->getUsername() << " sends a message to the chat room: " << message << "\n";
        for (const auto &user : users)
        {
            if (user != sender)
            {
                user->receiveChatMessage(sender, message);
            }
        }
    }
};

int main()
{
    ConcreteChatRoom chatRoom;
    User divyesh(&chatRoom, "Divyesh");
    User prince(&chatRoom, "Prince");
    User mitul(&chatRoom, "Mitul");

    divyesh.registerWithMediator();
    prince.registerWithMediator();
    mitul.registerWithMediator();

    divyesh.sendChatMessage("Hello everyone!");
    prince.sendChatMessage("Hi Divyesh!");
    mitul.sendChatMessage("Hey there!");

    return 0;
}
