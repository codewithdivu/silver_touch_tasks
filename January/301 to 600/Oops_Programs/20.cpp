#include <iostream>
using namespace std;

template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    const int result = Factorial<5>::value; 
    cout << "Factorial of 5: " << result << endl;
    return 0;
}
