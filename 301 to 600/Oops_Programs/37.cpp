#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
using namespace std;

template <typename T>
class HazardPointer {
private:
    atomic<T*> pointer;

public:
    HazardPointer() : pointer(nullptr) {}

    void set(T* value) {
        pointer.store(value, memory_order_release);
    }

    T* get() const {
        return pointer.load(memory_order_acquire);
    }
};

template <typename T>
class ThreadSafeDataStructure {
private:
    vector<T> data;
    HazardPointer<T> hazardPointer;

public:
    void insert(const T& item) {
        
        

        
        cout << "Thread " << this_thread::get_id() << " setting hazard pointer to new item." << endl;
        hazardPointer.set(new T(item));
        cout << "Thread " << this_thread::get_id() << " set hazard pointer to new item." << endl;
    }

    
};


void exampleUsage() {
    ThreadSafeDataStructure<int> threadSafeDataStructure;
    threadSafeDataStructure.insert(42);
    
}

int main() {
    ThreadSafeDataStructure<int> threadSafeDataStructure;

    thread t1([&]() {
        threadSafeDataStructure.insert(42);
        cout << "Thread " << this_thread::get_id() << " inserted 42." << endl;
        
    });

    thread t2([&]() {
        threadSafeDataStructure.insert(87);
        cout << "Thread " << this_thread::get_id() << " inserted 87." << endl;
        
    });

    t1.join();
    t2.join();

    return 0;
}