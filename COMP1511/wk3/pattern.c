#include <stdio.h>

int main (void) {
    int col;
    int row = 0;
    int max = 3;
    while (row <= max) {
        col = 0;
        while (col <= max){
            if (col == row) {
                printf("O");
            }
            else {
                printf("X");
            }
            col++;
        }
        printf(" \n");
        row++;
    }

    return 0;
}