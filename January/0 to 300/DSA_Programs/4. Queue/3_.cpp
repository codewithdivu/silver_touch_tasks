#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int capacity)
    {
        size = capacity + 1;
        arr = new int[size];
        front = rear = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return front == rear;
    }

    bool isFull() const
    {
        return (rear + 1) % size == front;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % size;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }

        front = (front + 1) % size;
    }

    int frontValue() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No front value." << endl;
            return -1;
        }

        return arr[front];
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != rear);

        cout << endl;
    }
};

int main()
{
    CircularQueue myQueue(5);

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);

    myQueue.display();

    cout << "Front value: " << myQueue.frontValue() << endl;

    myQueue.dequeue();
    myQueue.display();

    myQueue.enqueue(50);
    myQueue.enqueue(60);
    myQueue.display();

    myQueue.enqueue(70);

    return 0;
}
