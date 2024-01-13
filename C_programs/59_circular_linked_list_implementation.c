#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Traversal(struct node *head)
{
    struct node *temp = head;

    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main(int argc, char const *argv[])
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 39;
    third->next = head;

    Traversal(head);

    return 0;
}
