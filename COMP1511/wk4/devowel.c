// by z5592060
// Adrian Chen
// Devowelling text
// prints out input but without lowercase vowels

#include <stdio.h>

char vowelchecker(char letter);

int main (void) {
    char letter;
    while (scanf("%c", &letter) == 1) {
        vowelchecker(letter);
    }
    
    return 0;
}

char vowelchecker (char letter) {
    if (letter != 'a' && letter != 'e' && letter != 'i' 
    && letter != 'o' && letter != 'u') {
        printf("%c", letter);
    }
}