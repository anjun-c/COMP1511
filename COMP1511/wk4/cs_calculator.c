// cs_calculator.c
//
// This program was written by Adrian Chen (z5592060)
// on 11/03/2024
//
// a simple calculator

#include <stdio.h>

int main(void) {
    int no1, no2, result, i;
    char instruction;
    printf("Enter instruction: ");
    while (scanf(" %c", &instruction) == 1) {
        if (instruction == 's') {
            scanf(" %d", &no1);
            result = no1 * no1;
        }
        else {
            scanf(" %d %d", &no1, &no2);
            i = 1;
            result = no1;
            while (i < no2) {
                result = result * no1;
                i++;
            }
        }
        printf("%d\n", result);
        printf("Enter instruction: ");
    }

    return 0;
}