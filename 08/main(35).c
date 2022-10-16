#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int splitData(int array[], int size, int left_size, int *left_array, int *right_array)
{
    if (size >= 1 && left_size >= 0 && left_size <= size)
    {
        left_array = malloc(left_size * sizeof(left_size));
        right_array = malloc((size - left_size) * sizeof(size - left_size));

        int left = true; // simple boolean
        for (int i = 0, j = 0; i < size; i++)
        {
            if (left == true && i != left_size) // <- start left_array[i] = array[i]
            {
                left_array[i] = (int *) array[i];
            }
            else if (i == left_size) // <- stop left_array[i] = array[i]
            {
                left = false;
            }
            if (left == false) // <- start right_array[j] = array[i]
            {
                right_array[j] = (int *) array[i];
                j++;
            }
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int size = 10, left_size = 5;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *left_array = NULL, *right_array = NULL;

    printf("%d", splitData(array, size, left_size, left_array, right_array));

    free(left_array);
    free(right_array);
    return 0;
}
