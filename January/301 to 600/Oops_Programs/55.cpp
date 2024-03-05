#include <iostream>
#include <regex>
#include <string>
#include <type_traits> 
using namespace std;


template <const char* Pattern>
struct PatternWrapper {
    static constexpr const char* value = Pattern;
};

template <const char* Pattern, typename = void>
struct Matcher;

template <const char* Pattern>
struct Matcher<Pattern, enable_if_t<is_same<const char*, typename PatternWrapper<Pattern>::value>::value>> {
    static bool match(const string& input) {
        static const regex regexPattern(Pattern);
        return regex_match(input, regexPattern);
    }
};

int main() {
    constexpr const char* regexPattern = "^[0-9]+$"; 
    static const regex staticRegexPattern(regexPattern);
    if (regex_match("12345", staticRegexPattern)) {
        cout << "Matched!" << endl;
    } else {
        cout << "Not matched!" << endl;
    }
    if (regex_match("dafdfa", staticRegexPattern)) {
        cout << "Matched!" << endl;
    } else {
        cout << "Not matched!" << endl;
    }
    return 0;
}