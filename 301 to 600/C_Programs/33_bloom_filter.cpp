#include <iostream>
#include <bitset>
#include <vector>
#include <functional>

using namespace std;

class BloomFilter
{
private:
    bitset<10000> filter;
    vector<function<size_t(const string &)>> hashFunctions;

public:
    BloomFilter()
    {

        hashFunctions.push_back(hash<string>{});
        hashFunctions.push_back(hash<string>{});
        hashFunctions.push_back([](const string &s)
                                {        
            size_t hashVal = 0;
            for (char c : s) {
                hashVal = (hashVal * 131) + c;
            }
            return hashVal; });
    }

    void add(const string &element)
    {
        for (const auto &hashFunction : hashFunctions)
        {
            size_t index = hashFunction(element) % filter.size();
            filter[index] = true;
        }
    }

    bool contains(const string &element)
    {
        for (const auto &hashFunction : hashFunctions)
        {
            size_t index = hashFunction(element) % filter.size();
            if (!filter[index])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    BloomFilter bloomFilter;

    bloomFilter.add("apple");
    bloomFilter.add("banana");
    bloomFilter.add("orange");

    cout << "Contains 'apple': " << bloomFilter.contains("apple") << endl;
    cout << "Contains 'grape': " << bloomFilter.contains("grape") << endl;

    return 0;
}
