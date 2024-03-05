#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string preprocessString(const string &s)
{
    string result = "#";
    for (char c : s)
    {
        result += c;
        result += "#";
    }
    return result;
}

string longestPalindrome(const string &s)
{
    string processedString = preprocessString(s);

    int n = processedString.size();
    vector<int> P(n, 0);
    int center = 0;
    int rightBoundary = 0;

    for (int i = 1; i < n - 1; ++i)
    {
        int mirror = 2 * center - i;

        if (i < rightBoundary)
        {
            P[i] = min(rightBoundary - i, P[mirror]);
        }

        while (processedString[i + 1 + P[i]] == processedString[i - 1 - P[i]])
        {
            P[i]++;
        }

        if (i + P[i] > rightBoundary)
        {
            center = i;
            rightBoundary = i + P[i];
        }
    }

    auto maxElemIter = max_element(P.begin(), P.end());
    int maxLen = *maxElemIter;
    int centerIndex = distance(P.begin(), maxElemIter);

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = longestPalindrome(input);

    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
