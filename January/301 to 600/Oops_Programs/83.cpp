#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Instrument {
private:
    string name;
    double price;
    bool available;

public:
    Instrument(const string& instrumentName, double instrumentPrice) : name(instrumentName), price(instrumentPrice), available(true) {}

    const string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    bool isAvailable() const {
        return available;
    }

    void markAsSold() {
        available = false;
    }
};

class Musician {
private:
    string name;
    vector<Instrument*> instruments;

public:
    Musician(const string& musicianName) : name(musicianName) {}

    const string& getName() const {
        return name;
    }

    const vector<Instrument*>& getInstruments() const {
        return instruments;
    }

    void associateInstrument(Instrument* instrument) {
        instruments.push_back(instrument);
        cout << "Musician " << name << " associated with instrument: " << instrument->getName() << "\n";
    }
};

class Inventory {
private:
    vector<Instrument> instruments;
    vector<Musician> musicians;

public:
    void addInstrument(const string& name, double price) {
        instruments.emplace_back(name, price);
        cout << "Instrument added to inventory: " << name << "\n";
    }

    void addMusician(const string& name) {
        musicians.emplace_back(name);
        cout << "Musician added to store: " << name << "\n";
    }

    void sellInstrument(Musician& musician, Instrument* instrument) {
        if (instrument && instrument->isAvailable()) {
            musician.associateInstrument(instrument);
            instrument->markAsSold();
            cout << "Instrument sold to musician " << musician.getName() << ": " << instrument->getName() << "\n";
        } else {
            cout << "Instrument not available for sale or not found.\n";
        }
    }

    Instrument* findAvailableInstrument(const string& instrumentName) {
        auto it = find_if(instruments.begin(), instruments.end(), [&instrumentName](const Instrument& instrument) {
            return (instrument.getName() == instrumentName) && instrument.isAvailable();
        });

        return (it != instruments.end()) ? &(*it) : nullptr;
    }

    Musician& findMusician(const string& musicianName) {
        auto it = find_if(musicians.begin(), musicians.end(), [&musicianName](const Musician& musician) {
            return musician.getName() == musicianName;
        });

        if (it != musicians.end()) {
            return *it; // Return a reference to an existing Musician
        } else {
            musicians.emplace_back(musicianName);
            return musicians.back(); // Return a reference to the newly created Musician
        }
    }
};

int main() {
    Inventory musicStore;

    musicStore.addInstrument("Guitar", 500.0);
    musicStore.addInstrument("Piano", 1500.0);
    musicStore.addInstrument("Drums", 800.0);

    musicStore.addMusician("John");
    musicStore.addMusician("Alice");

    Musician& john = musicStore.findMusician("John");
    Musician& alice = musicStore.findMusician("Alice");

    musicStore.sellInstrument(john, musicStore.findAvailableInstrument("Guitar"));
    musicStore.sellInstrument(alice, musicStore.findAvailableInstrument("Piano"));

    return 0;
}
