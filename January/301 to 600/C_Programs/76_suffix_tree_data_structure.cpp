#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int start;
    int *end;
    Node *parent;
    unordered_map<char, Node *> children;
    Node *suffixLink;
    int suffixIndex;

    Node(int start, int *end, Node *parent = nullptr) : start(start), end(end), parent(parent), suffixLink(nullptr), suffixIndex(-1) {}

    int edgeLength(int currentIdx)
    {
        return min(*end, currentIdx + 1) - start;
    }
};

class SuffixTree
{
public:
    string text;
    Node *root;
    Node *activeNode;
    int activeEdge;
    int activeLength;
    int remainingSuffixCount;
    int leafEnd;
    int *rootEnd;
    int currentIndex;

    SuffixTree(const string &input) : text(input), root(nullptr), activeNode(nullptr), activeEdge(-1),
                                      activeLength(0), remainingSuffixCount(0), leafEnd(-1), currentIndex(-1)
    {
        rootEnd = new int(-1);
        root = new Node(-1, rootEnd);
        activeNode = root;

        activeEdge = -1;
        activeLength = 0;

        for (currentIndex = 0; currentIndex < text.length(); ++currentIndex)
        {
            extendTree();
        }

        setSuffixIndex(root, 0, currentIndex - 1);
    }

    void extendTree()
    {
        leafEnd = currentIndex;
        ++remainingSuffixCount;

        Node *lastInternalNode = nullptr;

        while (remainingSuffixCount > 0)
        {
            if (activeLength == 0)
            {
                activeEdge = currentIndex;
            }

            if (activeNode->children.find(text[activeEdge]) == activeNode->children.end())
            {
                activeNode->children[text[activeEdge]] = new Node(currentIndex, &leafEnd, activeNode);
                addSuffixLink(activeNode);
            }
            else
            {
                Node *next = activeNode->children[text[activeEdge]];
                if (walkDown(next))
                    continue;
                if (text[next->start + activeLength] == text[currentIndex])
                {
                    ++activeLength;
                    addSuffixLink(activeNode);
                    break;
                }

                splitEdge(next);

                if (lastInternalNode != nullptr)
                {
                    lastInternalNode->suffixLink = next;
                }

                lastInternalNode = next;
            }

            --remainingSuffixCount;
            if (activeNode == root && activeLength > 0)
            {
                --activeLength;
                activeEdge = currentIndex - remainingSuffixCount + 1;
            }
            else if (activeNode != root)
            {
                activeNode = activeNode->suffixLink != nullptr ? activeNode->suffixLink : root;
            }
        }
    }

    bool walkDown(Node *next)
    {
        if (activeLength >= next->edgeLength(currentIndex))
        {
            activeEdge += next->edgeLength(currentIndex);
            activeLength -= next->edgeLength(currentIndex);
            activeNode = next;
            return true;
        }
        return false;
    }

    void splitEdge(Node *next)
    {
        Node *split = new Node(next->start, new int(next->start + activeLength - 1), activeNode);
        activeNode->children[text[activeEdge]] = split;
        next->start += activeLength;
        split->children[text[next->start]] = next;

        next->parent = split;

        split->suffixLink = nullptr;

        // Add the new leaf node and edge
        split->children[text[currentIndex]] = new Node(currentIndex, &leafEnd, split);
    }

    void addSuffixLink(Node *node)
    {
        if (activeNode != root)
        {
            activeNode->suffixLink = node;
        }
        activeNode = node;
    }

    void setSuffixIndex(Node *node, int depth, int currentIndex)
    {
        if (node == nullptr)
            return;

        bool isLeaf = true;
        for (const auto &child : node->children)
        {
            isLeaf = false;
            setSuffixIndex(child.second, depth + child.second->edgeLength(currentIndex) - 1, currentIndex);
        }

        if (isLeaf)
        {
            node->suffixIndex = currentIndex - depth;
        }
    }

    void printSuffixTree(Node *node, int level = 0)
    {
        if (node == nullptr)
            return;

        for (int i = 0; i < level; ++i)
            cout << "  ";
        if (node->start == -1)
        {
            cout << "Root" << endl;
        }
        else
        {
            cout << "Edge: [" << node->start << ", " << *node->end << "], Suffix Index: " << node->suffixIndex << endl;
            for (int i = node->start; i <= *node->end && i < text.length(); ++i)
            {
                cout << text[i];
            }
            cout << endl;
        }

        for (const auto &child : node->children)
        {
            printSuffixTree(child.second, level + 1);
        }
    }
};

int main()
{
    string text;
    cout << "Enter a string: ";
    cin >> text;

    SuffixTree suffixTree(text);

    cout << "\nSuffix Tree:\n";
    suffixTree.printSuffixTree(suffixTree.root);

    return 0;
}
