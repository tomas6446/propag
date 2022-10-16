#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_MISTAKES 1000

char *ordinal(int number)
{
    if (number % 10 == 1 && number % 100 != 11)
    {
        return "st";
    }
    else if (number % 10 == 2 && number % 100 != 12)
    {
        return "nd";
    }
    else if (number % 10 == 3 && number % 100 != 13)
    {
        return "rd";
    }
    return "th";
} // adds ordinal for result

void remove_signs(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ',' || string[i] == '.' || string[i] == '!' || string[i] == '?' || string[i] == ':' ||
            string[i] == '"')
        {
            string[i] = ' ';
        }
    }
} // removes ',' '.' '!' '?' ':' and etc, replaces with space

int search_dictionary(char *search_word)
{
    FILE *dictionary;
    dictionary = fopen("dictionary.txt", "r");
    char line[MAX_LINES];

    int equal = 0;
    while (fgets(line, sizeof(line), dictionary) != NULL) // gets line from the dictionary (1 line = 1 word)
    {
        line[strcspn(line, "\n")] = 0; // add end line to compare word with words from dictionary
        remove_signs(line); // removes punctuation marks
        for (int i = 0; i < strlen(line); i++) // symbol by symbol...
        {
            if (line[i] == search_word[i]) // finds searched word in the lists, equal = true
            {
                equal = 1;
            }
            else
            {
                equal = 0;
                break;
            }
        }
        if (equal == 1)
        {
            return 1;
        }
    }
    fclose(dictionary);
    return 0;
} // finds word in the dictionary

int main()
{
    FILE *text;
    text = fopen("text.txt", "r");
    char line[MAX_LINES];

    //char *mistake;
    int pos_line[MAX_MISTAKES], pos_word[MAX_MISTAKES];
    int line_counter = 0, word_counter = 0;
    int mistake_counter = 0;

    while (fgets(line, sizeof(line), text)) // prints out text in the console
    {
        printf("%s", line);
    }
    rewind(text); // rewinds text to print it out again
    printf("\n\n");

    while (fgets(line, sizeof(line), text) != NULL)
    {
        remove_signs(line);
        char *word = strtok(line, " \n\t"); // divide lines by spaces
        while (word != NULL)
        {
            if (search_dictionary(word) == 0) // finds no word in the dictionary
            {
                int choice;
                do
                {
                    printf("[ %s ] is Correct? (Yes - 1, No - 0): ", word);
                    scanf_s("%d", &choice);
                    printf("\n");
                    if (choice == 1) // adds to the dictionary
                    {
                        FILE *dictionary;
                        dictionary = fopen("dictionary.txt", "a");
                        fprintf(dictionary, "%s\n", word);
                        fclose(dictionary);
                        break;
                    }
                    else if (choice == 0) // word with mistake, saves word position in the text
                    {
                        pos_word[mistake_counter] = word_counter; // saves position of word
                        pos_line[mistake_counter] = line_counter; // saves position of line
                        mistake_counter++; // counts mistakes
                        break;
                    }
                } while (1);
            }
            word_counter++;
            word = strtok(NULL, " \n\t");
        }
        line_counter++;
        word_counter = 0;
    }
    fclose(text);

    if (mistake_counter == 0)
    {
        printf("\nNo mistakes has been found...\n");
    }
    else
    {
        printf("\n------------------------\n");
        printf("Mistakes\n");
        printf("------------------------\n");
        for (int i = 0; i < mistake_counter; i++)
        {
            printf("%d%s Line, %d%s word, (%s)\n", pos_line[i] + 1, ordinal(pos_line[i] + 1), pos_word[i] + 1,
                   ordinal(pos_word[i] + 1));
        }
        printf("------------------------\n");
    }

    return 0;
}
