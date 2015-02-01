#include <stdio.h>

struct date {
    int day_of_week;
    int month;
    int day;
    int year;
};

struct date get_tomorrow (struct date today) {
    int days_in_months[13] = {-1, 31, 28, 31, 30, 31, 
	30, 31, 31, 30, 31, 30, 31};
    if ((today.year % 4 == 0 && today.year % 100 != 0)
        || today.year % 400 == 0) {
        days_in_months[2]++;
    }
    today.day_of_week = (today.day_of_week + 1) % 7;
    ++today.day;
    if (today.day > days_in_months[today.month]) {
        ++today.month;
        today.day = 1;
    }
    //++today.month;
    if (today.month > 12) {
        ++today.year;
        today.month = 1;
    }
    return today;
}

int main(void) {
    struct date start = {1, 1, 1, 1900};
    struct date end = {.day = 31, .month = 12, .year = 2000};
    struct date today = start;
    int first_sundays = 0;
    while (today.day != 31 || today.month != 12 || today.year != 2000) {
        today = get_tomorrow(today);
        if (today.year >= 1901) {
            if (today.day_of_week == 0 && today.day == 1) {
                first_sundays++;
            }
        }
    }
    printf("%d\n", first_sundays);
    return 0;
}
