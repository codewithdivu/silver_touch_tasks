#include <iostream>
using namespace std;

int searchRotatedArray(int arr[], int n, int target)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[start] <= arr[mid])
        {
            if (target >= arr[start] && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    int result = searchRotatedArray(arr, n, target);

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
