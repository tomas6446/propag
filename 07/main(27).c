#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(char *msg)
{
    int number;
    char buffer[256];

    do
    {
        printf("%s", msg);
        scanf("%255s", buffer);
        number = strtoul(buffer, NULL, 0);
    } while (number < 1);

    return number;
}

int main()
{
    printf("Positive number: %d", getPositiveNumber("Enter a positive number: "));

    return 0;
}
