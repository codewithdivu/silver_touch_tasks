#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode *sortedArrayToBST(const vector<int> &sortedArray, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    TreeNode *root = new TreeNode(sortedArray[mid]);

    root->left = sortedArrayToBST(sortedArray, start, mid - 1);
    root->right = sortedArrayToBST(sortedArray, mid + 1, end);

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    TreeNode *root = sortedArrayToBST(sortedArray, 0, sortedArray.size() - 1);

    cout << "Inorder traversal of the balanced BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
