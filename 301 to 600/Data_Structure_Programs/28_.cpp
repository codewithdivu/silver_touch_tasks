#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int MAX_LEVEL = 16;

struct Node
{
    int key;
    int value;
    Node *forward[MAX_LEVEL + 1];

    Node(int k, int v, int level) : key(k), value(v)
    {

        for (int i = 0; i <= level; ++i)
        {
            forward[i] = nullptr;
        }
    }
};

class SkipList
{
private:
    Node *header;
    int level;

public:
    SkipList() : level(0)
    {

        header = new Node(-1, -1, MAX_LEVEL);

        for (int i = 0; i <= MAX_LEVEL; ++i)
        {
            header->forward[i] = nullptr;
        }
    }

    int randomLevel()
    {
        int lvl = 0;
        while ((rand() % 2 == 0) && (lvl < MAX_LEVEL))
        {
            lvl++;
        }
        return lvl;
    }

    void insert(int key, int value)
    {
        Node *update[MAX_LEVEL + 1];
        Node *current = header;

        for (int i = level; i >= 0; --i)
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
            for (int i = level + 1; i <= newLevel; ++i)
            {
                update[i] = header;
            }
            level = newLevel;
        }

        Node *newNode = new Node(key, value, newLevel);

        for (int i = 0; i <= newLevel; ++i)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        cout << "Inserted key " << key << " with value " << value << " at level " << newLevel << endl;
    }

    Node *search(int key)
    {
        Node *current = header;

        for (int i = level; i >= 0; --i)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        if (current != nullptr && current->key == key)
        {
            cout << "Found key " << key << " with value " << current->value << endl;
            return current;
        }
        else
        {
            cout << "Key " << key << " not found" << endl;
            return nullptr;
        }
    }

    void remove(int key)
    {
        Node *update[MAX_LEVEL + 1];
        Node *current = header;

        for (int i = level; i >= 0; --i)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->key == key)
        {
            for (int i = 0; i <= level; ++i)
            {
                if (update[i]->forward[i] != current)
                {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            delete current;

            while (level > 0 && header->forward[level] == nullptr)
            {
                level--;
            }

            cout << "Deleted key " << key << endl;
        }
        else
        {
            cout << "Key " << key << " not found for deletion" << endl;
        }
    }

    void print()
    {
        cout << "Skip List:" << endl;
        for (int i = level; i >= 0; --i)
        {
            Node *current = header->forward[i];
            cout << "Level " << i << ": ";
            while (current != nullptr)
            {
                cout << "(" << current->key << "," << current->value << ") ";
                current = current->forward[i];
            }
            cout << endl;
        }
    }
};

int main()
{

    srand(static_cast<unsigned>(time(nullptr)));

    SkipList skipList;

    skipList.insert(3, 30);
    skipList.insert(6, 60);
    skipList.insert(9, 90);
    skipList.insert(1, 10);
    skipList.insert(5, 50);

    skipList.print();

    skipList.search(6);
    skipList.search(8);

    skipList.remove(6);
    skipList.remove(8);

    skipList.print();

    return 0;
}
