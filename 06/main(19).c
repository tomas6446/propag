#include <stdio.h>

int main()
{
    int n, fact = 1;

    do
    {
        printf("Skaicius: ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("Skaicius turi buti teigiamas\n");
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                fact *= i; // factorial
            }
            //output
            printf("Factorial: %d", fact);
            FILE *output;
            output = fopen("out.txt", "w");
            fprintf(output, "Factorial: %d \t", fact);
            fclose(output);

            break;
        }
    } while (1); // while stop != true

    return 0;
}
