#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>
using namespace std;

class Singleton {
private:
    Singleton() {}

    static atomic<Singleton*> instance;
    static mutex creationMutex;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (!instance.load(memory_order_acquire)) {
            lock_guard<mutex> lock(creationMutex);
            if (!instance.load(memory_order_relaxed)) {
                instance.store(new Singleton(), memory_order_release);
            }
        }
        return instance.load(memory_order_relaxed);
    }

    void performTransaction() {
        
        cout << "Transaction performed by Singleton instance" << endl;
    }
};

atomic<Singleton*> Singleton::instance(nullptr);
mutex Singleton::creationMutex;

void threadFunction(int id) {
    Singleton* singleton = Singleton::getInstance();
    
    singleton->performTransaction();
    cout << "Thread " << id << " completed." << endl;
}

int main() {
    const int numThreads = 5;
    thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(threadFunction, i);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}