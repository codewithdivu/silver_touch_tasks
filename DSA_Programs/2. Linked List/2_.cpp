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

void findMiddle(node *head)
{
    node *temp = head;
    node *femp = head->next;

    while (temp != NULL && femp->next != NULL)
    {
        temp = temp->next;
        femp = femp->next->next;
    }

    cout << "Middle element is " << temp->data << endl;
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
    cout << endl;
    findMiddle(head);

    return 0;
}