#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    printf("%s", menuTitle);
    for (int i = 0; i < menuSize; i++)
    {
        printf("%s", menuOptions[i]);
    }

    char ch[256];
    int number;
    do
    {
        printf("%s", inputMsg);
        scanf("%256s", ch);
        number = strtol(ch, NULL, 0); // convert char into int (returns zero for letters)

        if (number <= menuSize && number > 0) // must be in range of numbers in the menu
        {
            break;
        }
        else
        {
            printf("Try again\n"); // if number is not in the range or letter
        }
    } while (1);


    return number;
}

int main()
{
    int menuSize = 4;

    char *menuTitle = "Menu:\n";
    char *menuOptions[] = {"1. A\n", "2. B\n", "3. C\n", "4. D\n"};
    char *inputMsg = "Enter number: ";

    int choice = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    printf("You chose %s\n", menuOptions[choice - 1]);
    return 0;
}
