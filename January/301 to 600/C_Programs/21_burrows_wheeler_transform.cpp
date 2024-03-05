#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string burrowsWheelerTransform(const string &input)
{
    vector<string> rotations;
    int n = input.size();

    for (int i = 0; i < n; ++i)
    {
        rotations.push_back(input.substr(i) + input.substr(0, i));
    }

    sort(rotations.begin(), rotations.end());

    string bwt;
    for (const string &rotation : rotations)
    {
        bwt += rotation[n - 1];
    }

    return bwt;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string bwt = burrowsWheelerTransform(input);

    cout << "Burrows-Wheeler Transform: " << bwt << endl;

    return 0;
}
