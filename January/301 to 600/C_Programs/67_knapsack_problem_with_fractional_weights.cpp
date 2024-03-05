#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
    double valuePerWeight;

    Item(int w, int v) : weight(w), value(v)
    {
        valuePerWeight = static_cast<double>(value) / weight;
    }
};

bool compareItems(const Item &item1, const Item &item2)
{
    return item1.valuePerWeight > item2.valuePerWeight;
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const Item &item : items)
    {
        if (remainingCapacity >= item.weight)
        {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        }
        else
        {
            totalValue += (static_cast<double>(remainingCapacity) / item.weight) * item.value;
            break;
        }
    }

    return totalValue;
}

int main()
{

    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
