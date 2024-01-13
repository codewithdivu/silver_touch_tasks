#include <iostream>
using namespace std;

int max(int *arr, int size)
{
    int minu = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > minu)
        {
            minu = arr[i];
        }
    }
    return minu;
}

int main()
{
    int arr[] = {12, 2, 6, 23, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    int answer = max(arr, size);
    cout << "max element of arr is " << answer << endl;
    return 0;
}