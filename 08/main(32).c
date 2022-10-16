#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size, int low, int high)
{
    int *array = (int *) calloc(size, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }
    else
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            *(array + i) = rand() % (high - low + 1) + low;
            printf("%d ", *(array + i));
        }

        int *value = array;
        printf("\nvalue = %d \n", *value);
        free(array);
        return value;
    }
}


int main()
{
    int *p = createArray(10, 0, 9);
    printf("pointer = %p ", p);
    return 0;
}
