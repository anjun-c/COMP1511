// Written by Adrian Chen z5592060
// 11/03/2024

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
void make_alternating(char string[MAX_STRING_LENGTH]);

int main (void) {
    //You don't need to understand this code to complete the exercise.

    //Scans in a string from the user.
    char buffer[MAX_STRING_LENGTH];
    fgets(buffer, MAX_STRING_LENGTH, stdin);

    // Runs your function
    make_alternating(buffer);

    // Prints resulting string.
    printf("%s", buffer);

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// Modifies `string` so that the first letter is converted to lowercase, 
// and the case of each following letter alternates.
// i.e. in the resulting string: 
//      the first letter is lowercase, 
//      second letter is uppercase, 
//      third letter is lower case, 
//      etc.
//
// e.g.: "Hello" -> "hElLo"
void make_alternating(char string[MAX_STRING_LENGTH]) {
    // TODO: complete this function
    int i = 0, n = 0;
    int len = strlen(string);
    printf("%d\n", len);
    while (n < len) {
        printf("%d", i);
        if ((string[n] >= 'A' && string[n] <= 'Z') || 
        (string[n] >= 'a' && string[n] <= 'z')) {
            if (i % 2 == 0) {
                if(string[n] >= 'A' && string[n] <= 'Z') {
                    string[i] = string[i] + 'a' - 'A';
                } 
            } 
            else {
                if(string[n] >= 'a' && string[n] <= 'z') {
                    string[i] = string[i] - 'a' + 'A';
                }
            }
            i++;
        }
        n++;
    }
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
