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

    TrieNode() : fail(nullptr) {}
};

class AhoCorasick
{
private:
    TrieNode *root;

    void buildTrie(const vector<string> &patterns)
    {
        root = new TrieNode();

        for (int i = 0; i < patterns.size(); ++i)
        {
            TrieNode *current = root;
            for (char ch : patterns[i])
            {
                if (current->children.find(ch) == current->children.end())
                {
                    current->children[ch] = new TrieNode();
                }
                current = current->children[ch];
            }
            current->output.push_back(i);
        }
    }

    void buildFailureAndOutputLinks()
    {
        queue<TrieNode *> q;

        for (auto &it : root->children)
        {
            TrieNode *child = it.second;
            child->fail = root;
            q.push(child);
        }

        while (!q.empty())
        {
            TrieNode *current = q.front();
            q.pop();

            for (auto &it : current->children)
            {
                char ch = it.first;
                TrieNode *child = it.second;

                TrieNode *failure = current->fail;
                while (failure != nullptr && failure->children.find(ch) == failure->children.end())
                {
                    failure = failure->fail;
                }

                if (failure != nullptr)
                {
                    child->fail = failure->children[ch];
                }
                else
                {
                    child->fail = root;
                }

                child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());

                q.push(child);
            }
        }
    }

public:
    AhoCorasick(const vector<string> &patterns)
    {
        buildTrie(patterns);
        buildFailureAndOutputLinks();
    }

    void search(const string &text, vector<string> &patterns)
    {
        TrieNode *current = root;

        for (char ch : text)
        {
            while (current != nullptr && current->children.find(ch) == current->children.end())
            {
                current = current->fail;
            }

            if (current != nullptr)
            {
                current = current->children[ch];

                for (int patternIndex : current->output)
                {
                    cout << "Pattern found at position " << (patternIndex - patterns[patternIndex].size() + 1) << ": "
                         << patterns[patternIndex] << endl;
                }
            }
            else
            {
                current = root;
            }
        }
    }
};

int main()
{
    vector<string> patterns = {"he", "she", "hers", "his"};

    AhoCorasick ahoCorasick(patterns);

    string text = "ushers";
    cout << "Text: " << text << endl;
    cout << "Matching patterns:" << endl;
    ahoCorasick.search(text, patterns);

    return 0;
}
