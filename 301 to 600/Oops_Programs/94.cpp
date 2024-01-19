#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Destination {
private:
    string name;
    string description;

public:
    Destination(const string& destName, const string& destDescription)
        : name(destName), description(destDescription) {}

    const string& getName() const {
        return name;
    }

    const string& getDescription() const {
        return description;
    }
};

class Itinerary {
private:
    vector<Destination> destinations;

public:
    void addDestination(const Destination& destination) {
        destinations.push_back(destination);
    }

    void generateItinerary() const {
        cout << "Travel Itinerary:\n";
        cout << "-------------------\n";
        for (const Destination& destination : destinations) {
            cout << "Destination: " << destination.getName() << "\n";
            cout << "Description: " << destination.getDescription() << "\n";
            cout << "-------------------\n";
        }
    }
};

class Traveler {
private:
    string name;
    Itinerary itinerary;

public:
    Traveler(const string& travelerName) : name(travelerName) {}

    const string& getName() const {
        return name;
    }

    void planTrip(const vector<Destination>& destinations) {
        for (const Destination& destination : destinations) {
            itinerary.addDestination(destination);
        }
    }

    void viewItinerary() const {
        cout << "Itinerary for " << name << ":\n";
        cout << "-------------------\n";
        itinerary.generateItinerary();
    }
};

int main() {
    using namespace std;

    Destination dest1("Paris", "City of lights and romance");
    Destination dest2("Tokyo", "Vibrant and modern metropolis");
    Destination dest3("New York", "The city that never sleeps");

    vector<Destination> tripDestinations = {dest1, dest2, dest3};

    Traveler traveler("Alice");
    traveler.planTrip(tripDestinations);
    traveler.viewItinerary();

    return 0;
}
