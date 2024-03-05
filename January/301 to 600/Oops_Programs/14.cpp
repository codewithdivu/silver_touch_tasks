#include <iostream>
using namespace std;

class Adaptee {
public:
    void specificRequest() const {
        cout << "Adaptee's specific request\n";
    }
};

class Target {
public:
    virtual void request() const = 0;
};

class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adp) : adaptee(adp) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

int main() {
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    adapter.request();

    return 0;
}
