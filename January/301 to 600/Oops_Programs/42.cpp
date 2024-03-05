#include <iostream>
using namespace std;

template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    constexpr int result = Fibonacci<10>::value; 
    cout << "Fibonacci(10) = " << result << endl;

    return 0;
}
