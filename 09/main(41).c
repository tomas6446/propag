#include <stdio.h>
#include <stdlib.h>

typedef struct Point point;
typedef struct List list;

struct Point
{
    double x, y;
};

struct List
{
    point *p;
    struct List *next;
};

list *createList(double x, double y)
{
    list *l = malloc(sizeof(list)); // allocate memory for list
    l->p = malloc(sizeof(point)); // allocate memory for point (inside list)
    l->next = NULL;
    l->p->x = x;
    l->p->y = y;
    return l;
}

void printfList(list *l)
{
    if (l != NULL)
    {
        printf("(%0.1f, %0.1f) ", l->p->x, l->p->y);
        if (l->next != NULL)
        {
            printfList(l->next);
        }
    }
}

int getListSize(list *l)
{
    list *tmp;
    tmp = l;
    int count = 0;
    while (tmp != NULL) // count while until tmp becomes NULL
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

void insertElement(list **l, double x, double y)
{
    list *newList = malloc(sizeof(list)); // create newList;
    newList->p = malloc(sizeof(point)); // allocate memory for newList;

    newList->p->x = x; // assign values;
    newList->p->y = y;

    newList->next = *l; // point newList's pointer 'next' to the start of the 'list'
    *l = newList; // now point list's 'next' pointer to the start of the newList;
}

point *getElement(list **l)
{
    return (*l)->p;
}

point *deleteElement(list **l)
{
    point *p = (*l)->p;
    *l = (*l)->next;
    return p;
}

void destroyList(list **l)
{
    list *tmp;
    while (*l != NULL)
    {
        tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
}

int main()
{
    list List;
    list *l = &List;
    l = createList(5, 1);
    //printf("%d\n", getListSize(l));
    insertElement(&l, 1, 2);
    insertElement(&l, 2, 1);
    insertElement(&l, 3, 7);
    insertElement(&l, 4, 2);
    getElement(&l);
    deleteElement(&l);
    //destroyList(&l);
    printfList(l);

    return 0;
}
