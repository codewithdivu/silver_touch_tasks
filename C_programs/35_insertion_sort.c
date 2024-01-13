#include <stdio.h>

int main()
{
    int arr[] = {11, 65, 32, 5, 33, 78, 54, 99, 64, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }

    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}