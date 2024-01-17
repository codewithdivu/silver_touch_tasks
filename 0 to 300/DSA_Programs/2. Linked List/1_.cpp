#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Traversal(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

node *InsertAtEnd(node *head, int val)
{
    node *temp = head;
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node *InsertAtFirst(node *head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
    return head;
}

node *InsertAfterNode(node *head, node *preNode, int val)
{
    node *newNode = new node(val);
    newNode->next = preNode->next;
    preNode->next = newNode;
    return head;
}

node *InsertAtIndex(node *head, int index, int val)
{
    node *temp = head;
    node *newNode = new node(val);
    int i = 0;

    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// ----------------Deletion---------------

node *DeleteAtFirst(node *head)
{
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

node *DeleteAtEnd(node *head)
{
    node *p = head;
    node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

node *DeleteAtIndex(node *head, int index)
{
    node *p = head;
    node *q = p->next;
    if (index == 0)
    {
        return head = head->next;
    }
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node *DeleteAtValue(node *head, int value)
{
    node *p = head;
    node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        return head;
    }
    else
    {
        cout << "Value is not found in singly linked list" << endl;
        return head;
    }
}

int main(int argc, char const *argv[])
{
    node *head = new node(5);
    node *second = new node(7);
    node *third = new node(9);
    node *last = new node(11);

    head->next = second;
    second->next = third;
    third->next = last;

    Traversal(head);
    return 0;
}