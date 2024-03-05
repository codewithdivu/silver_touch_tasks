#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    string value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

bool isOperator(const string &s)
{
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

TreeNode *buildExpressionTree(const vector<string> &postfix)
{
    stack<TreeNode *> st;

    for (const string &token : postfix)
    {
        if (!isOperator(token))
        {

            st.push(new TreeNode(token));
        }
        else
        {

            TreeNode *operand2 = st.top();
            st.pop();
            TreeNode *operand1 = st.top();
            st.pop();

            TreeNode *newNode = new TreeNode(token);
            newNode->left = operand1;
            newNode->right = operand2;

            st.push(newNode);
        }
    }

    return st.top();
}

void inorderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

void deleteExpressionTree(TreeNode *root)
{
    if (root != nullptr)
    {
        deleteExpressionTree(root->left);
        deleteExpressionTree(root->right);
        delete root;
    }
}

int main()
{

    vector<string> postfixExpression = {"2", "3", "4", "*", "+"};

    TreeNode *expressionTree = buildExpressionTree(postfixExpression);

    cout << "In-order Traversal of Expression Tree: ";
    inorderTraversal(expressionTree);
    cout << endl;

    deleteExpressionTree(expressionTree);

    return 0;
}
