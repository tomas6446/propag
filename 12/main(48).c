#include <stdio.h>
#include <string.h>

char *myStrchr(const char *str, int character)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
        if (*(str + i) == character)
        {
            return (str + i);
        }
    }
    return (char *) NULL;
}

char *myStrrchr(const char *str, int character)
{
    int i = 0;
    char *last = NULL;
    while (*(str + i) != '\0')
    {
        i++;
        if (*(str + i) == character)
        {
            last = (str + i);
        }
    }
    return (char *) last;
}

char *myStrstr(char *str, char *key)
{
    char *a = str;
    char *b = key;
    for( ; *str != '\0'; *str++)
    {
        if (*str != *(b))
        {
            continue;
        }
        a = str;

        while (1)
        {
            if (*b == '\0')
            {
                return str;
            }
            else if (*a++ != *b++)
            {
                break;
            }
        }
        b = key;
    }
    return (char *) NULL;
}


int main()
{
    char str[] = "This is a simple string";

    char *pch = myStrchr(str, 's');
    printf("char 's' is found at %lld\n", pch - str + 1);

    pch = myStrrchr(str, 's');
    printf("last occurence of 's' is found at %lld\n", pch - str + 1);

    char keyWord[] = "string";
    pch = myStrstr(str, keyWord);
    printf("\nfirst occurence of a string '%s' is found at %lld\n", keyWord, pch - str + 1);

    return 0;
}
