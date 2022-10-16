#include <stdio.h>
#include <string.h>
#include <assert.h>

unsigned int myStrlen(const char *string)
{
    int i = 0;
    while(*(string + i) != '\0') {
        i++;
    }
    return i;
}

int main()
{
    char string[10] = "string";
    printf("%d\n", myStrlen(string));
    return 0;
}
