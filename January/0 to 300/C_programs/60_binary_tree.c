#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = newNode(10);

    root->left = newNode(29);
    root->right = newNode(40);

    root->left->left = newNode(50);
    root->left->right = newNode(43);

    root->right->left = newNode(23);
    root->right->right = newNode(90);

    printf("inorder --> ");
    inorder(root);
    printf("\n");
    printf("preorder --> ");
    preorder(root);
    printf("\n");
    printf("postorder --> ");
    postorder(root);
    printf("\n");

    return 0;
}