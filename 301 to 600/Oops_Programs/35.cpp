#include <iostream>
#include <regex>
using namespace std;

template <typename T>
struct MatchHelper {
    static constexpr bool match(const char* input, const T& pattern) {
        regex regex_pattern(pattern);
        return regex_match(input, regex_pattern);
    }
};

template <typename T>
constexpr bool match(const char* input, const T& pattern) {
    return MatchHelper<T>::match(input, pattern);
}

int main() {
    constexpr const char* input_str = "Hello, World!";
    constexpr const char* regex_pattern = "(.*)";

    if(match(input_str, regex_pattern)){
        cout << "not Matched!" << '\n';
        return 0;
    }
    cout << "Regular expression matched successfully!" << endl;

    return 0;
}
