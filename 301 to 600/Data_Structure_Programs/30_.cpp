#include <iostream>
#include <vector>
#include <functional>
#include <bitset>

class BloomFilter
{
private:
    std::vector<bool> filter;
    std::vector<std::function<size_t(const std::string &)>> hashFunctions;
    size_t size;
    size_t numHashFunctions;

public:
    BloomFilter(size_t size, size_t numHashFunctions) : size(size), numHashFunctions(numHashFunctions)
    {
        filter.resize(size, false);

        hashFunctions.push_back(std::hash<std::string>());
        hashFunctions.push_back([](const std::string &s)
                                {
            size_t hash = 0;
            for (char c : s) {
                hash = (hash * 31) + static_cast<size_t>(c);
            }
            return hash; });
    }

    void add(const std::string &element)
    {
        for (const auto &hashFunction : hashFunctions)
        {
            size_t hash = hashFunction(element) % size;
            filter[hash] = true;
        }
    }

    bool possiblyContains(const std::string &element) const
    {
        for (const auto &hashFunction : hashFunctions)
        {
            size_t hash = hashFunction(element) % size;
            if (!filter[hash])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    BloomFilter bloomFilter(100, 2);

    bloomFilter.add("apple");
    bloomFilter.add("orange");
    bloomFilter.add("banana");

    std::cout << "Possibly contains 'apple': " << bloomFilter.possiblyContains("apple") << std::endl;
    std::cout << "Possibly contains 'grape': " << bloomFilter.possiblyContains("grape") << std::endl;
    std::cout << "Possibly contains 'banana': " << bloomFilter.possiblyContains("banana") << std::endl;

    return 0;
}
