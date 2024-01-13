#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (key == arr[mid])
        {
            ans = mid;
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int LastOccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (key == arr[mid])
        {
            ans = mid;
            start = mid + 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 3, 3, 3, 5};

    cout << "first occurence of 3 is at index " << firstOccurence(arr, 7, 3) << endl;
    cout << "last occurence of 3 is at index " << LastOccurence(arr, 7, 3) << endl;
    return 0;
}