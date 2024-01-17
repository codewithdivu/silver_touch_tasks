#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseFirstKElements(queue<int> &q, int k)
{
    if (k <= 0 || k > q.size())
    {
        cout << "Invalid value of k\n";
        return;
    }

    stack<int> s;

    for (int i = 0; i < k; ++i)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < q.size() - k; ++i)
    {
        q.push(q.front());
        q.pop();
    }
}

void displayQueue(const queue<int> &q)
{
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> myQueue;

    for (int i = 1; i <= 5; ++i)
    {
        myQueue.push(i);
    }

    int k = 3;
    cout << "Original Queue: ";
    displayQueue(myQueue);

    reverseFirstKElements(myQueue, k);

    cout << "Queue after reversing first " << k << " elements: ";
    displayQueue(myQueue);

    return 0;
}
