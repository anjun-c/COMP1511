// The following code is meant to increment the time of 3 days, 4 hours
// and 59 minutes represented in a `struct time` variable and print out the
// resulting time.
// However, it contains a number of errors that you need to fix. Good luck!

#include <stdio.h>

struct time {
    int days;
    int hours;
    int minutes;
};

void increment_time(struct time *current_time);

int main(void) {
    struct time current_time;
    current_time.days = 3;
    current_time.hours = 4;
    current_time.minutes = 59;

    printf("One minute ago: %d days, %d hours and %d minutes\n",
           current_time.days, current_time.hours, current_time.minutes);

    increment_time(&current_time);

    printf("Now: %d days, %d hours and %d minutes\n", current_time.days,
           current_time.hours, current_time.minutes);

    return 0;
}

// increments the time by 1 minute
void increment_time(struct time *current_time) {
    current_time->minutes++;
    if (current_time->minutes == 60) {
        current_time->minutes = 0;
        current_time->hours++;
    }

    if (current_time->hours == 24) {
        current_time->hours = 0;
        current_time->days++;
    }
}
