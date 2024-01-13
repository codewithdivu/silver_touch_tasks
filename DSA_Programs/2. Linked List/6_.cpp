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

node *removeDuplicates(node *head)
{
    node *temp = head;
    set<int> s;
    while (temp != NULL)
    {
        s.insert(temp->data);
        temp = temp->next;
    }

    node *dummy = new node(10);
    node *femp = dummy;

    for (auto it : s)
    {
        node *nwNode = new node(it);
        femp->next = nwNode;
        femp = femp->next;
    }

    return dummy->next;
}

int main(int argc, char const *argv[])
{
    node *head = new node(5);
    node *second = new node(1);
    node *third = new node(3);
    node *fourth = new node(2);
    node *fifth = new node(3);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    node *ptr = removeDuplicates(head);

    Traversal(ptr);

    return 0;
}