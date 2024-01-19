#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class representing an Aircraft
class Aircraft {
private:
    string model;
    int capacity;

public:
    Aircraft(const string& aircraftModel, int aircraftCapacity) : model(aircraftModel), capacity(aircraftCapacity) {}

    const string& getModel() const {
        return model;
    }

    int getCapacity() const {
        return capacity;
    }

    void simulateMovement() const {
        cout << "Aircraft " << model << " is moving.\n";
    }
};

// Class representing an Airport
class Airport {
private:
    string code;
    vector<Aircraft> availableAircraft;

public:
    Airport(const string& airportCode) : code(airportCode) {}

    const string& getCode() const {
        return code;
    }

    void addAircraft(const Aircraft& aircraft) {
        availableAircraft.push_back(aircraft);
        cout << "Aircraft " << aircraft.getModel() << " added to airport " << code << ".\n";
    }

    void listAvailableAircraft() const {
        cout << "Available Aircraft at Airport " << code << ":\n";
        for (const Aircraft& aircraft : availableAircraft) {
            cout << "- Model: " << aircraft.getModel() << ", Capacity: " << aircraft.getCapacity() << "\n";
        }
    }
};

// Class representing a Flight
class Flight {
private:
    string flightNumber;
    string origin;
    string destination;

public:
    Flight(const string& number, const string& originAirport, const string& destinationAirport)
        : flightNumber(number), origin(originAirport), destination(destinationAirport) {}

    const string& getFlightNumber() const {
        return flightNumber;
    }

    const string& getOrigin() const {
        return origin;
    }

    const string& getDestination() const {
        return destination;
    }

    void scheduleFlight() const {
        cout << "Flight " << flightNumber << " scheduled from " << origin << " to " << destination << ".\n";
    }
};

int main() {
    Airport heathrow("LHR");
    Airport jfk("JFK");

    Aircraft boeing747("Boeing 747", 400);
    Aircraft airbusA380("Airbus A380", 550);

    heathrow.addAircraft(boeing747);
    heathrow.addAircraft(airbusA380);

    heathrow.listAvailableAircraft();

    Flight flight1("BA123", "LHR", "JFK");
    Flight flight2("AA456", "JFK", "LHR");

    flight1.scheduleFlight();
    flight2.scheduleFlight();

    return 0;
}
