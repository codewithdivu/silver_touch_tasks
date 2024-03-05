#include <stdio.h>

void mergeSort(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int first[len1];
    int second[len2];

    // divide array

    int mainIndex = start;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }

    // now merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainIndex++] = first[index1++];
        }
        else if (second[index2] < first[index1])
        {
            arr[mainIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainIndex++] = second[index2++];
    }

}

void merge(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{
    int arr[] = {11, 65, 32, 5, 33, 78, 54, 99, 64, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge(arr, 0, size - 1);

    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}