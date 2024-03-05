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

    
    

    return 0;
}
