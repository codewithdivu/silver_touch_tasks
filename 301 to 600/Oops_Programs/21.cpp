#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class GenericContainer {
private:
    vector<T> elements;

public:
    
    void addElement(const T& element) {
        elements.push_back(element);
    }

    
    T getElement(size_t index) const {
        if (index < elements.size()) {
            return elements[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    
    void displayElements() const {
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }

    
    bool isEmpty() const {
        return elements.empty();
    }

    
    size_t size() const {
        return elements.size();
    }
};

int main() {
    
    GenericContainer<int> intContainer;

    
    intContainer.addElement(42);
    intContainer.addElement(10);
    intContainer.addElement(99);

    
    cout << "Integers in the container: ";
    intContainer.displayElements();

    
    GenericContainer<string> stringContainer;

    
    stringContainer.addElement("Hello");
    stringContainer.addElement("World");
    stringContainer.addElement("!");

    
    cout << "Strings in the container: ";
    stringContainer.displayElements();

    return 0;
}
