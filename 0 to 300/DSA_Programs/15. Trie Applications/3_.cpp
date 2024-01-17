#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string sortString(const string &str)
{
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

void findAnagrams(const string &inputWord, const vector<string> &dictionary)
{
    unordered_map<string, vector<string>> anagramMap;

    for (auto word : dictionary)
    {
        string sortedWord = sortString(word);
        if (sortedWord == sortString(inputWord))
        {
            anagramMap[sortedWord].push_back(word);
        }
    }

    for (auto entry : anagramMap)
    {
        cout << "Anagrams of " << inputWord << ": ";
        for (auto anagram : entry.second)
        {
            cout << anagram << " ";
        }
        cout << endl;
    }
}

int main()
{
    ifstream dictionaryFile("ic.txt");
    if (!dictionaryFile.is_open())
    {
        cerr << "Error opening dictionary file." << endl;
        return 1;
    }

    vector<string> dictionary;
    string word;
    while (dictionaryFile >> word)
    {
        dictionary.push_back(word);
    }

    dictionaryFile.close();

    string inputWord;
    cout << "Enter a word to find anagrams: ";
    cin >> inputWord;

    findAnagrams(inputWord, dictionary);

    return 0;
}
