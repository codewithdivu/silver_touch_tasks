#include <stdio.h>

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month)
{
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && is_leap_year(year))
    {
        return 29;
    }
    else
    {
        return days[month];
    }
}

int get_day_of_week(int year, int month, int day)
{
    if (month < 3)
    {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return (dayOfWeek + 5) % 7;
}

void print_calendar(int year, int month)
{
    printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

    int firstDayOfWeek = get_day_of_week(year, month, 1);

    for (int i = 0; i < firstDayOfWeek; ++i)
    {
        printf("      ");
    }

    int days = days_in_month(year, month);
    for (int day = 1; day <= days; ++day)
    {
        printf("%6d", day);

        if ((firstDayOfWeek + day) % 7 == 0 || day == days)
        {
            printf("\n");
        }
    }
}

int main()
{
    int month;

    printf("Enter the month (1 to 12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12)
    {
        printf("Invalid month. Please enter a number between 1 and 12.\n");
        return 1;
    }

    int currentYear = 2024;

    printf("Calendar for %d/%d:\n", currentYear, month);
    print_calendar(currentYear, month);

    return 0;
}
