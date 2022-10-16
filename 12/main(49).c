#include <stdio.h>

void myMemcpy(void *destination, void *source, unsigned long long size)
{
    char *src = (char *) source;
    char *dest = (char *) destination;
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

int main()
{
    int source[] = {10, 20, 30, 40, 50};
    int n = sizeof(source) / sizeof(source[0]);
    int destination[n];

    myMemcpy(destination, source, sizeof(source));

    for (int i = 0; i < n; i++)
    {
        printf("%d ", destination[i]);
    }

    return 0;
}
