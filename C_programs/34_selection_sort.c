#include <stdio.h>

int main()
{
    int arr[] = {11, 65, 32, 5, 33, 78, 54, 99, 64, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}