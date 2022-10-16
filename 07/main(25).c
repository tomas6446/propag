#include <stdio.h>

int isInRange(int *number, int *low, int *high)
{
    for (*low; *low <= *high; (*low)++)
    {
        if (*number == *low)
        {
            return 1; // true
        }
    }
    return 0; // false
}

int main()
{
    int number, low, high;
    printf("Enter three numbers: number and range (number = [low, high]): ");
    scanf("%d%d%d", &number, &low, &high);

    if (isInRange(&number, &low, &high) == 1) // true
    {
        printf("True\n");
    }
    else if(isInRange(&number, &low, &high) == 0) // false
    {
        printf("False\n");
    }
    return 0;
}
