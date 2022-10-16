#include <stdio.h>
#include <stdlib.h>

#define ASCENDING 1
#define DESCENDING -1
typedef struct DoublyLinkedList List;

struct DoublyLinkedList
{
    char *word;
    List *next;
    List *prev;
};

List *createList(char *word)
{
    List *list = malloc(sizeof(List));
    list->word = word;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void inputWord(List **list, char *word)
{
    List *newList = malloc(sizeof(List));
    newList->word = word;
    newList->next = *list;
    newList->prev = NULL;
    if ((*list) != NULL)
    {
        (*list)->prev = newList;
    }
    *list = newList;
}

void printfList(List *list)
{
    if (list != NULL)
    {
        printf("%s ", list->word);
        if (list->next != NULL)
        {
            printfList(list->next);
        }
    }
}

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void sortList(List **list, int value)
{
    List *current = NULL, *index = NULL;

    if (*list == NULL) // Check if list is empty
    {
        return;
    }
    for (current = *list; current->next != NULL; current = current->next) // Current will point to head(*list)
    {
        for (index = current->next; index != NULL; index = index->next) // Index will point to node next to current
        {
            if (value == ASCENDING) // ascending order
            {
                if (*(current->word) > *(index->word)) // If current's data is greater than index's data
                {
                    swap(&current->word, &index->word); // swap the data of current and index (ascending order)
                }
            }
            else if (value == DESCENDING) // descending order
            {
                if (*(current->word) < *(index->word)) // If current's data is greater than index's data
                {
                    swap(&index->word, &current->word); // swap the data of current and index (descending order)
                }
            }
        }
    }
}

void destroyList(List **list)
{
    List *tmp;
    while (*list != NULL)
    {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
}


int main()
{
    List l;
    List *list = &l;

    list = createList("C");
    inputWord(&list, "A");
    inputWord(&list, "D");
    inputWord(&list, "E");
    inputWord(&list, "B");
    inputWord(&list, "A");
    inputWord(&list, "D");
    inputWord(&list, "E");

    sortList(&list, DESCENDING);
    //sortList(&list, ASCENDING);

    printfList(list);
    destroyList(&list);
    return 0;
}
