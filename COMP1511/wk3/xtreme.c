// Name of Exercise
// draw a fancy pattern
//
// This program was written by Adrian Chen(z5592060)
// on 26/02/2024
//
// One line summary of what this exercise does.
// draw an x pattern

#include <stdio.h>

int main (void) {
    int n, half;
    int row = 0;
    int column = 0;
    printf("Enter size: ");
    scanf(" %d", &n);
    half = n / 2;
    while (row <= half) {
        while (column <= half - row) {
            if (column % 4 == 0) {
                printf("*");
            }
            else {
                printf("-");
            }
            column++;
        }
        column--;
        while (column > 0 - row) {
            column--;
            if (column % 4 == 0) {
                printf("*");
            }
            else {
                printf("-");
            }
        }
        printf("\n");
        row++;
        column = 0 - row;
    }
    row -= 2;
    column = 0 - row;
    while (row >= 0) {
        while (column <= half - row) {
            if (column % 4 == 0) {
                printf("*");
            }
            else {
                printf("-");
            }
            column++;
        }
        column--;
        while (column > 0 - row) {
            column--;
            if (column % 4 == 0) {
                printf("*");
            }
            else {
                printf("-");
            }
        }
        printf("\n");
        row--;
        column = 0 - row;
    }

    return 0;
}