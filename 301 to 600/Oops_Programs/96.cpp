#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    int stock;

public:
    Product(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    const string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getStock() const {
        return stock;
    }

    void updateStock(int quantity) {
        stock += quantity;
        if (stock < 0) {
            stock = 0;
        }
    }
};

class Category {
private:
    string name;
    vector<Product> products;

public:
    Category(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    void addProduct(const string& productName, double price, int stock) {
        products.emplace_back(productName, price, stock);
    }

    void removeProduct(const string& productName) {
        products.erase(
            remove_if(products.begin(), products.end(),
                      [&](const Product& product) { return product.getName() == productName; }),
            products.end());
    }

    vector<Product>& getProducts() {  // Change this line to return a non-const reference
        return products;
    }

    int getTotalStock() const {
        int totalStock = 0;
        for (const Product& product : products) {
            totalStock += product.getStock();
        }
        return totalStock;
    }
};

class Warehouse {
private:
    string name;
    vector<Category> categories;

public:
    Warehouse(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    void addCategory(const string& categoryName) {
        categories.emplace_back(categoryName);
    }

    void removeCategory(const string& categoryName) {
        categories.erase(
            remove_if(categories.begin(), categories.end(),
                      [&](const Category& category) { return category.getName() == categoryName; }),
            categories.end());
    }

    vector<Category>& getCategories() {  // Change this line to return a non-const reference
        return categories;
    }

    void generateInventoryReport() {
        cout << "\nInventory Report for Warehouse " << name << ":\n";
        cout << "---------------------------------------------\n";

        for (Category& category : categories) {  // Change to non-const iterator
            cout << "Category: " << category.getName() << "\n";
            for (const Product& product : category.getProducts()) {
                cout << "  - " << product.getName() << ", Stock: " << product.getStock()
                     << ", Price: $" << product.getPrice() << "\n";
            }
            cout << "  Total Stock: " << category.getTotalStock() << "\n";
            cout << "---------------------------------------------\n";
        }
    }
};

int main() {
    Warehouse warehouse("Main Warehouse");

    warehouse.addCategory("Electronics");
    warehouse.addCategory("Clothing");

    warehouse.getCategories()[0].addProduct("Laptop", 1200.0, 10);
    warehouse.getCategories()[0].addProduct("Smartphone", 600.0, 20);
    warehouse.getCategories()[1].addProduct("T-Shirt", 15.0, 50);
    warehouse.getCategories()[1].addProduct("Jeans", 40.0, 30);

    warehouse.generateInventoryReport();

    warehouse.getCategories()[0].getProducts()[0].updateStock(-5);
    warehouse.getCategories()[1].getProducts()[1].updateStock(10);

    warehouse.generateInventoryReport();

    return 0;
}
