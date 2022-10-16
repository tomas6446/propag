#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maximum(int a, int b)
{
    return a > b ? b : a;
}

int minimum(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int a, b, c;
    char result_file[128] = "";
    printf("Program will find middle number\n");
    printf("Enter three numbers divided by ';' ( a;b;c ): ");
    scanf("%d %*c %d %*c %d", &a, &b, &c); // ignore ';'

    int max = maximum(maximum(a, b), c);
    int min = minimum(minimum(a, b), c);
    int mid = a + b + c - max - min;

    while (1)
    {
        printf("Enter name of the text file, where you want to save your result\n (must include .txt): ");
        scanf("%128s", result_file);

        FILE *file;
        file = fopen(result_file, "w");

        if (strstr(result_file, ".txt")) // check if file name you entered, has '.txt' in it
        {
            fprintf(file, "Middle number is %d", mid);
            printf("The result successfully saved in: %s", result_file);
            break; // leave loop
        }
        else
        {
            printf("\nNo .txt found in the name of the text file\n");
        }
        fclose(file);
    }


    return 0;
}
