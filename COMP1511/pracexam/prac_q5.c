// The following code is meant to ask the user to enter a string, print out
// what the user has entered and repeat this until the user enters Ctrl + d.
// However, it contains a number of errors that you need to fix. Good luck!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LETTERS 100

int main(void) {
    char my_arr[MAX_LETTERS];
    printf("Enter string: ");
    while (fgets(my_arr, MAX_LETTERS, stdin) != NULL) {
        printf("Input received: %s", my_arr);
        printf("Enter string: ");
    }

    return 0;
}
