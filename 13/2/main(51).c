#include "file.h"
#include <stdio.h>
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

int main()
{
    // 1) sugeneruokite masyvus m1, m2 ir m3 su atsitiktiniais duomenimis
    int *m1 = fillArray(10);
    int *m2 = fillArray(10);
    int *m3 = fillArray(10);
    saveToFile(m1, "file.txt"); // 2) išsaugokite masyvą m1 failą
    saveToFile(m3, "file.txt"); // 3) į tą patį failą („ant viršaus“) išsaugokite masyvą m3
    m1 = loadFromFile("file.txt"); // 4) užkraukite iš to failo masyvą m1
    saveToFile(m2, "file2.txt"); // 5) išsaugokite kitame faile masyvą m2
    m3 = loadFromFile("file2.txt"); // 6) užkraukite iš to (kito) failo masyvą m3
    m2 = loadFromFile("file.txt"); // 7) užkraukite iš pirmo (ankstesnio) failo masyvą m2

    if(saveCount == 3 && loadCount == 3)
    {
        printf("all good\n");
    }
    else
    {
        printf("something's wrong\n");
    }

    free(m1);
    free(m2);
    free(m3);
    return 0;
}
