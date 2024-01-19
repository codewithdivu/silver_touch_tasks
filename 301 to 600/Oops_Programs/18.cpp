#include <iostream>
#include <string>
using namespace std;


class Product {
private:
    int id;
    string name;
    double price;

public:
    Product(int i, const string& n, double p) : id(i), name(n), price(p) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};


class ProductRepository {
public:
    Product getById(int id) const {
        return Product(id, "Sample Product", 19.99);
    }

    void save(const Product& product) const {
        cout << "Product saved: " << product.getId() << " - " << product.getName() << endl;
    }
};

int main() {
    ProductRepository repository;

    int productId = 1;
    Product product = repository.getById(productId);
    cout << "Retrieved Product: " << product.getName() << " - $" << product.getPrice() << endl;
    
    product = Product(productId, "Modified Product", 29.99);
    repository.save(product);

    return 0;
}
