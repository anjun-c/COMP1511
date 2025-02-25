// adrian chen z5592060 april 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20000

int main(int argc, char *argv[]) {
    printf("Enter text: ");
    char str[MAX_LENGTH];
    char str1[MAX_LENGTH];
    strcpy(str1, argv[1]);
    fgets(str, MAX_LENGTH, stdin);
    int i = 0;
    int len = strlen(str);
    int calc;
    while (i < len) {
        printf(" %d", str[i]);
        if (str[i] <= 'Z' && str[i] >= 'A') {
            calc = str[i] - 64;
            str[i] = str1[calc] + 64;
            printf("%d", str1[calc]);
        }
        else if (str[i] <= 'z' && str[i] >= 'a') {
            calc = str[i] - 96;
            str[i] = str1[calc] + 96;
            printf(" %d", str1[calc]);
        }
        printf(" %d", str[i]);
        i++;
    }
    printf("%s", str);

    
    return 0;
}