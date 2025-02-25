// The following code is meant to find the minimum and maximum values in an
// array.
// However, it contains a number of errors that you need to fix. Good luck!

#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int scanned_length;
    int length_count = 0;
    int scanned_value;
    int scanned_num[MAX_SIZE];

    // Prompt user for the specific number of integers to be taken from input
    printf("How many numbers: ");
    scanf(" %d", &scanned_length);

    // Take in scanned_length number of integers
    printf("Please enter numbers: ");
    while (length_count < scanned_length) {
        scanf(" %d", &scanned_value);
        scanned_num[length_count] = scanned_value;

        length_count++;
    }

    // Iterate over the array and print the minimum and maximum values in the
    // array
    int index = 0;
    if (scanned_length > 0) {
        int minimum = scanned_num[0];
        int maximum = scanned_num[0];

        while (index < scanned_length) {
            if (scanned_num[index] < minimum) {
                minimum = scanned_num[index];
            } else if (scanned_num[index] > maximum){
                maximum = scanned_num[index];
            }

            index++;
        }

        printf("Minimum: %d\nMaximum: %d\n", minimum, maximum);
    }

    return 0;
}