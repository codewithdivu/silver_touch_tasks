#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
struct is_incrementable {
    template <typename U>
    static auto test(U* p) -> decltype(++(*p), true_type{});

    template <typename U>
    static auto test(...) -> false_type;

    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template <typename T>
typename enable_if<is_incrementable<T>::value, T>::type
incrementAndPrint(T value) {
    ++value;
    cout << value << endl;
    return value;
}

int main() {
    int intValue = 5;
    double doubleValue = 3.14;

    intValue = incrementAndPrint(intValue);     
    doubleValue = incrementAndPrint(doubleValue); 

    return 0;
}
