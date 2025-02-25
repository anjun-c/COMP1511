// by Adrian Chen
// z5592060

#include <stdio.h>

int main (void) {
    int countto;
    int i = 0;
    printf("Enter number: ");
    scanf(" %d", &countto);
    if (countto >= 0) {
        while (i <= countto) {
            printf(" %d \n", i);
            i++;
        }
    }
    else {
        while (i >= countto) {
            printf(" %d \n", i);
            i--;
        }
    }

    return 0;
}