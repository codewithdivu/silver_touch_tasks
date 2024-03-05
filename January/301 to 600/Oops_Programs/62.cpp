#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(const string& n, double p) : name(n), price(p) {}
};

class ShoppingCart {
private:
    vector<Product> items;

public:
    void addItem(const Product& product) {
        items.push_back(product);
        cout << "Added " << product.name << " to the cart." << endl;
    }

    void removeItem(const string& productName) {
        
        cout << "Removed " << productName << " from the cart." << endl;
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total;
    }
};

class Customer {
private:
    string name;
    ShoppingCart cart;

public:
    Customer(const string& n) : name(n) {}

    void addToCart(const Product& product) {
        cart.addItem(product);
    }

    void removeFromCart(const string& productName) {
        cart.removeItem(productName);
    }

    void checkout() {
        double total = cart.calculateTotal();
        cout << "Total amount to pay: $" << total << endl;
        
        cout << "Checkout completed. Thank you!" << endl;
    }
};

int main() {
    Product laptop("Laptop", 999.99);
    Product smartphone("Smartphone", 499.99);

    Customer customer("John");
    customer.addToCart(laptop);
    customer.addToCart(smartphone);

    customer.removeFromCart("Laptop");
    customer.checkout();

    return 0;
}
