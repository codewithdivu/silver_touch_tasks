#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Attendee {
public:
    string name;

    Attendee(const string& n) : name(n) {}
};

class Organizer {
public:
    string name;

    Organizer(const string& n) : name(n) {}

    void sendNotification(const string& message) const {
        cout << "Notification sent by organizer " << name << ": " << message << endl;
    }
};

class Event {
private:
    string eventName;
    Organizer organizer;
    vector<Attendee> attendees;

public:
    Event(const string& name, const Organizer& org) : eventName(name), organizer(org) {}

    void registerAttendee(const Attendee& attendee) {
        attendees.push_back(attendee);
        organizer.sendNotification("New attendee registered for event " + eventName + ": " + attendee.name);
    }
};

int main() {
    Organizer eventOrganizer("John Doe");
    Event techEvent("Tech Conference", eventOrganizer);

    Attendee attendee1("Alice");
    Attendee attendee2("Bob");

    techEvent.registerAttendee(attendee1);
    techEvent.registerAttendee(attendee2);

    return 0;
}
