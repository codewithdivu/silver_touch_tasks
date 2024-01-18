#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::vector<int> compressLZW(const std::string& input) {
    std::unordered_map<std::string, int> dictionary;
    int code = 256; 

    std::vector<int> result;
    std::string current;

    for (char c : input) {
        std::string combined = current + c;
        if (dictionary.find(combined) != dictionary.end()) {
            current = combined;
        } else {
            result.push_back(dictionary[current]);
            dictionary[combined] = code++;
            current = c;
        }
    }

    if (!current.empty()) {
        result.push_back(dictionary[current]);
    }

    return result;
}

int main() {
    std::string input = "ABABABABA";
    std::vector<int> compressed = compressLZW(input);

    for (int code : compressed) {
        std::cout << code << " ";
    }

    return 0;
}
