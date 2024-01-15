#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &arr)
{
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);

    for (int num : arr)
    {
        count[num]++;
    }

    for (int i = 1; i <= maxElement; ++i)
    {
        count[i] += count[i - 1];
    }

    vector<int> result(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (size_t i = 0; i < arr.size(); ++i)
    {
        arr[i] = result[i];
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
