#include <stdio.h>

long getFactorial(int *factorial)
{
    if(*factorial > 1)
    {
        int temp = *factorial - 1;
        return *factorial *= getFactorial(&temp);
    }
    else if(*factorial == 1)
    {
        return *factorial;
    }
    return 0;
}

int main()
{
    int factorial;
    printf("Enter number: ");
    scanf("%d", &factorial);
    factorial = getFactorial(&factorial);

    printf("Factorial: %d\n", factorial);
    return 0;
}
