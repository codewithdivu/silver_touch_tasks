#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    TrieNode *fail;
    vector<int> output;
};

class AhoCorasick
{
private:
    TrieNode *root;

public:
    AhoCorasick()
    {
        root = new TrieNode();
    }

    void insertPattern(const string &pattern, int patternIndex)
    {
        TrieNode *current = root;

        for (char c : pattern)
        {
            if (!current->children[c])
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }

        current->output.push_back(patternIndex);
    }

    void buildFailureLinks()
    {
        queue<TrieNode *> q;
        root->fail = nullptr;

        for (auto &pair : root->children)
        {
            TrieNode *child = pair.second;
            child->fail = root;
            q.push(child);
        }

        while (!q.empty())
        {
            TrieNode *current = q.front();
            q.pop();

            for (auto &pair : current->children)
            {
                char c = pair.first;
                TrieNode *child = pair.second;
                q.push(child);

                TrieNode *failNode = current->fail;
                while (failNode && !failNode->children.count(c))
                {
                    failNode = failNode->fail;
                }

                child->fail = failNode ? failNode->children[c] : root;

                child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());
            }
        }
    }

    vector<pair<int, int>> search(const string &text)
    {
        vector<pair<int, int>> matches;
        TrieNode *current = root;

        for (int i = 0; i < text.length(); ++i)
        {
            char c = text[i];

            while (current && !current->children.count(c))
            {
                current = current->fail;
            }

            if (current)
            {
                current = current->children[c];
                for (int patternIndex : current->output)
                {
                    matches.push_back({i - patternIndex + 1, patternIndex});
                }
            }
            else
            {
                current = root;
            }
        }

        return matches;
    }
};

int main()
{
    AhoCorasick ahoCorasick;

    vector<string> patterns = {"he", "she", "his", "hers"};

    for (int i = 0; i < patterns.size(); ++i)
    {
        ahoCorasick.insertPattern(patterns[i], i);
    }

    ahoCorasick.buildFailureLinks();

    string text = "hershehishers";

    vector<pair<int, int>> matches = ahoCorasick.search(text);

    cout << "Pattern matches in the text:\n";
    for (const auto &match : matches)
    {
        cout << "Pattern: " << patterns[match.second] << ", Position: " << match.first << "\n";
    }

    return 0;
}
