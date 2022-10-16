#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[1000];
    int a, b, c;
    printf("Tris skaicius (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);
    srand(time(NULL));
    for (int i = 0; i < c; i++)
    {
        array[i] = (rand() % (b - a + 1)) + a;
    }
    for (int i = 0; i < c; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;
}
