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
node *reverse(node *&head)
{
    node *curr = head;
    node *prev;
    node *nextPtr;
    while (curr != NULL)
    {
        nextPtr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextPtr;
    }
    return prev;
}

node *sum(node *head1, node *head2)
{
    node *t1 = head1;
    node *t2 = head2;
    int carry = 0;
    int sum;
    node *newNode = new node(0);
    node *temp = newNode;

    while (t1 || t2 || carry)
    {
        sum = 0;
        if (t1)
        {
            sum = sum + t1->data;
            t1 = t1->next;
        }
        if (t2)
        {
            sum += t2->data;
            t2 = t2->next;
        }
        sum = sum + carry;

        temp->next = new node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
    }
    return newNode->next;
}

int main(int argc, char const *argv[])
{
    node *head1 = new node(1);
    node *second1 = new node(2);
    node *third1 = new node(3);

    head1->next = second1;
    second1->next = third1;
    third1->next = NULL;

    node *head2 = new node(6);
    node *second2 = new node(5);
    node *third2 = new node(4);

    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;

    node *ans = sum(head1, head2);

    Traversal(ans);

    return 0;
}