#include <stdio.h>

#define MAX_ARRAY_SIZE 100

int main()
{
    int s, n;
    printf("Du skaiciai (s ir n): ");
    scanf("%d", &s);
    do
    {
        scanf("%d", &n);
        if (n < 0)
        {
            printf("n turi buti teigiamas: ");
        }
    } while (n < 0);

    int x[MAX_ARRAY_SIZE];
    printf("Skaiciai: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x[i] * x[j] == s)
            {
                printf("(%d, %d)\n", x[i], x[j]);
            }
        }
    }
    return 0;
}
