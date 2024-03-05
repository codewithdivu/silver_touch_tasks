#include <iostream>
#include <type_traits>
using namespace std;

template <typename T, enable_if_t<is_integral<T>::value, int> = 0>
void performOperation(T value) {
    cout << "Integral operation: " << value << endl;
}

template <typename T, enable_if_t<is_floating_point<T>::value, int> = 0>
void performOperation(T value) {
    cout << "Floating-point operation: " << value << endl;
}

template <typename T, enable_if_t<!is_integral<T>::value && !is_floating_point<T>::value, int> = 0>
void performOperation(T value) {
    cout << "Generic operation: " << value << endl;
}

int main() {
    performOperation(42);      
    performOperation(3.14);    
    performOperation("Hello"); 

    return 0;
}