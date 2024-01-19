#include <iostream>
using namespace std;

class ImmutableObject {
private:
    const int value;

public:
    ImmutableObject(int v) : value(v) {}

    int getValue() const {
        return value;
    }
};

int main() {
    ImmutableObject obj(42);

    cout << "Immutable Object Value: " << obj.getValue() << endl;

    // Uncommenting the line below will result in a compilation error
    // obj.setValue(100);

    return 0;
}
