#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MemoryPool {
public:
    MemoryPool(size_t block_size, size_t pool_size) : block_size(block_size), pool_size(pool_size) {
        // Allocate a pool of memory
        pool = new char[block_size * pool_size];
        
        // Initialize the free list
        for (size_t i = 0; i < pool_size; ++i) {
            free_list.push_back(pool + i * block_size);
        }
    }

    ~MemoryPool() {
        delete[] pool;
    }

    void* allocate() {
        if (free_list.empty()) {
            throw bad_alloc();
        }

        void* block = free_list.back();
        free_list.pop_back();
        return block;
    }

    void deallocate(void* block) {
        free_list.push_back(block);
    }

private:
    size_t block_size;
    size_t pool_size;
    char* pool;
    vector<void*> free_list;
};

int main() {
    // Example usage
    MemoryPool pool(sizeof(int), 10);

    int* a = static_cast<int*>(pool.allocate());
    int* b = static_cast<int*>(pool.allocate());

    *a = 42;
    *b = 23;

    cout << "a: " << *a << ", b: " << *b << endl;

    pool.deallocate(a);
    pool.deallocate(b);

    return 0;
}
