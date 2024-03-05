#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void generatePowerSet(const string &str, string currentSet, int index = 0)
{
    int n = str.length();

    cout << "{" << currentSet << "}" << endl;

    for (int i = index; i < n; ++i)
    {
        currentSet.push_back(str[i]);
        generatePowerSet(str, currentSet, i + 1);
        currentSet.pop_back();
    }
}

int main()
{
    string input = "abc";

    sort(input.begin(), input.end());

    generatePowerSet(input, "");

    return 0;
}
