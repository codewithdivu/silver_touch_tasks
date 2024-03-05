#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct SkipNode
{
    int key;
    vector<SkipNode *> next;

    SkipNode(int k, int levels) : key(k), next(levels, nullptr) {}
};

class SkipGraph
{
private:
    int maxLevels;
    SkipNode *head;
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<> dis;

    int randomLevel()
    {
        int level = 1;
        while (dis(gen) < 0.5 && level < maxLevels)
        {
            level++;
        }
        return level;
    }

public:
    SkipGraph(int levels) : maxLevels(levels), head(nullptr), gen(rd()), dis(0, 1) {}

    void insert(int key)
    {
        if (head == nullptr)
        {
            head = new SkipNode(key, maxLevels);
        }

        int level = randomLevel();
        SkipNode *newNode = new SkipNode(key, level);

        for (int i = 0; i < level; ++i)
        {
            newNode->next[i] = head->next[i];
            head->next[i] = newNode;
        }
    }

    bool search(int key)
    {
        SkipNode *current = head;

        for (int i = maxLevels - 1; i >= 0; --i)
        {
            while (current->next[i] != nullptr && current->next[i]->key < key)
            {
                current = current->next[i];
            }

            if (current->next[i] != nullptr && current->next[i]->key == key)
            {
                return true;
            }
        }

        return false;
    }

    void remove(int key)
    {
        SkipNode *current = head;
        vector<SkipNode *> update(maxLevels, nullptr);

        for (int i = maxLevels - 1; i >= 0; --i)
        {
            while (current->next[i] != nullptr && current->next[i]->key < key)
            {
                current = current->next[i];
            }
            update[i] = current;
        }

        for (int i = 0; i < maxLevels; ++i)
        {
            if (update[i]->next[i] != nullptr && update[i]->next[i]->key == key)
            {
                update[i]->next[i] = update[i]->next[i]->next[i];
            }
        }
    }

    void inorderTraversal()
    {
        if (head == nullptr)
        {
            cout << "Skip Graph is empty." << endl;
            return;
        }

        SkipNode *current = head;
        while (current->next[0] != nullptr)
        {
            cout << current->next[0]->key << " ";
            current = current->next[0];
        }

        cout << endl;
    }
};

int main()
{

    SkipGraph skipGraph(4);

    skipGraph.insert(10);
    skipGraph.insert(20);
    skipGraph.insert(15);
    skipGraph.insert(25);
    skipGraph.insert(5);

    cout << "Skip Graph after insertion: ";
    skipGraph.inorderTraversal();

    cout << "Search for key 15: " << (skipGraph.search(15) ? "Found" : "Not Found") << endl;

    skipGraph.remove(15);

    cout << "Skip Graph after removing key 15: ";
    skipGraph.inorderTraversal();

    return 0;
}
