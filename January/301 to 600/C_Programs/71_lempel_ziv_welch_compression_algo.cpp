#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> compressLZW(const string &input)
{
    unordered_map<string, int> dictionary;
    vector<int> compressed;

    for (int i = 0; i < 256; ++i)
    {
        dictionary[string(1, static_cast<char>(i))] = i;
    }

    string current;
    for (char c : input)
    {
        string currentPlusC = current + c;

        if (dictionary.find(currentPlusC) != dictionary.end())
        {
            current = currentPlusC;
        }
        else
        {

            compressed.push_back(dictionary[current]);
            dictionary[currentPlusC] = dictionary.size();
            current = c;
        }
    }

    if (!current.empty())
    {
        compressed.push_back(dictionary[current]);
    }

    return compressed;
}

int main()
{

    string input = "ABABABABA";

    vector<int> compressed = compressLZW(input);

    cout << "Compressed Codes: ";
    for (int code : compressed)
    {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
