#include <stdio.h>
#include <string.h>

int main()
{
    int true = 1;
    char email[100];
    while (true)
    {
        printf("Enter email address (write 0 to stop program): ");
        scanf("%s", email);
        if (email[0] == '0')
        {
            break;
        }

        int address_sign = 0;
        int dot = 0;
        int correct = 1; // boolean that checks if email is correct
        int after_sign = 0; // boolean for situation when @ sign was already placed

        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@')
            {
                address_sign++;
                after_sign = 1;
            }
            if (email[i] == '.' && after_sign == 1)
            {
                dot++;
            }
            if ((email[i] == '@' && email[i + 1] == '.') || (address_sign > 1 && dot > 1) ||
                (email[i] == '.' && email[i + 1] == '\0'))
            {
                correct = 0;
                break;
            }
        }

        FILE *file;
        file = fopen("emails.txt", "a");
        if (correct == 1 && address_sign == 1 && dot == 1)
        {
            printf("%s is added in database.\n\n", email, email);
            fprintf(file, "%s\n", email);
        }
        else
        {
            printf("%s is not correct, try again.\n\n", email);
        }
        fclose(file);
    }


    return 0;
}
