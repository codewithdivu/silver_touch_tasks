#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


struct SkipNode
{
    int key;
    vector<SkipNode *> forward;

    SkipNode(int k, int level) : key(k), forward(level + 1) {}
};


class SkipGraph
{
    int maxLevel;
    int currentLevel;
    SkipNode *header;

public:
    SkipGraph(int maxLvl) : maxLevel(maxLvl), currentLevel(0)
    {
        header = new SkipNode(INT_MIN, maxLevel);
    }

    
    int randomLevel()
    {
        int lvl = 0;
        while (rand() % 2 == 0 && lvl < maxLevel)
        {
            lvl++;
        }
        return lvl;
    }

    
    void insert(int key)
    {
        vector<SkipNode *> update(maxLevel + 1, nullptr);
        SkipNode *current = header;

        for (int i = currentLevel; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();

        if (newLevel > currentLevel)
        {
            for (int i = currentLevel + 1; i <= newLevel; i++)
            {
                update[i] = header;
            }
            currentLevel = newLevel;
        }

        SkipNode *newNode = new SkipNode(key, newLevel);

        for (int i = 0; i <= newLevel; i++)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    
    bool search(int key)
    {
        SkipNode *current = header;

        for (int i = currentLevel; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        return (current != nullptr && current->key == key);
    }

    
    void display()
    {
        cout << "Skip Graph (level " << currentLevel << "):\n";
        for (int i = currentLevel; i >= 0; i--)
        {
            SkipNode *current = header->forward[i];
            cout << "Level " << i << ": ";
            while (current != nullptr)
            {
                cout << current->key << " ";
                current = current->forward[i];
            }
            cout << "\n";
        }
    }
};

int main()
{
    SkipGraph skipGraph(4);

    skipGraph.insert(3);
    skipGraph.insert(6);
    skipGraph.insert(7);
    skipGraph.insert(9);
    skipGraph.insert(12);
    skipGraph.insert(19);
    skipGraph.insert(17);
    skipGraph.insert(26);
    skipGraph.insert(21);
    skipGraph.insert(25);

    skipGraph.display();

    
    int searchKey = 17;
    cout << "Key " << searchKey << " is " << (skipGraph.search(searchKey) ? "found" : "not found") << "\n";

    return 0;
}
