#include <bits/stdc++.h>
using namespace std;
#define n 7

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    bool isFull();
    bool isEmpty();
    void push(int x);
    int pop();
    int Top();
    int Bottom();
    int peek(int postion);
};

bool Stack::isFull()
{
    if (top == n - 1)
    {
        return true;
    }
    return false;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack is overFlow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is underFlow" << endl;
        return 0;
    }
    int x = arr[top];
    top--;
    return x;
}

int Stack::Top()
{
    if (isEmpty())
    {
        cout << "Stack has no elements" << endl;
        return 0;
    }
    int x = arr[top];
    return x;
}

int Stack::Bottom()
{
    if (isEmpty())
    {
        cout << "Stack has no elements" << endl;
        return 0;
    }
    int x = arr[0];
    return x;
}

int Stack ::peek(int position)
{
    if (position < 0)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        int val = arr[top - position + 1];
        return val;
    }
}

int main(int argc, char const *argv[])
{
    Stack s;

    s.push(12);
    s.push(54);
    s.push(64);
    s.push(87);
    s.push(110);
    s.push(135);
    s.push(150);

    cout << "stack top element is " << s.Top() << endl;
    cout << "stack bottom element is " << s.Bottom() << endl;

    cout << "Element at the " << 5 << " postion is " << s.peek(5) << endl;

    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    cout << "poped element is : " << s.pop() << endl;
    return 0;
}