#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    double price;

    Room(int number, double p) : roomNumber(number), price(p) {}
};

class Guest {
public:
    string name;

    Guest(const string& n) : name(n) {}
};

class Reservation {
public:
    Room* room;
    Guest* guest;

    Reservation(Room* r, Guest* g) : room(r), guest(g) {}
};

class Hotel {
private:
    vector<Room> rooms;
    vector<Guest> guests;
    vector<Reservation> reservations;

public:
    void addRoom(const Room& room) {
        rooms.push_back(room);
    }

    void addGuest(const Guest& guest) {
        guests.push_back(guest);
    }

    Reservation bookRoom(Room* room, Guest* guest) {
        reservations.emplace_back(room, guest);
        cout << guest->name << " booked Room #" << room->roomNumber << " for $" << room->price << " per night." << endl;
        return reservations.back();
    }

    void cancelReservation(const Reservation& reservation) {
        // Implement cancellation logic
        cout << reservation.guest->name << "'s reservation for Room #" << reservation.room->roomNumber << " canceled." << endl;
    }
};

int main() {
    Hotel hotel;

    Room singleRoom(101, 79.99);
    Room doubleRoom(201, 129.99);

    Guest guest1("Alice");
    Guest guest2("Bob");

    hotel.addRoom(singleRoom);
    hotel.addRoom(doubleRoom);

    hotel.addGuest(guest1);
    hotel.addGuest(guest2);

    Reservation reservation1 = hotel.bookRoom(&singleRoom, &guest1);
    Reservation reservation2 = hotel.bookRoom(&doubleRoom, &guest2);

    hotel.cancelReservation(reservation1);

    return 0;
}
