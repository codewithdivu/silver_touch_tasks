#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(const string &n, double p) : name(n), price(p) {}
};

class ShoppingCart
{
private:
    vector<Product> cart;

public:
    void addProduct(const Product &product)
    {
        cart.push_back(product);
        cout << "Added " << product.name << " to the shopping cart." << endl;
    }

    double calculateTotal() const
    {
        double total = 0.0;

        for (const auto &product : cart)
        {
            total += product.price;
        }

        return total;
    }
};

class Order
{
public:
    ShoppingCart cart;
    string customerName;

    Order(const string &name) : customerName(name) {}

    void checkout()
    {
        double total = cart.calculateTotal();
        cout << "Checkout completed for " << customerName << ". Total amount: $" << total << endl;
    }
};

int main()
{
    Product laptop("Laptop", 999.99);
    Product phone("Smartphone", 499.99);

    Order order("Alice");
    order.cart.addProduct(laptop);
    order.cart.addProduct(phone);

    order.checkout();

    return 0;
}
