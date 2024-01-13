#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void Enqueue(struct queue *q, int val)
{
    if ((q->front == 1 && q->rear == q->size) || (q->rear == q->front - 1))
    {
        printf("Circular queue is full\n");
    }
    if (q->front == 0)
    {
        q->front = q->rear = 1;
        q->arr[q->rear] = val;
    }
    else if (q->rear == q->size)
    {
        q->rear = 1;
        q->arr[q->rear] = val;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int Dequeue(struct queue *q)
{
    if (q->front == 0)
    {
        printf("Circular queue is empty\n");
        return -1;
    }

    int val = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = 0;
    }
    else if (q->front == q->size)
    {
        q->front = 1;
    }
    else
    {
        q->front++;
    }

    return val;
}

void Display(struct queue *q)
{
    if (q->front == 0)
    {
        printf("Circular queue is empty\n");
        return;
    }

    int i = q->front;
    do
    {
        printf("%d ", q->arr[i]);

        if (i == q->size)
        {
            i = 1;
        }
        else
        {
            i++;
        }
    } while (i != (q->rear + 1));
    printf("\n");
}

int main()
{
    struct queue q;
    q.size = 10;
    q.front = 0;
    q.rear = 0;
    q.arr = (int *)malloc((q.size + 1) * sizeof(int));
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);

    Display(&q);

    int val = Dequeue(&q);
    if (val != -1)
    {
        printf("Dequeued element: %d\n", val);
    }

    Display(&q);

    Enqueue(&q, 40);
    Enqueue(&q, 50);
    Display(&q);

    free(q.arr);

    return 0;
}
