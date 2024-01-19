#include <iostream>
#include <queue>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

template <typename T>
class LockFreeQueue
{
public:
    LockFreeQueue() {}

    void enqueue(const T &item)
    {
        Node *newNode = new Node(item);
        Node *tail;
        Node *next;

        while (true)
        {
            tail = tail_.load(memory_order_relaxed);
            next = tail->next.load(memory_order_relaxed);

            if (tail == tail_.load(memory_order_relaxed))
            {
                if (next == nullptr)
                {
                    if (tail->next.compare_exchange_weak(next, newNode))
                    {
                        break;
                    }
                }
                else
                {
                    tail_.compare_exchange_weak(tail, next);
                }
            }
        }

        tail_.compare_exchange_strong(tail, newNode);
    }

    bool dequeue(T &item)
    {
        Node *head;
        Node *tail;
        Node *next;

        while (true)
        {
            head = head_.load(memory_order_relaxed);
            tail = tail_.load(memory_order_relaxed);
            next = head->next.load(memory_order_relaxed);

            if (head == head_.load(memory_order_relaxed))
            {
                if (head == tail)
                {
                    if (next == nullptr)
                    {
                        return false;
                    }
                    tail_.compare_exchange_weak(tail, next);
                }
                else
                {
                    item = next->data;
                    if (head_.compare_exchange_weak(head, next))
                    {
                        delete head;
                        return true;
                    }
                }
            }
        }
    }

private:
    struct Node
    {
        T data;
        atomic<Node *> next;

        Node(const T &item) : data(item), next(nullptr) {}
    };

    atomic<Node *> head_;
    atomic<Node *> tail_;
};

// Example usage:
LockFreeQueue<int> queuee;

void producer()
{
    for (int i = 0; i < 10; ++i)
    {
        queuee.enqueue(i);
    }
}

void consumer(int id)
{
    int item;
    while (queuee.dequeue(item))
        cout << "Consumer " << id << " dequeued: " << item << endl;
}

int main()
{
    vector<thread> threads;
    threads.emplace_back(producer);
    for (int i = 0; i < 2; ++i)
        threads.emplace_back(consumer, i);

    for (auto &thread : threads)
        thread.join();

    return 0;
}