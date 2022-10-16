#include <stdio.h>
#include <math.h>

int Weekday(int year, int month, int day)
{
    int m;
    if (month > 2)
    {
        m = month; // for march to december month code is same as month
    }
    else
    {
        m = (12 + month); // for Jan and Feb, month code will be 13 and 14
        year--; // decrease year for month Jan and Feb
    }

    int y = year % 100; // last two digit
    int c = year / 100; // first two digit
    int w = (day + floor((13 * (m + 1)) / 5) + y + floor(y / 4) + floor(c / 4) + (5 * c)); // formula
    return w %= 7;
}

int main()
{
    int weekday;
    char format;
    int year, month, day;

    while (1)
    {
        printf("Enter date by the format(YYYY-MM-DD): ");
        scanf("%d %c %d %c %d", &year, &format, &month, &format, &day);
        if (format == '-' && (month <= 12 && day <= 31) && (day != 0 && month != 0))
        {
            weekday = Weekday(year, month, day); // calculating weekday
            break;
        }
        else
        {
            printf("Unsuitable format...\n");
        }
    }

    FILE *file = fopen("week.txt", "r");
    int count = 0, line_number = weekday; // line_number is line where weekday name is written...
    if (file != NULL)
    {
        char weekday_name[32]; // weekday name
        while (fgets(weekday_name, sizeof weekday_name, file) != NULL) // read line by line
        {
            if (count == line_number) // line number equals to weekday
            {
                printf("Day of the week: %s\n", weekday_name);
                break;
            }
            else
            {
                count++;
            }
        }
        fclose(file);
    }
    else
    {
        printf("File doesn't exist\n");
    }

    return 0;
}
