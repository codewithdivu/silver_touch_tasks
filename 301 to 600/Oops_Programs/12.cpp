#include <iostream>
#include <unordered_map>
using namespace std;

class Flyweight {
public:
    virtual void operation() const = 0;
};

class ConcreteFlyweight : public Flyweight {
private:
    string intrinsicState;

public:
    ConcreteFlyweight(const string& intrinsic) : intrinsicState(intrinsic) {}

    void operation() const override {
        cout << "Concrete Flyweight with intrinsic state: " << intrinsicState << endl;
    }
};

class FlyweightFactory {
private:
    unordered_map<string, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(const string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }
};

int main() {
    FlyweightFactory factory;

    Flyweight* fw1 = factory.getFlyweight("A");
    Flyweight* fw2 = factory.getFlyweight("B");
    Flyweight* fw3 = factory.getFlyweight("A");

    fw1->operation();
    fw2->operation();
    fw3->operation();  

    return 0;
}
