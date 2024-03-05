#include <iostream>
using namespace std;

void reverse(int *arr, int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {99, 2, 6, 23, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}