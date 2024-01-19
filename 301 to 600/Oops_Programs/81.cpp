#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Room {
private:
    int roomNumber;
    bool isOccupied;

public:
    Room(int number) : roomNumber(number), isOccupied(false) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool getIsOccupied() const {
        return isOccupied;
    }

    void occupyRoom() {
        isOccupied = true;
        cout << "Room " << roomNumber << " has been occupied.\n";
    }

    void vacateRoom() {
        isOccupied = false;
        cout << "Room " << roomNumber << " has been vacated.\n";
    }
};

class Guest {
private:
    string name;

public:
    Guest(const string& guestName) : name(guestName) {}

    const string& getName() const {
        return name;
    }
};

class Booking {
private:
    Room* room;
    Guest* guest;

public:
    Booking(Room& bookedRoom, Guest& bookingGuest) : room(&bookedRoom), guest(&bookingGuest) {}

    void checkIn() {
        if (!room->getIsOccupied()) {
            room->occupyRoom();
            cout << guest->getName() << " has checked in to Room " << room->getRoomNumber() << ".\n";
        } else {
            cout << "Room " << room->getRoomNumber() << " is already occupied.\n";
        }
    }

    void checkOut() {
        if (room->getIsOccupied()) {
            room->vacateRoom();
            cout << guest->getName() << " has checked out from Room " << room->getRoomNumber() << ".\n";
        } else {
            cout << "Room " << room->getRoomNumber() << " is not occupied.\n";
        }
    }
};

class Hotel {
private:
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    Hotel(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.emplace_back(i);
        }
    }

    Room* findAvailableRoom() {
        auto it = find_if(rooms.begin(), rooms.end(), [](const Room& room) {
            return !room.getIsOccupied();
        });

        return (it != rooms.end()) ? &(*it) : nullptr;
    }

    void bookRoom(Guest& guest) {
        Room* availableRoom = findAvailableRoom();
        if (availableRoom) {
            bookings.emplace_back(*availableRoom, guest);
            cout << guest.getName() << " has booked Room " << availableRoom->getRoomNumber() << ".\n";
        } else {
            cout << "No available rooms for booking.\n";
        }
    }

    void displayRoomStatus() const {
        cout << "Room Status:\n";
        cout << "------------------------\n";
        for (const Room& room : rooms) {
            cout << "Room " << room.getRoomNumber() << ": " << (room.getIsOccupied() ? "Occupied" : "Available") << "\n";
        }
        cout << "------------------------\n";
    }
};

int main() {

    Hotel hotel(10);  // Create a hotel with 10 rooms

    Guest alice("Alice");
    Guest bob("Bob");

    hotel.displayRoomStatus();

    hotel.bookRoom(alice);
    hotel.bookRoom(bob);

    hotel.displayRoomStatus();

    // Create a booking for Alice in Room 3
    Booking aliceBooking(*hotel.findAvailableRoom(), alice);
    aliceBooking.checkIn();
    hotel.displayRoomStatus();

    // Create a booking for Bob in Room 7
    Booking bobBooking(*hotel.findAvailableRoom(), bob);
    bobBooking.checkIn();
    hotel.displayRoomStatus();

    // Check out Alice from Room 3
    aliceBooking.checkOut();
    hotel.displayRoomStatus();

    // Check out Bob from Room 7
    bobBooking.checkOut();
    hotel.displayRoomStatus();

    return 0;
}
