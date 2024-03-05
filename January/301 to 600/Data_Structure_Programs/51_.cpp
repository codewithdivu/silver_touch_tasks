#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
using namespace std;

class SkipNode
{
public:
    int value;
    vector<SkipNode *> next;

    SkipNode(int val, int level) : value(val), next(level + 1, nullptr) {}
};

class SkipGraph
{
public:
    SkipGraph(int maxLevels) : maxLevels(maxLevels), head(new SkipNode(numeric_limits<int>::min(), maxLevels)) {}

    void insert(int value);
    bool search(int value);
    void printSkipGraph();

private:
    int getRandomLevel();
    SkipNode *findNode(int value);
    int maxLevels;
    SkipNode *head;
};

void SkipGraph::insert(int value)
{
    int level = getRandomLevel();

    SkipNode *newNode = new SkipNode(value, level);

    SkipNode *current = head;
    vector<SkipNode *> update(head->next);

    for (int i = level; i >= 0; --i)
    {
        while (current->next[i] != nullptr && current->next[i]->value < value)
        {
            current = current->next[i];
        }
        update[i] = current;
    }

    for (int i = 0; i <= level; ++i)
    {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
}

bool SkipGraph::search(int value)
{
    SkipNode *current = head;

    for (int i = maxLevels; i >= 0; --i)
    {
        while (current->next[i] != nullptr && current->next[i]->value < value)
        {
            current = current->next[i];
        }
    }

    current = current->next[0];

    return (current != nullptr && current->value == value);
}

void SkipGraph::printSkipGraph()
{
    for (int i = maxLevels; i >= 0; --i)
    {
        SkipNode *current = head;
        cout << "Level " << i << ": ";
        while (current->next[i] != nullptr)
        {
            cout << current->next[i]->value << " ";
            current = current->next[i];
        }
        cout << endl;
    }
}

int SkipGraph::getRandomLevel()
{
    int level = 0;
    while (rand() % 2 == 0 && level < maxLevels)
    {
        level++;
    }
    return level;
}

int main()
{
    srand(time(nullptr));

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
    skipGraph.insert(29);

    cout << "Skip Graph:" << endl;
    skipGraph.printSkipGraph();

    int searchValue = 17;
    if (skipGraph.search(searchValue))
    {
        cout << "Element " << searchValue << " found in the skip graph." << endl;
    }
    else
    {
        cout << "Element " << searchValue << " not found in the skip graph." << endl;
    }

    return 0;
}
