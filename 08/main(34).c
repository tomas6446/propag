#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[] = {1, 2, 4, 5, 6,};
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    swap(&array[0], &array[4]);
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
