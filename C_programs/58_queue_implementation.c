#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int main()
{
    struct queue *qu;
    qu->size = 10;
    qu->f = 0;
    qu->r = 0;
    qu->arr = (struct queue *)malloc(qu->size * (sizeof(int)));
    return 0;
}