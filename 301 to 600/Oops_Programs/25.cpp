#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
using EnableIfNumeric = enable_if_t<is_arithmetic<T>::value>;

template <typename T>
void printValue(T value, EnableIfNumeric<T>* = nullptr)
{
    cout << "Value: " << value << endl;
}

int main()
{
    printValue(42);
    printValue(3.14);
    // printValue("Hello");  // Compilation error due to type constraint

    return 0;
}