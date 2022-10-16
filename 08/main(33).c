#include <stdio.h>
#include <stdlib.h>

long getFileSize(FILE *file, char *fileName)
{
    file = fopen(fileName, "rb"); // open file for binary reading
    if (file == NULL)
    {
        return -1;
    }
    else
    {
        if (fseek(file, 0, SEEK_END) == 0)
        {
            return ftell(file);
        }
        fclose(file);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *file;
    long maxBytes = 0;
    char *maxName = NULL;

    for (int i = 1; i < argc; i++)
    {
        if ((file = fopen(argv[i], "r")) != NULL)
        {
            long fileSize = getFileSize(file, argv[i]);
            if (maxBytes < fileSize)
            {
                maxBytes = fileSize;
                maxName = argv[i];
            }
        }
        else
        {
            printf("No text file with that name\n");
            exit(0);
        }
        fclose(file);
    }
    printf("Maximum size is %ld bytes. File name: %s\n", maxBytes, maxName);

    return 0;
}
