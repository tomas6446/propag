#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

char ***createArray(int x, int y)
{
    char ***array = (char ***) calloc(x, sizeof(char ***));
    for (int i = 0; i < x; i++)
    {
        array[i] = (char **) calloc(y, sizeof(char **));
    }
    return array;
}

void putLine(char **array, char *line)
{
    *array = line;
}

char *getLine(char **array)
{
    return *array;
}

void deleteArray(char ***array)
{
    free(array);
}

void printfArray(char ***array, int x, int y)
{
    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%s ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int stop = 0; // boolean
    int x = 5, y = 5;
    char ***array = NULL;
    array = createArray(x, y);
    do
    {
        printfArray(array, x, y);

        int choice;

        printf("1. Put line in array\n2. Get line from array\n3. Delete array\nChoice:");
        scanf("%d", &choice);

        int i, j;
        char *line = "";
        switch (choice)
        {
            case 1:
                printf("Row:");
                scanf("%d", &i);
                printf("Column:");
                scanf("%d", &j);
                printf("Line:");
                scanf("%s", line);
                putLine(&array[i][j], line);
                break;
            case 2:
                printf("Row:");
                scanf("%d", &i);
                printf("Column:");
                scanf("%d", &j);
                line = getLine(&array[i][j]);
                printf("\nLine:%s\n", line);
                break;
            case 3:
                deleteArray(array);
                break;
            case 4:
                stop = true;
            default:
                printf("Bad input\n");
                break;
        }
    } while (stop == false);
    return 0;
}
