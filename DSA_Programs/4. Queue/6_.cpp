#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x)
    {
        mainStack.push(x);
        if (minStack.empty() || x <= getMin())
        {
            minStack.push(x);
        }
    }

    void pop()
    {
        if (!mainStack.empty())
        {
            if (mainStack.top() == getMin())
            {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top()
    {
        if (!mainStack.empty())
        {
            return mainStack.top();
        }
        return -1;
    }

    int getMin()
    {
        if (!minStack.empty())
        {
            return minStack.top();
        }
        return -1;
    }
};

int main()
{
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl;

    minStack.push(2);
    minStack.push(1);
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl;

    return 0;
}
