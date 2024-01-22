#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
public:
    string brand;
    string model;
    string licensePlate;
    bool available;

    Car(const string& brand, const string& model, const string& licensePlate)
        : brand(brand), model(model), licensePlate(licensePlate), available(true) {}

    void rent() {
        if (available) {
            available = false;
            cout << "Car rented: " << brand << " " << model << " (" << licensePlate << ")" << endl;
        } else {
            cout << "Car is not available for rent." << endl;
        }
    }

    void returnCar() {
        available = true;
        cout << "Car returned: " << brand << " " << model << " (" << licensePlate << ")" << endl;
    }
};

class Customer;  

class RentalAgency {
public:
    string name;
    vector<Car> cars;

    RentalAgency(const string& name) : name(name) {}

    void displayAvailableCars() {
        cout << "Available cars at " << name << " rental agency:" << endl;
        for (const auto& car : cars) {
            if (car.available) {
                cout << car.brand << " " << car.model << " (" << car.licensePlate << ")" << endl;
            }
        }
    }

    void rentCar(Customer& customer, const string& licensePlate);

    void returnCar(Customer& customer, const string& licensePlate);
};

class Customer {
public:
    string name;
    vector<Car*> rentedCars;  

    Customer(const string& name) : name(name) {}

    void rentCar(Car& car) {
        car.rent();
        rentedCars.push_back(&car);
    }

    void returnCar(Car& car) {
        car.returnCar();
        rentedCars.erase(remove(rentedCars.begin(), rentedCars.end(), &car), rentedCars.end());
    }

    void displayRentalHistory() {
        cout << "Rental history for customer " << name << ":" << endl;
        for (const auto& car : rentedCars) {
            cout << car->brand << " " << car->model << " (" << car->licensePlate << ")" << endl;
        }
    }
};

void RentalAgency::rentCar(Customer& customer, const string& licensePlate) {
    for (auto& car : cars) {
        if (car.licensePlate == licensePlate) {
            customer.rentCar(car);
            return;
        }
    }
    cout << "Car with license plate " << licensePlate << " not found." << endl;
}

void RentalAgency::returnCar(Customer& customer, const string& licensePlate) {
    for (auto& car : cars) {
        if (car.licensePlate == licensePlate) {
            customer.returnCar(car);
            return;
        }
    }
    cout << "Car with license plate " << licensePlate << " not found." << endl;
}

int main() {
    
    Car car1("Toyota", "Camry", "ABC123");
    Car car2("Honda", "Accord", "XYZ789");

    
    RentalAgency rentalAgency("BestRentals");
    rentalAgency.cars = {car1, car2};

    
    Customer customer("John");

    
    rentalAgency.displayAvailableCars();

    
    rentalAgency.rentCar(customer, "ABC123");

    
    customer.displayRentalHistory();

    
    rentalAgency.returnCar(customer, "ABC123");

    
    rentalAgency.displayAvailableCars();

    return 0;
}
