#include <stdio.h>

int main(void) {
    int i = 0, N, half, add = 0, column, j = 1, trunk;
    scanf("%d", &N);
    half = (N*2) / 2;
    column = (N * 2) - 1;
    trunk = N / 3;
    while (i < N) {
        while (j <= column) {
            if (j >= half - add && j <= half + add) {
                printf("*");
            }
            else {
                printf(".");
            }
            j++;
        }
        printf("\n");
        j = 1;
        add++;
        i++;
    }
    i = 0;
    j = 1;
    half = N*2 / 2;
    while (i <= trunk) {
        while (j <= column) {
            if (j == half) {
                printf("*");
            }
            else {
                printf(".");
            }
            j++;
        }
        j = 1;
        printf("\n");
        i++;
    }

    return 0;
}