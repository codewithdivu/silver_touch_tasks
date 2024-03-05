#include <stdio.h>
#include <stdlib.h>

int main()
{

    // malloc

    int *ptr;
    int n = 5, i;

    ptr = (int *)malloc(5 * sizeof(int));

    printf("Memory successfully allocated using malloc.\n");

    for (i = 0; i < 5; ++i)
    {
        ptr[i] = i + 1;
    }
    printf("The elements of the array are: ");
    for (i = 0; i < 5; ++i)
    {
        printf("%d, ", ptr[i]);
    }

    // calloc

    int i, *ptr, sum = 0;
    ptr = calloc(10, sizeof(int));

    printf("calculating the sequence sum of the first 10 terms \ n ");
    for (i = 0; i < 10; ++i)
    {
        *(ptr + i) = i;
        sum += *(ptr + i);
    }
    printf("Sum = %d", sum);
    free(ptr);

    // realloc

    int i, *ptr, sum = 0;
    ptr = malloc(100);
    if (ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    ptr = realloc(ptr, 500);
    if (ptr != NULL)
        printf("Memory created successfully\n");

    return 0;
}