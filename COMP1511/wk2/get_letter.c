// Program which prints a letter depending on the user's request.
// by z5592060

#include <stdio.h>

int main(void) {
    char is_uppercase;
    printf("Uppercase: ");
    scanf(" %c", &is_uppercase);

    int index;
    printf("Index: ");
    scanf(" %d", &index);
    // TODO: finish the program
    if (is_uppercase == 'y') {
        index = index + 65;
    }
    else if (is_uppercase == 'n') {
        index = index + 97;
    }
    printf("The letter is %c \n", index);



    return 0;
}