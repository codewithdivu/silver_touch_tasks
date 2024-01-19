#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum VehicleType {
    CAR,
    MOTORCYCLE
};

class Vehicle {
public:
    string licensePlate;
    VehicleType type;

    Vehicle(const string& plate, VehicleType t) : licensePlate(plate), type(t) {}
};

class Ticket {
public:
    string ticketNumber;
    Vehicle* vehicle;

    Ticket(const string& number, Vehicle* v) : ticketNumber(number), vehicle(v) {}
};

class ParkingLot {
private:
    vector<Vehicle> parkedVehicles;
    vector<Ticket> issuedTickets;

public:
    Ticket parkVehicle(const Vehicle& vehicle) {
        parkedVehicles.push_back(vehicle);
        string ticketNumber = "T" + to_string(issuedTickets.size() + 1);
        issuedTickets.emplace_back(ticketNumber, &parkedVehicles.back());
        return issuedTickets.back();
    }

    void retrieveVehicle(const Ticket& ticket) {
        // Implement retrieval logic
        cout << "Retrieved vehicle with ticket number " << ticket.ticketNumber << endl;
    }

    double calculateParkingFee(const Ticket& ticket) const {
        // Implement fee calculation based on vehicle type and duration
        return 10.0; // Placeholder value
    }
};

int main() {
    ParkingLot parkingLot;

    Vehicle car("ABC123", CAR);
    Ticket carTicket = parkingLot.parkVehicle(car);

    Vehicle motorcycle("XYZ789", MOTORCYCLE);
    Ticket motorcycleTicket = parkingLot.parkVehicle(motorcycle);

    parkingLot.retrieveVehicle(carTicket);
    double carFee = parkingLot.calculateParkingFee(carTicket);
    cout << "Parking fee for the car: $" << carFee << endl;

    parkingLot.retrieveVehicle(motorcycleTicket);
    double motorcycleFee = parkingLot.calculateParkingFee(motorcycleTicket);
    cout << "Parking fee for the motorcycle: $" << motorcycleFee << endl;

    return 0;
}
