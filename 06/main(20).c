#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main()
{
    FILE *file;

    char string[10];
    file = fopen("in.txt", "r");
    fscanf(file, "%s", &string);
    fclose(file);

    while (1)
    {
        int size_number = strlen(string) - 1; // size of whole number without comma
        int size_int_number = 0; // size of number before comma

        for (size_int_number = 0; size_int_number < size_number; size_int_number++)
        {
            if (string[size_int_number] == ',') // counting until you find comma
            {
                break; // found comma = break from loop;
            }
        }

        int number = atoi(string); // converting number from string
        int size_after_comma = size_number - size_int_number; // size of numbers after comma

        if (number >= 10 && number <= 1000 &&
            size_after_comma <= 3) // and less than 3 digits after comma, number must be in range of [10, 1000]
        {
            printf("Data '%s' presented correctly its length: %d\n", string,
                   size_number); // nežinau ar ',' skaitosi už length, jeigu taip tada reikia size_number+1
            break;
        }
        else
        {
            printf("Data '%s' presented incorrectly\n", string);
        }

        char DB[128] = ""; // name of database;
        printf("Enter another database name: ");
        scanf("%128s", DB); // reading
        strcat(DB, ".txt");

        file = fopen(DB, "r");
        if (file == NULL)
        {
            perror("Couldn't find or open this file\n");
            exit(1);
        }
        else
        {
            printf("\nSuccessfully opened file %s\n", DB);
        }
        fscanf(file, "%s", &string);
        fclose(file);
    }


    return 0;
}
