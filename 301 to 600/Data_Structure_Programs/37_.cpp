#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct RadixNode
{
    bool isLeaf;
    unordered_map<char, RadixNode *> children;
    string value;

    RadixNode() : isLeaf(false) {}
};

class RadixTree
{
private:
    RadixNode *root;

    void insertHelper(RadixNode *&node, const string &key, const string &value)
    {
        if (node == nullptr)
        {
            node = new RadixNode();
        }

        if (key.empty())
        {

            node->isLeaf = true;
            node->value = value;
        }
        else
        {
            char firstChar = key[0];
            string remainingKey = key.substr(1);

            auto it = node->children.find(firstChar);

            if (it == node->children.end())
            {

                insertHelper(node->children[firstChar], remainingKey, value);
            }
            else
            {

                insertHelper(it->second, remainingKey, value);
            }
        }
    }

    RadixNode *searchHelper(RadixNode *node, const string &key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (key.empty())
        {

            return node->isLeaf ? node : nullptr;
        }
        else
        {
            char firstChar = key[0];
            string remainingKey = key.substr(1);

            auto it = node->children.find(firstChar);

            if (it != node->children.end())
            {

                return searchHelper(it->second, remainingKey);
            }
            else
            {

                return nullptr;
            }
        }
    }

public:
    RadixTree() : root(nullptr) {}

    void insert(const string &key, const string &value)
    {
        insertHelper(root, key, value);
    }

    string search(const string &key)
    {
        RadixNode *resultNode = searchHelper(root, key);
        return (resultNode != nullptr) ? resultNode->value : "Key not found";
    }
};

int main()
{
    RadixTree radixTree;

    radixTree.insert("apple", "A fruit");
    radixTree.insert("app", "An application");
    radixTree.insert("banana", "Another fruit");
    radixTree.insert("bat", "A flying mammal");

    cout << "Search result for 'apple': " << radixTree.search("apple") << endl;
    cout << "Search result for 'app': " << radixTree.search("app") << endl;
    cout << "Search result for 'banana': " << radixTree.search("banana") << endl;
    cout << "Search result for 'bat': " << radixTree.search("bat") << endl;
    cout << "Search result for 'orange': " << radixTree.search("orange") << endl;

    return 0;
}
