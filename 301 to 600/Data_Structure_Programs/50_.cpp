#include <iostream>
#include <cstdint>
using namespace std;

class Node
{
public:
    int data;
    Node *xorPointer;

    Node(int data) : data(data), xorPointer(nullptr) {}
};

class XORLinkedList
{
private:
    Node *head;

    Node *XOR(Node *a, Node *b)
    {
        return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
    }

public:
    XORLinkedList() : head(nullptr) {}

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->xorPointer = XOR(nullptr, head);

        if (head != nullptr)
        {
            head->xorPointer = XOR(newNode, head->xorPointer);
        }

        head = newNode;
    }

    void traverse()
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next;

        cout << "XOR Linked List: ";

        while (current != nullptr)
        {
            cout << current->data << " ";

            next = XOR(prev, current->xorPointer);
            prev = current;
            current = next;
        }

        cout << endl;
    }
};

int main()
{

    XORLinkedList xorList;

    xorList.insert(10);
    xorList.insert(20);
    xorList.insert(30);
    xorList.insert(40);

    xorList.traverse();

    return 0;
}
