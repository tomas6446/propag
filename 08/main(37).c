#include <stdio.h>
#include <stdlib.h>

// informaciją paėmiau iš https://sites.cs.ucsb.edu/~rich/class/cs170/labs/lab1.malloc/
// sugebėjau padaryti kažka panašaus į myCalloc ir myMalloc, bet nežinau kaip padaryti myFree
#define MAX_MALLOC_SIZE 1000

unsigned char bigBuffer[MAX_MALLOC_SIZE];

struct malloc_stc
{
    int size;
    unsigned char *buffer;
} mall_stc;

void nullBuffer()
{
    for (int i = 0; i < MAX_MALLOC_SIZE; i++)
    {
        mall_stc.buffer[i] = '0';
    }
}

void *myMalloc(int size)
{
    if (mall_stc.size - size >= 0)
    {
        for (int i = (MAX_MALLOC_SIZE - mall_stc.size); i < ((MAX_MALLOC_SIZE - mall_stc.size) + size); i++)
        {
            *(mall_stc.buffer + i) = (int) &bigBuffer[i];
        }
        mall_stc.size -= size;
        return &mall_stc.buffer[MAX_MALLOC_SIZE - (mall_stc.size + size)];
    }
    else
    {
        fprintf(stderr, "\ncall to MyMalloc() failed\n");
        fflush(stderr);
        exit(1);
    }
}

void *myCalloc(int size)
{
    if (mall_stc.size - size >= 0)
    {
        for (int i = (MAX_MALLOC_SIZE - mall_stc.size); i < ((MAX_MALLOC_SIZE - mall_stc.size) + size); i++)
        {
            *(mall_stc.buffer + i) = (char) 0;
        }
        mall_stc.size -= size;
        return &mall_stc.buffer[MAX_MALLOC_SIZE - (mall_stc.size + size)];
    }
    else
    {
        fprintf(stderr, "\ncall to MyCalloc() failed\n");
        fflush(stderr);
        exit(1);
    }
}

void printfBigBuffer()
{
    printf("\n");
    printf("\n");
    for (int i = 0; i < MAX_MALLOC_SIZE; i++)
    {
        printf("%c", mall_stc.buffer[i]);
        if ((i + 100) % 100 == 0 && i != 0)
        {
            printf("\n");
        }
    }

}

int main()
{
    mall_stc.size = MAX_MALLOC_SIZE;
    mall_stc.buffer = &bigBuffer[0];
    nullBuffer();
    //______________________


    //_____________________
    printfBigBuffer();
    return 0;
}
