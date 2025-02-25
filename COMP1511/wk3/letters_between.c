// Name of Exercise
// letters between
//
// This program was written by Adrian Chen(z5592060)
// on 26/02/2024
//
// One line summary of what this exercise does.
// print letters between

#include <stdio.h>

int main (void) {
    char start, target;
    int difference;
    printf("Please enter starting letter: ");
    scanf(" %c", &start);
    printf("Please enter target letter: ");
    scanf(" %c", &target);
    if (start < target) {
        difference = target - start;
        if (difference <= 13) {
            while (start <= target) {
                printf("%c", start);
                start++;
            }
        }
        else {
            printf("%c", start);
            while (start != target) {
                start--;
                if (start == 96 || start == 64) {
                    start = start + 26;
                }
                printf("%c", start);
            }
        }
    }
    else {
        difference = start - target;
        if (difference < 13) {
            while (start >= target) {
                printf("%c", start);
                start--;
            }
        }
        else {
            printf("%c", start);
            while (start != target) {
                start++;
                if (start == 123 || start == 91) {
                    start = start - 26;
                }
                printf("%c", start);

            }
        }
    }
    printf("\n");

    return 0;
}