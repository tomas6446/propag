#include <stdio.h>

#define MAX_SIZE 100

int checkifpirminis(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int array[MAX_SIZE];
    int num, size = 0;
    do
    {
        scanf("%d", &num);
        array[size] = num;
        size++;
    } while (num > 0);
    int pirm[MAX_SIZE], pirm_size = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] != 1 && checkifpirminis(array[i]) == 1)
        {
            pirm[pirm_size] = array[i];
            pirm_size++;
        }
    }

    int new_size = pirm_size;
    for (int i = 0; i < pirm_size - 1; i++)
    {
        for (int j = i + 1; j < pirm_size; j++)
        {
            if (pirm[i] == pirm[j])
            {
                for (int x = j; j < size - 1; j++)
                {
                    pirm[x] = pirm[x + 1];
                }
                new_size--;
            }
        }
    }

    printf("\nPirminiai skaiciai:\n");
    for (int i = 0; i < new_size; i++)
    { // pirminiai skaiciai
        printf("%d ", pirm[i]);
    }
    return 0;
}
