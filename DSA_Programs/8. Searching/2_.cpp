#include <iostream>
using namespace std;

int BinearySearching(int arr[], int size, int key)
{
    int start = 0;
    int end = size;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << BinearySearching(arr, n, key) << endl;
    return 0;
}