#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;

template <typename RandomIt>
void parallelSort(RandomIt begin, RandomIt end, size_t numThreads) {
    auto size = distance(begin, end);
    auto chunkSize = size / numThreads;
    
    vector<thread> threads;

    for (size_t i = 0; i < numThreads; ++i) {
        auto threadBegin = begin + i * chunkSize;
        auto threadEnd = (i == numThreads - 1) ? end : threadBegin + chunkSize;
        threads.emplace_back(sort<RandomIt>, threadBegin, threadEnd);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    // Merge sorted chunks
    inplace_merge(begin, begin + chunkSize, end);
}

int main() {
    vector<int> data = {5, 2, 9, 1, 5, 6};

    // Sort using parallel algorithm
    parallelSort(data.begin(), data.end(), thread::hardware_concurrency());

    // Print the sorted result
    for (const auto& element : data) {
        cout << element << " ";
    }

    return 0;
}
