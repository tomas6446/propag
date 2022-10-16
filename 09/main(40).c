#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point point;
typedef struct Stack stack;

struct Point
{
    double x, y;
};

struct Stack
{
    point *arr;
    int size;
};

void initStack(stack *st)
{
    st->size = 0;
    st->arr = calloc(st->size, sizeof(point));
}

void push(stack *st, double x, double y)
{
    st->size++;
    st->arr = realloc(st->arr, st->size * sizeof(point));

    st->arr[st->size - 1].x = x;
    st->arr[st->size - 1].y = y;
}

point top(stack *st)
{
    return st->arr[st->size - 1];
}

void printfStack(stack *st)
{
    for (int i = 0; i < st->size; ++i)
    {
        printf("distance from first point (%.1f, %.1f) = %0.1f\n", st->arr[i].x, st->arr[i].y,
               sqrt(pow((st->arr[0].x - st->arr[i].x), 2) + pow((st->arr[i].y - st->arr[0].y), 2)));
    }
}

point pop(stack *st)
{
    point p = top(st);
    st->size--;
    st->arr = realloc(st->arr, st->size * sizeof(point));
    return p;
}


int main()
{
    stack st;
    stack *ptr_st = &st;

    initStack(ptr_st);
    push(ptr_st, 1, 2);
    push(ptr_st, 2, 3);
    push(ptr_st, 3, 5);
    push(ptr_st, 7, 5);
    push(ptr_st, 12, 2);
    push(ptr_st, 32, 12);

    point t = top(ptr_st);
    printf("top = (%.1f, %.1f)\n", t.x, t.y);
    point p = pop(ptr_st);
    printf("pop = (%.1f, %.1f)\n", p.x, p.y);

    printfStack(ptr_st);
    free(ptr_st->arr);
    return 0;
}
