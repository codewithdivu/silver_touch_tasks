#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    int data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void buildDictionary(vector<string> &dictionary)
    {
        for (string word : dictionary)
        {
            insertWord(word);
        }
    }

    void autocompleteUtil(TrieNode *root, const string &prefix, vector<string> &suggestions)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->isTerminal)
        {
            suggestions.push_back(prefix);
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != nullptr)
            {
                char ch = 'a' + i;
                autocompleteUtil(root->children[i], prefix + ch, suggestions);
            }
        }
    }

    vector<string> autocomplete(const string &prefix)
    {
        vector<string> suggestions;
        TrieNode *current = root;

        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (current->children[index] == nullptr)
            {
                return suggestions;
            }
            current = current->children[index];
        }

        autocompleteUtil(current, prefix, suggestions);
        return suggestions;
    }
};

int main()
{
    Trie *t = new Trie();

    vector<string> dictionary = {"apple", "appa", "apane", "banana", "orange", "grape", "pear"};
    t->buildDictionary(dictionary);

    string prefix;
    cout << "Enter a prefix for autocomplete: ";
    cin >> prefix;

    vector<string> suggestions = t->autocomplete(prefix);

    if (suggestions.empty())
    {
        cout << "No suggestions found." << endl;
    }
    else
    {
        cout << "Autocomplete suggestions:" << endl;
        for (const string &suggestion : suggestions)
        {
            cout << suggestion << endl;
        }
    }

    return 0;
}