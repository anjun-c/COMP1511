// word_square.c
//
// makes a square of words
// Wrriten by Adrian Chen, ZID z5592060
// on TODAY'S DATE 11/03/2024

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    int i = 1;
    char str[MAX_SIZE];
    printf("Input word: ");
    fgets(str, MAX_SIZE, stdin);
    int len = strlen(str);
    printf("\nWord square is:\n");
    while (i < len) {
        printf("%s", str);
        i++;
    }

    return 0;
}