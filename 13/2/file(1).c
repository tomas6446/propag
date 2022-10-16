#include "file.h"

int loadCount = 0;
int saveCount = 0;

int *loadFromFile(char *fileName)
{
    int *numbers = malloc(sizeof(int));
    FILE *file = fopen(fileName, "rb");
    if (file != NULL)
    {
        int size, number;
        fscanf(file, "%d", &size);
        *(numbers) = size;

        numbers = realloc(numbers, size * sizeof(int)); // add size to the array
        for (int i = 1; i < size; i++)
        {
            fscanf(file, "%d", &number);
            if (number != ' ')
            {
                *(numbers + i) = number; // assign number from the file
            }
        }
    }
    fclose(file);
    loadCount++;
    return numbers;
}

void saveToFile(int *arr, char *fileName)
{
    FILE *file;
    file = fopen(fileName, "wb");
    if (file != NULL)
    {
        for (int i = 0; i < arr[0]; i++)
        {
            fprintf(file, "%d ", arr[i]);
        }
    }
    fclose(file);
    saveCount++;
}