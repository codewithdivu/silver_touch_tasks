#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int SELECT_SAMPLE_SIZE = 5; 

int partition(vector<int> &arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); 
    int storeIndex = left;

    for (int i = left; i < right; ++i)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }

    swap(arr[storeIndex], arr[right]); 
    return storeIndex;
}

int selectBySorting(vector<int> &arr, int left, int right, int k)
{
    sort(arr.begin() + left, arr.begin() + right + 1);
    return arr[left + k - 1];
}

int floydRivestSelect(vector<int> &arr, int left, int right, int k)
{
    while (right > left)
    {
        if (right - left > SELECT_SAMPLE_SIZE)
        {
            int n = right - left + 1;
            int numGroups = n / SELECT_SAMPLE_SIZE;
            for (int i = 0; i < numGroups; ++i)
            {
                int groupLeft = left + i * SELECT_SAMPLE_SIZE;
                int groupRight = groupLeft + SELECT_SAMPLE_SIZE - 1;
                int medianIndex = selectBySorting(arr, groupLeft, groupRight, SELECT_SAMPLE_SIZE / 2);
                swap(arr[left + i], arr[medianIndex]);
            }
            int numMedians = numGroups;
            int medianOfMedians = floydRivestSelect(arr, left, left + numMedians - 1, numMedians / 2);
            int pivotIndex = partition(arr, left, right, medianOfMedians);
            if (k == pivotIndex - left + 1)
            {
                return arr[pivotIndex];
            }
            else if (k < pivotIndex - left + 1)
            {
                right = pivotIndex - 1;
            }
            else
            {
                left = pivotIndex + 1;
                k -= (pivotIndex - left + 1);
            }
        }
        else
        {
            return selectBySorting(arr, left, right, k);
        }
    }

    return arr[left];
}

int main()
{
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    if (k >= 1 && k <= arr.size())
    {
        int result = floydRivestSelect(arr, 0, arr.size() - 1, k);
        cout << "The " << k << "-th smallest element is: " << result << endl;
    }
    else
    {
        cout << "Invalid value of k.\n";
    }

    return 0;
}
