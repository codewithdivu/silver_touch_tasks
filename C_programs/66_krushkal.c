#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent, rank;
};

int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void kruskalMST(struct Edge edges[], int V, int E);

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskalMST(struct Edge edges[], int V, int E)
{
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    for (int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    struct Edge resultMST[V - 1];

    int e = 0;

    int i = 0;

    while (e < V - 1 && i < E)
    {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y)
        {
            resultMST[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Edges of the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++)
    {
        printf("%d - %d : %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);
    }

    free(subsets);
}

int main()
{
    int V = 4; 
    int E = 5; 

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    kruskalMST(edges, V, E);

    return 0;
}
