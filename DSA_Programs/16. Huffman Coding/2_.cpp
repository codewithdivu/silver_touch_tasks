#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class cmp
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

void traverse(node *root, vector<string> &answer, string temp)
{
    if (root->left == NULL && root->right == NULL)
    {
        answer.push_back(temp);
        return;
    }
    traverse(root->left, answer, temp + '0');
    traverse(root->right, answer, temp + '1');
}

void decodeHuffman(node *root, string encodedStr)
{
    node *current = root;
    cout << "Decoded string: ";
    for (char bit : encodedStr)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL)
        {
            cout << current->data;
            current = root;
        }
    }
    cout << endl;
}

int main()
{
    string str = "abcdef";
    vector<int> frequency = {5, 9, 12, 13, 16, 45};

    priority_queue<node *, vector<node *>, cmp> pq;

    for (int i = 0; i < frequency.size(); i++)
    {
        node *newNode = new node(frequency[i]);
        pq.push(newNode);
    }

    while (!pq.empty())
    {
        node *left = pq.top();
        pq.pop();
        node *right = pq.top();
        pq.pop();

        node *newNode = new node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    node *root = pq.top();
    string temp = "";
    vector<string> answer;
    traverse(root, answer, temp);

    cout << "Huffman Codes:" << endl;
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << ": " << answer[i] << endl;
    }

    string encodedStr = "1100";
    decodeHuffman(root, encodedStr);

    return 0;
}
