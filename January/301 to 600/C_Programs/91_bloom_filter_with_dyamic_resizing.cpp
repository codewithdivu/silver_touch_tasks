#include <iostream>
#include <vector>
#include <bitset>
#include <functional>

class DynamicBloomFilter
{
private:
    std::vector<bool> bloomFilter;
    std::vector<std::function<size_t(const std::string &)>> hashFunctions;
    size_t numHashFunctions;
    size_t size;
    size_t elementsCount;
    double falsePositiveRateThreshold;

public:
    DynamicBloomFilter(size_t initialSize, size_t numHashFunctions, double falsePositiveRateThreshold)
        : bloomFilter(initialSize, false),
          numHashFunctions(numHashFunctions),
          size(initialSize),
          elementsCount(0),
          falsePositiveRateThreshold(falsePositiveRateThreshold)
    {
        initializeHashFunctions();
    }

    void initializeHashFunctions()
    {
        for (size_t i = 0; i < numHashFunctions; ++i)
        {
            hashFunctions.emplace_back([i](const std::string &s)
                                       { return std::hash<std::string>{}(s + std::to_string(i)); });
        }
    }

    void insert(const std::string &key)
    {

        if ((static_cast<double>(elementsCount) / size) > falsePositiveRateThreshold)
        {
            resize();
        }

        for (auto &hashFunction : hashFunctions)
        {
            size_t index = hashFunction(key) % size;
            bloomFilter[index] = true;
        }

        elementsCount++;
    }

    bool contains(const std::string &key) const
    {
        for (auto &hashFunction : hashFunctions)
        {
            size_t index = hashFunction(key) % size;
            if (!bloomFilter[index])
            {
                return false;
            }
        }
        return true;
    }

    void resize()
    {
        size *= 2;
        elementsCount = 0;
        bloomFilter.resize(size, false);
    }
};

int main()
{

    size_t initialSize = 10;
    size_t numHashFunctions = 3;
    double falsePositiveRateThreshold = 0.1;

    DynamicBloomFilter bloomFilter(initialSize, numHashFunctions, falsePositiveRateThreshold);

    bloomFilter.insert("apple");
    bloomFilter.insert("banana");
    bloomFilter.insert("orange");

    std::cout << "Contains apple? " << (bloomFilter.contains("apple") ? "Possibly" : "No") << std::endl;
    std::cout << "Contains grape? " << (bloomFilter.contains("grape") ? "Possibly" : "No") << std::endl;

    return 0;
}
