#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Flight {
public:
    string flightNumber;
    int availableSeats;

    Flight(const string& number, int seats) : flightNumber(number), availableSeats(seats) {}
};

class Passenger {
public:
    string name;

    Passenger(const string& n) : name(n) {}
};

class Reservation {
public:
    Passenger* passenger;
    Flight* flight;

    Reservation(Passenger* p, Flight* f) : passenger(p), flight(f) {
        if (flight->availableSeats > 0) {
            flight->availableSeats--;
            cout << "Reservation for " << passenger->name << " on flight " << flight->flightNumber << " successful." << endl;
        } else {
            cout << "Sorry, no available seats on flight " << flight->flightNumber << "." << endl;
        }
    }
};

int main() {
    Flight flight1("ABC123", 50);
    Flight flight2("XYZ789", 30);

    Passenger passenger1("Alice");
    Passenger passenger2("Bob");

    Reservation reservation1(&passenger1, &flight1);
    Reservation reservation2(&passenger2, &flight1);
    Reservation reservation3(&passenger2, &flight2);

    return 0;
}
