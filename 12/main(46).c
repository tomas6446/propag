#include <stdio.h>
#include <string.h>

char *myStrcpy(char *dest, const char *src)
{
    int i = 0;
    while (*(src + i) != '\0')
    {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';
    return 0;
}

char *myStrcat(char *dest, const char *src)
{
    int i = 0;
    while (*(dest + i) != '\0')
    {
        i++;
    }
    if (*(dest + i) == '\0')
    {
        int j = 0;
        while (*(src + j) != '\0')
        {
            *(dest + i) = *(src + j);
            j++;
            i++;
        }
    }
    return 0;
}

int myStrcmp(char *str1, const char *str2)
{
    int i = 0, count = 0;
    if (strlen(str1) == strlen(str2))
    {
        while (*(str1 + i) != '\0' || *(str2 + i) != '\0')
        {
            if (str1[i] == str2[i])
            {
                count++;
            }
            i++;
        }
    }

    if(count > strlen(str1))
    {
        return 1;
    }
    else if (count < strlen(str1))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *src = "HelloWorld!";
    char dest[strlen(src) + 1];
    // myStrcpy
    myStrcpy(dest, src);
    printf("%s\n", dest);
    // strcpy
    strcpy(dest, src);
    printf("%s\n", dest);


    char str1[50] = "Hello ";
    char str2[7] = "World!";
    // myStrcat
    myStrcat(str1, str2);
    myStrcat(str1, "!");
    printf("%s\n", str1);

    // myStrcmp
    char compare1[50] = "Text12";
    char compare2[50] = "Text12";
    if (myStrcmp(compare1, compare2) == 0)
    {
        printf("Equal\n");
    }
    else if(myStrcmp(compare1, compare2) > 0 )
    {
        printf("Greater\n");
    }
    else if(myStrcmp(compare1, compare2) < 0 )
    {
        printf("Lesser\n");
    }

    return 0;
}
