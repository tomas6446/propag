#include <stdio.h>
#include <stdlib.h>

typedef struct Stack stack;

struct Stack
{
    int *arr;
    int size;
};

void initStack(stack *st)
{
    st->size = 0;
    st->arr = calloc(st->size, sizeof(int));
}

void printfStack(stack *st)
{
    for (int i = 0; i < st->size; i++)
    {
        printf("%d ", st->arr[i]);
    }
}

int getStackSize(stack *st)
{
    return st->size;
}

void push(stack *st, int value)
{
    st->size++; // add size
    st->arr = realloc(st->arr, st->size * sizeof(int *)); // allocate memory for arr
    st->arr[st->size - 1] = value; // assign value
}

int top(stack *st)
{
    return st->arr[st->size - 1];
}

int pop(stack *st)
{
    int t = top(st); // save value in 't'
    st->size--; // decrease size
    st->arr = realloc(st->arr, st->size * sizeof(int *)); // reallocate memory
    return t; // return value stored in t
}

void destroyStack(stack *st)
{
    st->size = 0;
    free(st->arr);
}

int main()
{
    stack st;
    stack *ptr_st = &st;

    initStack(ptr_st);
    printfStack(ptr_st);
    printf("Size = %d\n", getStackSize(ptr_st));
    push(ptr_st, 5);
    push(ptr_st, 2);
    push(ptr_st, 1);
    push(ptr_st, 7);
    push(ptr_st, 8);
    push(ptr_st, 1);
    printf("top = %d\n", top(ptr_st));
    printf("pop = %d\n", pop(ptr_st));

    printfStack(ptr_st);
    destroyStack(ptr_st);
    return 0;
}
