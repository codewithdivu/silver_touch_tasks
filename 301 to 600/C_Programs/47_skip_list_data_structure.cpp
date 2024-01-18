#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int key;
    Node **forward;

    Node(int k, int level) : key(k)
    {
        forward = new Node *[level + 1];
        fill_n(forward, level + 1, nullptr);
    }
};

class SkipList
{
    int MAX_LEVEL;
    float P;
    int level;
    Node *header;

public:
    SkipList(int maxLevel, float probability) : MAX_LEVEL(maxLevel), P(probability), level(0)
    {
        header = new Node(-1, MAX_LEVEL);
    }

    int randomLevel()
    {
        int lvl = 0;
        while ((rand() % 100) < P * 100 && lvl < MAX_LEVEL)
        {
            lvl++;
        }
        return lvl;
    }

    Node *createNode(int key, int level)
    {
        return new Node(key, level);
    }

    void insert(int key)
    {
        Node *update[MAX_LEVEL + 1];
        Node *current = header;

        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();

        if (newLevel > level)
        {
            for (int i = level + 1; i <= newLevel; i++)
            {
                update[i] = header;
            }
            level = newLevel;
        }

        Node *newNode = createNode(key, newLevel);

        for (int i = 0; i <= newLevel; i++)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        cout << "Inserted key " << key << " at level " << newLevel << "\n";
    }

    void display()
    {
        cout << "Skip List (level " << level << "):\n";
        for (int i = level; i >= 0; i--)
        {
            Node *current = header->forward[i];
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
    SkipList skipList(3, 0.5);

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(9);
    skipList.insert(12);
    skipList.insert(19);
    skipList.insert(17);
    skipList.insert(26);
    skipList.insert(21);
    skipList.insert(25);

    skipList.display();

    return 0;
}
