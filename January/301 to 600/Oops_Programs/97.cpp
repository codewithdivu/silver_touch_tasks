#include <iostream>
#include <vector>
#include <string>

using namespace std;


class ChatRoom;
class Message;


class User {
private:
    string username;

public:
    User(const string& username) : username(username) {}

    const string& getUsername() const {
        return username;
    }

    void sendMessage(ChatRoom& chatRoom, const string& content);

    void receiveMessage(const Message& message) const;
};


class Message {
private:
    const User& sender;
    string content;

public:
    Message(const User& sender, const string& content) : sender(sender), content(content) {}

    const User& getSender() const {
        return sender;
    }

    const string& getContent() const {
        return content;
    }
};


class ChatRoom {
private:
    string name;
    vector<User*> participants;
    vector<Message> messageHistory;

public:
    ChatRoom(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    void addUser(User* user) {
        participants.push_back(user);
    }

    void broadcastMessage(const Message& message) {
        messageHistory.push_back(message);
        for (User* participant : participants) {
            participant->receiveMessage(message);
        }
    }

    const vector<Message>& getMessageHistory() const {
        return messageHistory;
    }
};


void User::sendMessage(ChatRoom& chatRoom, const string& content) {
    Message message(*this, content);
    chatRoom.broadcastMessage(message);
}

void User::receiveMessage(const Message& message) const {
    cout << "[" << message.getSender().getUsername() << "]: " << message.getContent() << endl;
}

int main() {
    
    User user1("Alice");
    User user2("Bob");
    User user3("Charlie");

    
    ChatRoom chatRoom("General Chat");

    
    chatRoom.addUser(&user1);
    chatRoom.addUser(&user2);
    chatRoom.addUser(&user3);

    
    user1.sendMessage(chatRoom, "Hello, everyone!");
    user2.sendMessage(chatRoom, "Hi, Alice!");
    user3.sendMessage(chatRoom, "Hey, Bob!");

    
    const vector<Message>& history = chatRoom.getMessageHistory();
    cout << "\nChat Room History:\n";
    for (const Message& message : history) {
        cout << "[" << message.getSender().getUsername() << "]: " << message.getContent() << endl;
    }

    return 0;
}
