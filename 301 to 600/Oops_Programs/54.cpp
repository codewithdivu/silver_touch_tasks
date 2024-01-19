#include <iostream>
#include <type_traits>
using namespace std;

// Initial version of the Incrementable concept
template <typename T>
struct Incrementable {
    static_assert(is_integral<T>::value, "Incrementable requires an integral type");
};

// Specialization for int
template <>
struct Incrementable<int> {};

// Updated version of the Incrementable concept with additional requirements
template <typename T>
struct IncrementableWithAdditionalRequirements {
    static_assert(is_integral<T>::value, "IncrementableWithAdditionalRequirements requires an integral type");
    static_assert(is_unsigned<T>::value, "IncrementableWithAdditionalRequirements requires an unsigned type");
};

// Specialization for unsigned int
template <>
struct IncrementableWithAdditionalRequirements<unsigned int> {};

// Template function using Incrementable concept
template <typename T>
T incrementAndPrint(T value) {
    Incrementable<T>();  // This line will cause a compile-time error if T does not meet the requirements
    cout << "Incrementing: " << value << endl;
    return ++value;
}

// Template function using IncrementableWithAdditionalRequirements concept
template <typename T>
T incrementAndPrintWithAdditionalRequirements(T value) {
    IncrementableWithAdditionalRequirements<T>();  // This line will cause a compile-time error if T does not meet the requirements
    cout << "Incrementing with additional requirements: " << value << endl;
    return ++value;
}

int main() {
    int intValue = 5;
    unsigned int uintValue = 3;

    // Using the Incrementable concept
    intValue = incrementAndPrint(intValue);     // Output: Incrementing: 5
    // Uncommenting the line below will cause a compile-time error
    // char charValue = incrementAndPrint('a');  // Error: static assertion failed: Incrementable requires an integral type

    // Using the IncrementableWithAdditionalRequirements concept
    uintValue = incrementAndPrintWithAdditionalRequirements(uintValue);  // Output: Incrementing with additional requirements: 3
    // Uncommenting the line below will cause a compile-time error
    // intValue = incrementAndPrintWithAdditionalRequirements(intValue);  // Error: static assertion failed: IncrementableWithAdditionalRequirements requires an unsigned type

    return 0;
}