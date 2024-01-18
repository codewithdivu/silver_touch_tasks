#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> compressLZW(const string& input) {
    unordered_map<string, int> dictionary;
    int code = 256; 

    vector<int> result;
    string current;

    for (char c : input) {
        string combined = current + c;
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
    string input = "ABABABABA";
    vector<int> compressed = compressLZW(input);

    for (int code : compressed) {
        cout << code << " ";
    }

    return 0;
}
