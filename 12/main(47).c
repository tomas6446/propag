#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *myStrncpy(char *dest, const char *src, unsigned int num)
{
    for (int i = 0; i < num; i++)
    {
        *(dest + i) = *(src + i);
    }
    return "";
}

char *myStrncat(char *dest, const char *src, unsigned int num)
{
    int i = 0;
    if (num < strlen(dest) + strlen(src))
    {
        while (*(dest + i) != '\0')
        {
            i++;
        }
        if (*(dest + i) == '\0')
        {
            for (int j = 0; j < num; j++)
            {
                *(dest + i) = *(src + j);
                i++;
            }
        }
    }
    return "";
}

int myStrncmp(char *str1, char *str2, unsigned long num)
{
    int i = 0, count = 0;
    if (num < strlen(str1) + strlen(str2))
    {
        while (*(str1 + i) != '\0' || *(str2 + i) != '\0')
        {
            count++;
            if (count == num)
            {
                break;
            }
            i++;
        }
        if (count > num)
        {
            return -1;
        }
        else if (count < num)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    char str1[40] = "Copy this string ";
    char str2[40] = "Copy";
    char str3[40];

    // myStrncpy
    assert(myStrncpy(str2, "\n", 10));
    assert(myStrncpy(str2, "\n\n", 10));
    assert(myStrncpy(str2, ".\n", 10));
    assert(myStrncpy(str2, "Copy this string\n", 10));
    assert(myStrncpy(str2, "copy\n", 39));
    myStrncpy(str2, str1, 20);
    printf("%s\n", str2);

    // myStrncat
    assert((myStrncat, "\n", 1));
    assert((myStrncat, "", 1));
    assert((myStrncat, " ", 1));
    assert((myStrncat, "\n\0", 1));
    myStrncat(str1, str2, 20);
    printf("%s\n", str1);

    // myStrncmp
    if (myStrncmp(str2, str1, 4) == 0)
    {
        printf("Equal\n");
    }
    else if (myStrncmp(str2, str1, 4) > 0)
    {
        printf("Greater\n");
    }
    else if (myStrncmp(str2, str1, 4) < 0)
    {
        printf("Lesser\n");
    }


    return 0;
}
