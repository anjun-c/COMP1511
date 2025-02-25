// Name of Exercise
// custom cake
//
// This program was written by Adrian Chen(z5592060)
// on 26/02/2024
//
// One line summary of what this exercise does.
// Make a cake

#include <stdio.h>

int main (void) {
    int layer_number;
    int increment1 = 0;
    int increment2 = 0;
    printf("How many layers: ");
    scanf(" %d", &layer_number);
    printf("Please enter layers: ");
    while (layer_number > increment1) {
        char layerchar;
        scanf(" %c", &layerchar);
        while (layer_number > increment2) {
            printf("%c", layerchar);
            increment2++;
        }
        increment2 = 0;
        printf("\n");
        increment1++;
    }

    return 0;
}