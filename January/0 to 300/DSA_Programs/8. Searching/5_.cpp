#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target)
{
    int start = 0, end = n - 1;

    while (start <= end && target >= arr[start] && target <= arr[end])
    {
        int pos = start + ((double)(end - start) / (arr[end] - arr[start])) * (target - arr[start]);

        if (arr[pos] == target)
        {
            return pos;
        }

        if (arr[pos] < target)
        {
            start = pos + 1;
        }
        else
        {
            end = pos - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    int result = interpolationSearch(arr, n, target);

    if (result != -1)
    {
        cout << "Element " << target << " found at index " << result << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
