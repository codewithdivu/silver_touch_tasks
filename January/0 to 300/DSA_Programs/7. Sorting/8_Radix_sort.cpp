#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> &arr)
{
    int maxNum = arr[0];
    for (int num : arr)
    {
        if (num > maxNum)
        {
            maxNum = num;
        }
    }
    return maxNum;
}

void countingSort(vector<int> &arr, int exp)
{
    const int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr)
{
    int maxNum = findMax(arr);

    for (int exp = 1; maxNum / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
