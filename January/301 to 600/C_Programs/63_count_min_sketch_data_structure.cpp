#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class CountMinSketch
{
private:
    int width;
    int depth;
    vector<vector<int>> table;
    vector<pair<int, int>> hashParams; 

public:
    CountMinSketch(int w, int d) : width(w), depth(d), table(d, vector<int>(w, 0))
    {
        
        hashParams.resize(d);
        for (int i = 0; i < d; ++i)
        {
            hashParams[i] = {rand() % 100 + 1, rand() % 100 + 1}; 
        }
    }

    void update(const string &key, int value)
    {
        for (int i = 0; i < depth; ++i)
        {
            int hashValue = hash(key, hashParams[i].first, hashParams[i].second);
            table[i][hashValue] += value;
        }
    }

    int query(const string &key)
    {
        int minValue = INT_MAX;

        for (int i = 0; i < depth; ++i)
        {
            int hashValue = hash(key, hashParams[i].first, hashParams[i].second);
            minValue = min(minValue, table[i][hashValue]);
        }

        return minValue;
    }

private:
    int hash(const string &key, int a, int b)
    {
        std::hash<std::string> hashFunction;
        return static_cast<int>(hashFunction(key)) % width;
    }
};

int main()
{
    CountMinSketch countMinSketch(10, 3); 

    countMinSketch.update("apple", 2);
    countMinSketch.update("banana", 3);
    countMinSketch.update("apple", 1);

    cout << "Frequency of 'apple': " << countMinSketch.query("apple") << endl;
    cout << "Frequency of 'banana': " << countMinSketch.query("banana") << endl;

    return 0;
}
