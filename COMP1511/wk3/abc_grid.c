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
    char starting_letter, printletter;
    int row_max, column_max, startx, starty;
    int charshift;
    int row = 0;
    int column = 0;
    int half_row_max = row_max / 2;
    int half_column_max = column_max / 2;
    printf("How many rows?: ");
    scanf(" %d", &row_max);
    printf("How many columns?: ");
    scanf(" %d", &column_max);
    printf("Please choose a starting letter: ");
    scanf(" %c", &starting_letter);
    printf("Please enter starting coordinates: ");
    scanf(" %d %d", &startx, &starty);
    while (row < row_max) {
        while (column < column_max){
            if (column <= row_max / 2){
                charshift = row + column - startx - starty;
            }
            else {
                charshift = startx + starty - row - column;
            }
            printletter = starting_letter - charshift;
            printf("%c", printletter);
            column++;
        }
        printf("\n");
        column = 0;
        row++;
    }

    return 0;
}
