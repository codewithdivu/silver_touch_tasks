#include <iostream>
#include <vector>
#include <atomic>
#include <random>
#include <climits>
using namespace std;

const int MAX_LEVEL = 10; 

template <typename T>
class Node {
public:
    T data;
    vector<atomic<Node<T>*>> next; 

    Node(T value, int level) : data(value), next(level + 1) {}
};

template <typename T>
class SkipList {
private:
    Node<T>* head;
    atomic<int> maxLevel;

    int randomLevel() const {
        int level = 0;
        while (level < MAX_LEVEL && rand() % 2 == 0) {
            level++;
        }
        return level;
    }

public:
    SkipList() : head(new Node<T>(INT_MIN, MAX_LEVEL)), maxLevel(0) {}

    void insert(T value) {
        vector<Node<T>*> preds(MAX_LEVEL + 1);
        vector<Node<T>*> succs(MAX_LEVEL + 1);

        int topLevel = randomLevel();
        Node<T>* newNode = new Node<T>(value, topLevel);

        for (int i = 0; i <= MAX_LEVEL; ++i) {
            preds[i] = head;
            succs[i] = nullptr;
        }

        for (int i = maxLevel; i >= 0; --i) {
            while (true) {
                Node<T>* curr = preds[i]->next[i].load();
                Node<T>* next = curr->next[i].load();

                if (curr == preds[i] && next == succs[i]) {
                    if (i <= topLevel) {
                        newNode->next[i].store(next);
                        if (curr->next[i].compare_exchange_weak(next, newNode)) {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                search(value, preds, succs);
            }
        }

        int oldMaxLevel = maxLevel.load();
        while (oldMaxLevel < topLevel) {
            maxLevel.compare_exchange_weak(oldMaxLevel, topLevel);
        }
    }

    bool remove(T value) {
        vector<Node<T>*> preds(MAX_LEVEL + 1);
        vector<Node<T>*> succs(MAX_LEVEL + 1);

        for (int i = maxLevel; i >= 0; --i) {
            while (true) {
                search(value, preds, succs);
                Node<T>* pred = preds[i];
                Node<T>* curr = succs[i];

                if (curr->data < value) {
                    break;
                }

                if (curr->data == value) {
                    for (int j = i; j >= 0; --j) {
                        Node<T>* next = curr->next[j].load();
                        if (pred->next[j].compare_exchange_weak(curr, next)) {
                            delete curr;
                        }
                    }

                    return true;
                }
            }
        }

        return false;
    }

    bool search(T value) const {
        vector<Node<T>*> preds(MAX_LEVEL + 1);
        vector<Node<T>*> succs(MAX_LEVEL + 1);

        search(value, preds, succs);

        Node<T>* foundNode = succs[0];
        return (foundNode != nullptr && foundNode->data == value);
    }

    void search(T value, vector<Node<T>*>& preds, vector<Node<T>*>& succs) const {
        for (int i = maxLevel; i >= 0; --i) {
            Node<T>* curr = head;
            while (true) {
                Node<T>* next = curr->next[i].load();
                while (next && next->data < value) {
                    curr = next;
                    next = curr->next[i].load();
                }

                preds[i] = curr;
                succs[i] = next;

                if (i == 0) {
                    break;
                }
            }
        }
    }

    void display() const {
        Node<T>* curr = head->next[0].load();
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next[0].load();
        }
        cout << endl;
    }
};

int main() {
    SkipList<int> skipList;

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(9);

    cout << "Skip List after insertions: ";
    skipList.display();

    skipList.remove(6);

    cout << "Skip List after removal of 6: ";
    skipList.display();

    bool found = skipList.search(7);
    cout << "Search for 7: " << (found ? "Found" : "Not Found") << endl;

    return 0;
}
