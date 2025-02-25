// Name of Exercise
// print grid
//
// This program was written by Adrian Chen(z5592060)
// on 26/02/2024
//
// One line summary of what this exercise does.
// print a grid

#include <stdio.h>

int main (void) {
    int size;
    int row = 0;
    int col = 0;
    printf("Enter size:");
    scanf(" %d", &size);
    while (row < size) {
        while (col < size) {
            printf("(%d, %d) ", row, col);
            col++;
        }
        printf("\n");
        col = 0;
        row++;
    }

    return 0;
}