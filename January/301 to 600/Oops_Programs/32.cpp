#include <iostream>
#include <atomic>
#include <memory>
using namespace std;

template <typename T>
class LockFreeQueue {
private:
    struct Node {
        T data;
        unique_ptr<Node> next;

        Node(T value) : data(value), next(nullptr) {}
    };

    atomic<Node*> head;
    atomic<Node*> tail;

public:
    LockFreeQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(T value) {
        auto newNode = make_unique<Node>(value);
        Node* oldTail = tail.exchange(newNode.get());
        if (oldTail) {
            oldTail->next = move(newNode);
        } else {
            head.store(newNode.get());
        }
    }

    bool dequeue(T& result) {
        Node* oldHead = head.load();
        if (!oldHead) {
            return false; 
        }

        head.store(oldHead->next.get());
        result = oldHead->data;
        return true;
    }
};

int main() {
    LockFreeQueue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);

    int value;
    queue.dequeue(value);
    cout << "Dequeued: " << value << endl;
    return 0;
}
