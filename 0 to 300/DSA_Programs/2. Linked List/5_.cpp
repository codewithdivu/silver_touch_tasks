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

int getLength(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void intersection(node *head1, node *head2)
{
    node *temp1;
    node *temp2;

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int distance;

    if (len1 > len2)
    {
        distance = len1 - len2;
        temp1 = head1;
        temp2 = head2;
    }
    else
    {
        distance = len2 - len1;
        temp1 = head2;
        temp2 = head1;
    }

    while (distance--)
    {
        head1 = head1->next;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            cout << "Intersection point is " << temp1->data << endl;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    cout << "there is no Intersection point" << endl;
}

int main(int argc, char const *argv[])
{
    node *head1 = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *fourth = new node(4);
    node *fifth = new node(5);

    node *head2 = new node(8);
    node *boby = new node(9);

    head1->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    head2->next = boby;
    boby->next = fourth;

    intersection(head1, head2);

    return 0;
}