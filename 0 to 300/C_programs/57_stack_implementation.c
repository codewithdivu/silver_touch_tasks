#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IsEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int IsFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val)
{
    if (IsFull(ptr))
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int Pop(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("Stack is Underflow, so you can not pop any elements\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *s, int index)
{
    int arrindex = s->top - index + 1;
    if (arrindex < 0)
    {
        printf("not a valid postion of stack\n");
        return -1;
    }
    else
    {
        return s->arr[arrindex];
    }
}

int stackBottom(struct stack *s)
{
    return s->arr[0];
}
int stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));
    printf("Stack has been created successfully \n");

    printf("element %d is poped from stack\n", Pop(s));
    printf("element %d is poped from stack\n", Pop(s));

    return 0;
}
