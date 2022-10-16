#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long getFileSize(FILE *file, char *fileName)
{
    long size = -1;
    file = fopen(fileName, "rb"); // open file for binary reading
    if (fseek(file, 0, SEEK_END) == 0)
    {
        return ftell(file);
    }
    fclose(file);
    return size;
}

void setValue(FILE *file, char *fileName, int index, int value)
{
    printf("Value:");
    scanf("%d", &value);
    printf("Index:");
    scanf("%d", &index);

    file = fopen(fileName, "w");
    fseek(file, index, SEEK_END);
    fprintf(file, "%d", value);

    fclose(file);
}

int getValue(FILE *file, char *fileName, int index)
{
    printf("Index:");
    scanf("%d", &index);

    file = fopen(fileName, "r");
    fseek(file, index, SEEK_SET);

    char value[10];
    value[0] = NULL;
    memset(value, 0, 10);
    fread(value, 1, 9, file);
    fclose(file);

    if (value[0] != NULL)
    {
        return atoi(value);
    }
    else
    {
        return 0;
    }
}

void addValue(FILE *file, char *fileName, int index, int value)
{
    printf("Value:");
    scanf("%d", &value);
    printf("Index:");
    scanf("%d", &index);

    file = fopen(fileName, "r+");
    fseek(file, index, SEEK_SET);
    fprintf(file, "%d", value);
    fclose(file);
}

void remValue(FILE *file, char *fileName)
{
    fclose(fopen(fileName, "w"));
}

int main()
{
    FILE *file;
    char fileName[256];

    printf("Enter file name (0 <- to stop the program):");
    scanf("%256s", fileName);

    if (strstr(fileName, ".txt") == NULL) // in case user forgot to put .txt in the name of the file...
    {
        strcat(fileName, ".txt");
    }

    file = fopen(fileName, "r");
    if (file != NULL)
    {
        printf("Successfully opened the text file '%s'\n", fileName);
        int stop = 0;
        do
        {
            int choice, index = 0, value = 0;
            int size = getFileSize(file, fileName);

            printf("\nSize of the file is %d bytes\n\n", size);

            printf("Enter function: \n1. getValue()\n2. setValue()\n3. addValue()\n4. remValue()\n5. stop the program\n\nChoice:");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    value = getValue(file, fileName, index);
                    printf("The Value on index[%d]: %d", index, value);
                    break;
                case 2:
                    setValue(file, fileName, index, value);
                    printf("The Value %d on index[%d] has been set\n", index, value);
                    break;
                case 3:
                    addValue(file, fileName, index, value);
                    printf("The Value %d on index[%d] has been added\n", index, value);
                    break;
                case 4:
                    remValue(file, fileName);
                    printf("The File has been cleared\n");
                    break;
                case 5:
                    stop = 1;
                    break;
                default:
                    printf("Incorrect input. Try again.\n");
                    break;
            }
        } while (stop == 0);
    }
    else
    {
        printf("\nUnable to open '%s' file.\n", fileName);
        exit(1);
    }
    fclose(file);

    return 0;
}
