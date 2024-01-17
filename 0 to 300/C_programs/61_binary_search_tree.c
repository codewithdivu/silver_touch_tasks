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

// recursive approach

struct node *searchInBST(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key > root->data)
    {
        return searchInBST(root->right, key);
    }
    else
    {
        return searchInBST(root->left, key);
    }
}

// iterative approach

struct node *IterativeSearchInBST(struct node *root, int key)
{

    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

// insertion

void insertInBST(struct node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            return;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    struct node *insertNode = newNode(key);

    if (key > prev->data)
    {
        prev->right = insertNode;
    }
    else
    {
        prev->left = insertNode;
    }
}

int main()
{
    struct node *root = newNode(10);

    root->left = newNode(8);
    root->right = newNode(20);

    root->left->left = newNode(5);
    root->left->right = newNode(9);

    root->right->left = newNode(18);
    root->right->right = newNode(25);

    printf("'\n");

    struct node *ptr = searchInBST(root, 19);

    if (ptr != NULL)
    {
        printf("key is there is BST %d", ptr->data);
    }
    else
    {
        printf("Key is not-found in BST");
    }

    printf("'\n");

    printf("inorder --> ");
    inorder(root);
    printf("\n");
    printf("preorder --> ");
    preorder(root);
    printf("\n");
    printf("postorder --> ");
    postorder(root);
    printf("\n");

    insertInBST(root, 8);

    return 0;
}