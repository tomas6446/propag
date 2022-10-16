#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int *size, int *low, int *high)
{
    srand(time(NULL));
    for (int i = 0; i < *size; i++)
    {
        data[i] = rand() % ((*high) + 1 - *low) + *low; // random in range of [low, high]
        printf("data[%d] = %d\n", i, data[i]);
    }
}

int main()
{
    int size, low, high;

    printf("Enter size of the array: ");
    scanf("%d", &size);
    printf("Enter range of the array -> [low, high]: ");
    scanf("%d %d", &low, &high);

    int *data = (int *) calloc(size, sizeof(int));

    generateArray(data, &size, &low, &high);
    free(data);

    return 0;
}
