#include <stdio.h>

int main()
{
    int arr[] = {12, 14, 15, 76, 87, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    int element;
    printf("enter element which you want to find in array\n");
    scanf("%d", &element);

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == element)
        {
            printf("element present at index %d ", mid);
            return;
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    printf("element is not present in array");

    return 0;
}