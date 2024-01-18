#include <iostream>
#include <set>
#include <list>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class DoubleEndedPriorityQueue {
private:
    set<pair<T, typename list<T>::iterator>> elements;
    list<T> order;

public:
    void pushFront(const T& value) {
        auto it = order.insert(order.begin(), value);
        elements.insert({value, it});
    }

    void pushBack(const T& value) {
        auto it = order.insert(order.end(), value);
        elements.insert({value, it});
    }

    void popFront() {
        if (!order.empty()) {
            T frontValue = order.front();
            auto it = elements.find({frontValue, order.begin()});
            elements.erase(it);
            order.pop_front();
        }
    }

    void popBack() {
        if (!order.empty()) {
            T backValue = order.back();
            auto it = elements.find({backValue, prev(order.end())});
            elements.erase(it);
            order.pop_back();
        }
    }

    const T& front() const {
        return order.front();
    }

    const T& back() const {
        return order.back();
    }

    bool empty() const {
        return order.empty();
    }
};

int main() {
    
    DoubleEndedPriorityQueue<int> dq;

    dq.pushFront(3);
    dq.pushBack(5);
    dq.pushFront(1);

    cout << "Front: " << dq.front() << endl;  
    cout << "Back: " << dq.back() << endl;    

    dq.popFront();

    cout << "Front after popFront: " << dq.front() << endl;  

    dq.popBack();

    cout << "Back after popBack: " << dq.back() << endl;    

    return 0;
}
