#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

class BloomFilter
{
private:
    vector<bool> bitArray;
    int size;
    int numHashFunctions;

public:
    BloomFilter(int setSize, double falsePositivesProbability)
    {
        size = computeOptimalSize(setSize, falsePositivesProbability);
        numHashFunctions = computeOptimalHashFunctions(setSize, size);
        bitArray.resize(size, false);
    }

    void add(const string &element)
    {
        for (int i = 0; i < numHashFunctions; ++i)
        {
            int hashValue = hashFunction(element, i);
            bitArray[hashValue] = true;
        }
    }

    bool contains(const string &element) const
    {
        for (int i = 0; i < numHashFunctions; ++i)
        {
            int hashValue = hashFunction(element, i);
            if (!bitArray[hashValue])
            {
                return false;
            }
        }
        return true;
    }

    double estimateFalsePositivesProbability(int setSize) const
    {
        return pow(1 - exp(-numHashFunctions * setSize / static_cast<double>(size)), numHashFunctions);
    }

private:
    static int computeOptimalSize(int setSize, double falsePositivesProbability)
    {
        return static_cast<int>(-setSize * log(falsePositivesProbability) / pow(log(2), 2));
    }

    static int computeOptimalHashFunctions(int setSize, int size)
    {
        return static_cast<int>((size / setSize) * log(2));
    }

    int hashFunction(const string &element, int index) const
    {

        hash<string> hashFunction;
        return (hashFunction(element) ^ index) % size;
    }
};

int main()
{

    int setSize = 1000;
    double falsePositivesProbability = 0.01;

    BloomFilter bloomFilter(setSize, falsePositivesProbability);

    bloomFilter.add("apple");
    bloomFilter.add("banana");
    bloomFilter.add("orange");

    cout << "Contains 'apple': " << bloomFilter.contains("apple") << endl;
    cout << "Contains 'grape': " << bloomFilter.contains("grape") << endl;

    double estimatedFalsePositivesProbability = bloomFilter.estimateFalsePositivesProbability(setSize);
    cout << "Estimated False Positives Probability: " << estimatedFalsePositivesProbability << endl;

    return 0;
}
