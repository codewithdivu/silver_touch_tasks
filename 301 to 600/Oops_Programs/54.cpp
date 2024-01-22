#include <iostream>
#include <type_traits>
using namespace std;


template <typename T>
struct Incrementable {
    static_assert(is_integral<T>::value, "Incrementable requires an integral type");
};


template <>
struct Incrementable<int> {};


template <typename T>
struct IncrementableWithAdditionalRequirements {
    static_assert(is_integral<T>::value, "IncrementableWithAdditionalRequirements requires an integral type");
    static_assert(is_unsigned<T>::value, "IncrementableWithAdditionalRequirements requires an unsigned type");
};


template <>
struct IncrementableWithAdditionalRequirements<unsigned int> {};


template <typename T>
T incrementAndPrint(T value) {
    Incrementable<T>();  
    cout << "Incrementing: " << value << endl;
    return ++value;
}


template <typename T>
T incrementAndPrintWithAdditionalRequirements(T value) {
    IncrementableWithAdditionalRequirements<T>();  
    cout << "Incrementing with additional requirements: " << value << endl;
    return ++value;
}

int main() {
    int intValue = 5;
    unsigned int uintValue = 3;

    
    intValue = incrementAndPrint(intValue);     
    
    

    
    uintValue = incrementAndPrintWithAdditionalRequirements(uintValue);  
    
    

    return 0;
}