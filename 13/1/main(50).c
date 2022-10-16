#include "file.h"
#include <stdlib.h>
#include <time.h>

int *fillArray(int size)
{
    srand(time(NULL));
    int *arr = malloc(size * sizeof(int));
    arr[0] = size;
    for (int i = 1; i < size; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

void printArray(int arr[])
{
    int size = arr[0];
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int checkSimilarity(int arr1[], int arr2[])
{
    if (arr1[0] == arr2[0])
    {
        for (int i = 0; i < arr1[0]; i++)
        {
            if (arr1[i] != arr2[i])
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        printf("array size is not same\n");
        return 0;
    }
}

int main()
{
    int *m1 = fillArray(10); // 1) sugeneruokite masyvą m1
    printArray(m1); //  2) atspausdinkite m1
    saveToFile(m1, "file.txt"); // 3) išsaugokite m1 faile
    int *m2 = loadFromFile("file.txt"); // 4) užkraukite iš failo masyvą
    printArray(m2); //  5) atspausdinkite m2

    if (checkSimilarity(m1, m2) == 1)
    {
        printf("all good\n");
    }
    else
    {
        printf("something's wrong\n");
    }

    free(m1);
    free(m2);
    return 0;
}
