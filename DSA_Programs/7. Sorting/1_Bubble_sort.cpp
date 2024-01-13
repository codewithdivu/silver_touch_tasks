#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {11, 65, 32, 5, 33, 78, 34, 99, 64, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int j = 1; j < n; j++)
    {

        bool swapped = false;

        for (int i = 0; i < n - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true; // if there is already sorted array then no need to swap simply break loop
            }
        }
        if (swapped == false)
        {
            break;
        }
    }

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
}