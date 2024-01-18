#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(const string &s, const unordered_set<string> &wordDict, int start, vector<int> &memo)
{
    if (start == s.length())
    {
        return true;
    }

    if (memo[start] != -1)
    {
        return memo[start];
    }

    for (int end = start + 1; end <= s.length(); ++end)
    {
        string word = s.substr(start, end - start);

        if (wordDict.find(word) != wordDict.end() && wordBreak(s, wordDict, end, memo))
        {

            memo[start] = true;
            return true;
        }
    }

    memo[start] = false;
    return false;
}

bool wordBreak(const string &s, const unordered_set<string> &wordDict)
{

    vector<int> memo(s.length(), -1);
    return wordBreak(s, wordDict, 0, memo);
}

int main()
{

    string input1 = "ilikesamsungmobile";
    unordered_set<string> wordDict1 = {"i", "like", "sam", "sung", "mobile"};

    cout << "Example 1: ";
    if (wordBreak(input1, wordDict1))
    {
        cout << "Yes, the string can be segmented." << endl;
    }
    else
    {
        cout << "No, the string cannot be segmented." << endl;
    }

    string input2 = "ilikeicecreamandmango";
    unordered_set<string> wordDict2 = {"i", "like", "ice", "cream", "and", "mango"};

    cout << "Example 2: ";
    if (wordBreak(input2, wordDict2))
    {
        cout << "Yes, the string can be segmented." << endl;
    }
    else
    {
        cout << "No, the string cannot be segmented." << endl;
    }

    return 0;
}
