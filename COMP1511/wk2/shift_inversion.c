//z5592060

#include <stdio.h>


int main(void) {
    char user_input, yn, result;
    int shift, shift_test;
    printf("Please enter a character: ");
    scanf(" %c", &user_input);
    printf("Would you like to invert the case? y or n: ");
    scanf(" %c", &yn);
    printf("By how much would you like to shift the character? ");
    scanf(" %d", &shift);
    result = user_input;
    shift_test = result;
    shift = shift % 26;
    if (yn == 'y') {
        if (user_input >= 'a' && user_input <= 'z') {
            result = result+'A'-'a';

        }
        else if (user_input >= 'A' && user_input <= 'Z') {
            result = result+'a'-'A';
        }
    }
    shift_test = result + shift;
    if (shift_test >= 123) {
        result = result - 26;
    }
    else if (shift_test >= 91 && user_input <= 'Z') {
        result = result - 26;
    }
    result = result + shift;
    printf("The character is %c! \n", result);
    return 0;
}