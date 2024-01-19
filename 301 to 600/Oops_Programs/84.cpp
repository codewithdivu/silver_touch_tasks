#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Class representing a fitness activity
class Activity {
private:
    string name;
    double duration; // in minutes

public:
    Activity(const string& activityName, double activityDuration) : name(activityName), duration(activityDuration) {}

    const string& getName() const {
        return name;
    }

    double getDuration() const {
        return duration;
    }
};

// Class representing a user with fitness tracking capabilities
class User {
private:
    string username;
    vector<Activity> activities;

public:
    User(const string& name) : username(name) {}

    const string& getUsername() const {
        return username;
    }

    void logActivity(const Activity& activity) {
        activities.push_back(activity);
        cout << "Activity logged for user " << username << ": " << activity.getName() << " - Duration: " << activity.getDuration() << " minutes\n";
    }

    void generateActivityReport() const {
        cout << "Activity Report for user " << username << ":\n";
        for (const Activity& activity : activities) {
            cout << "- " << activity.getName() << ": " << activity.getDuration() << " minutes\n";
        }
    }
};

// Class representing a fitness tracker
class Tracker {
private:
    vector<User> users;

public:
    void addUser(const string& username) {
        users.emplace_back(username);
        cout << "User added to the tracker: " << username << "\n";
    }

    void logActivity(const string& username, const Activity& activity) {
        auto it = find_if(users.begin(), users.end(), [&username](const User& user) {
            return user.getUsername() == username;
        });

        if (it != users.end()) {
            it->logActivity(activity);
        } else {
            cout << "User not found in the tracker.\n";
        }
    }

    void generateUserReport(const string& username) const {
        auto it = find_if(users.begin(), users.end(), [&username](const User& user) {
            return user.getUsername() == username;
        });

        if (it != users.end()) {
            it->generateActivityReport();
        } else {
            cout << "User not found in the tracker.\n";
        }
    }
};

int main() {
    Tracker fitnessTracker;

    fitnessTracker.addUser("John");
    fitnessTracker.addUser("Alice");

    Activity running("Running", 30.0);
    Activity cycling("Cycling", 45.0);

    fitnessTracker.logActivity("John", running);
    fitnessTracker.logActivity("Alice", cycling);

    fitnessTracker.generateUserReport("John");
    fitnessTracker.generateUserReport("Alice");

    return 0;
}
