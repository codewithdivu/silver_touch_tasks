#include <iostream>
#include <string>

using namespace std;

class Pet {
private:
    string name;
    int health;
    int happiness;

public:
    Pet(const string& petName) : name(petName), health(100), happiness(100) {}

    const string& getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getHappiness() const {
        return happiness;
    }

    void feed(int foodValue) {
        health += foodValue;
        happiness += 5;
        cout << name << " has been fed. Health + " << foodValue << ", Happiness + 5\n";
    }

    void play() {
        happiness += 10;
        cout << name << " is playing. Happiness + 10\n";
    }

    void showStatus() const {
        cout << "Status of " << name << ":\n";
        cout << "Health: " << health << "\n";
        cout << "Happiness: " << happiness << "\n";
    }
};

class Food {
private:
    string name;
    int nutritionValue;

public:
    Food(const string& foodName, int nutrition) : name(foodName), nutritionValue(nutrition) {}

    const string& getName() const {
        return name;
    }

    int getNutritionValue() const {
        return nutritionValue;
    }
};

class Owner {
private:
    string name;

public:
    Owner(const string& ownerName) : name(ownerName) {}

    const string& getName() const {
        return name;
    }

    void feedPet(Pet& pet, const Food& food) {
        pet.feed(food.getNutritionValue());
    }

    void playWithPet(Pet& pet) {
        pet.play();
    }
};

int main() {
    using namespace std;

    Pet myPet("Buddy");
    Food petFood("Dog Food", 20);
    Owner petOwner("John");

    petOwner.feedPet(myPet, petFood);
    petOwner.playWithPet(myPet);

    myPet.showStatus();

    return 0;
}
