#include <iostream>
using namespace std;

int sum(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {12, 2, 6, 23, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    int answer = sum(arr, size);
    cout << "sum of arr is " << answer << endl;
    return 0;
}