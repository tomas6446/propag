#include <stdio.h>
#include <string.h>

long getFileSize(char *fileName)
{
    long size = -1;
    FILE *file;

    if(strstr(fileName, ".txt") == NULL) // in case user forgot to put .txt in the name of the file...
    {
        strcat(fileName, ".txt");
    }

    file = fopen(fileName, "rb"); // open file for binary reading
    if(file != NULL)
    {
        if(fseek(file, 0, SEEK_END) == 0)
        {
            return ftell(file);
        }
    }
    else
    {
        return -1;
    }
    fclose(file);
    return size;
}

int main()
{

    char fileName[128] = ""; // name of the file;
    do
    {
        printf("Enter file name: ");
        scanf("%128s", fileName);

        long size = getFileSize(fileName);

        if(size >= 0)
        {
            printf("Size of %s is %ld bytes\n", fileName, size);
            break;
        }
        else
        {
            printf("Error! File does not exit. Try again.\n");
        }
    } while(1);


    return 0;
}
