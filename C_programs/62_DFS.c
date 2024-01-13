#include <stdio.h>
#include <stdlib.h>

void dfs(int start, int arr[7][7], int visited[])
{
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < 7; i++)
    {
        if (!visited[i])
        {
            dfs(i, arr, visited);
        }
    }
}

int main(int argc, char const *argv[])
{

    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int arr[7][7] =
        {
            {0, 1, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 1, 1, 0, 0},
            {1, 1, 1, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0}};

    dfs(i, arr, visited);

    return 0;
}