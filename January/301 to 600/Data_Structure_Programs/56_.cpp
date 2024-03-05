#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
using namespace std;

template <typename T>
class DoubleEndedPriorityQueue
{
private:
    vector<T> maxHeap;
    vector<T> minHeap;

public:
    void insertMax(const T &value)
    {
        maxHeap.push_back(value);
        push_heap(maxHeap.begin(), maxHeap.end(), less<T>());
    }

    void insertMin(const T &value)
    {
        minHeap.push_back(value);
        push_heap(minHeap.begin(), minHeap.end(), greater<T>());
    }

    T extractMax()
    {
        if (maxHeap.empty())
        {
            throw runtime_error("DoubleEndedPriorityQueue is empty");
        }

        T maxValue = maxHeap.front();
        pop_heap(maxHeap.begin(), maxHeap.end(), less<T>());
        maxHeap.pop_back();
        return maxValue;
    }

    T extractMin()
    {
        if (minHeap.empty())
        {
            throw runtime_error("DoubleEndedPriorityQueue is empty");
        }

        T minValue = minHeap.front();
        pop_heap(minHeap.begin(), minHeap.end(), greater<T>());
        minHeap.pop_back();
        return minValue;
    }

    bool isEmpty() const
    {
        return maxHeap.empty() && minHeap.empty();
    }
};

int main()
{
    DoubleEndedPriorityQueue<int> depq;

    depq.insertMax(5);
    depq.insertMax(3);
    depq.insertMin(7);
    depq.insertMin(2);

    cout << "Max value: " << depq.extractMax() << endl;
    cout << "Min value: " << depq.extractMin() << endl;

    return 0;
}
