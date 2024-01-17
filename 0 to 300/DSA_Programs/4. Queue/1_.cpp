#include <bits/stdc++.h>
using namespace std;
#define n 20

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    bool isFull();
    bool isEmpty();
    void Enqueue(int x);
    int Dequeue();
    int Peek();
};

bool Queue ::isFull()
{
    if (back == n - 1)
    {
        return true;
    }
    return false;
}

bool Queue ::isEmpty()
{
    if (front == -1 || front > back)
    {
        return true;
    }
    return false;
}

void Queue::Enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is OverFlow" << endl;
        return;
    }
    back++;
    arr[back] = x;
    if (front == -1)
    {
        front++;
    }
}

int Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is UnderFlow" << endl;
        return 0;
    }
    int l = arr[front];
    front++;
    return l;
}

int Queue::Peek()
{
    if (isEmpty())
    {
        cout << "Queue is UnderFlow" << endl;
        return 0;
    }
    return arr[front];
}

int main(int argc, char const *argv[])
{
    Queue q1;
    q1.Enqueue(12);
    q1.Enqueue(22);
    q1.Enqueue(32);
    q1.Enqueue(42);
    q1.Enqueue(52);

    cout << "Dequeued element is " << q1.Dequeue() << endl;
    cout << "Dequeued element is " << q1.Dequeue() << endl;
    cout << "Dequeued element is " << q1.Dequeue() << endl;

    cout << "Peek element of queue is " << q1.Peek() << endl;

    return 0;
}