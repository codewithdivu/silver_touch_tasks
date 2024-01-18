#include <iostream>
#include <vector>
#include <functional>
#include <bitset>
using namespace std;

class BloomFilter
{
private:
    vector<bool> bitArray;
    vector<function<size_t(const string &)>> hashFunctions;
    size_t size;
    size_t numHashFunctions;

public:
    BloomFilter(size_t size, size_t numHashFunctions) : size(size), numHashFunctions(numHashFunctions)
    {
        bitArray.resize(size, false);

        for (size_t i = 0; i < numHashFunctions; ++i)
        {
            hashFunctions.emplace_back([i](const string &s)
                                       { return hash<string>{}(s + to_string(i)); });
        }
    }

    void insert(const string &key)
    {
        for (auto &hashFunction : hashFunctions)
        {
            size_t hashValue = hashFunction(key) % size;
            bitArray[hashValue] = true;
        }
    }

    bool contains(const string &key) const
    {
        for (auto &hashFunction : hashFunctions)
        {
            size_t hashValue = hashFunction(key) % size;
            if (!bitArray[hashValue])
            {

                return false;
            }
        }

        return true;
    }
};

int main()
{

    size_t filterSize = 100;
    size_t numHashFunctions = 3;

    BloomFilter bloomFilter(filterSize, numHashFunctions);

    bloomFilter.insert("apple");
    bloomFilter.insert("banana");
    bloomFilter.insert("orange");

    cout << "Contains apple? " << (bloomFilter.contains("apple") ? "Yes" : "No") << endl;
    cout << "Contains grape? " << (bloomFilter.contains("grape") ? "Yes" : "No") << endl;

    return 0;
}
