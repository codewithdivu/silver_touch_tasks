#include <stdio.h>

int main()
{
    int arr[] = {11, 65, 32, 5, 33, 78, 54, 99, 64, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    int element;
    printf("enter element which you want to find in array\n");
    scanf("%d", &element);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("element found at index %d ", i);
            return;
        }
    }

    printf("element is not present in array");

    return 0;
}