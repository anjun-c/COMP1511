#include <stdio.h>

#define NUM_ROWS 4
#define MAX_COLS 100

// Return the number of rows that add up to 0
int count_neutral_rows(int size, int array[NUM_ROWS][MAX_COLS]) {
    int length_row = 4;
    int length_col = sizeof(array[4]) / sizeof(array[4][0]);
    int i = 0, j = 0, count = 0, neutral_rows = 0;
    while (i < length_row) {
        while (j < length_col) {
            count += array[i][j];
            j++;
        }
        if (count == 0) {
            neutral_rows++;
        }
        count = 0;
        j = 0;
        i++;
    }
    return neutral_rows;
}

// This is a simple main function which could be used
// to test your count_neutral_rows function.
// It will not be marked.
// Only your count_neutral_rows function will be marked.


int main(void) {
    int test_array[NUM_ROWS][MAX_COLS] = {
        {1, 2, 3, -3, 0},
        {1, 2, 0, -3, -3},
        {1, 4, 3, -3, -2},
        {1, -2, 3, -3, -3}
    };

    int result = count_neutral_rows(MAX_COLS, test_array);
    printf("%d\n", result);

    return 0;
}