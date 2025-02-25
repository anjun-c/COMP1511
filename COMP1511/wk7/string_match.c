// adrian chen z5592060 april 2024

#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 128

void swap_pointers(int *a, int *b);

int main(void) {
    char search[MAX_LIMIT], list[MAX_LIMIT];
    int count = 0;
    printf("Enter the search term: ");
    fgets(search, MAX_LIMIT, stdin);
    printf("Enter the list of strings:\n");
    while (fgets(list, MAX_LIMIT, stdin) != NULL) {
        if (strcmp(search, list) == 0) {
            count++;
        }
    }
    printf("There was %d occurrence(s) of the search term in the input.\n", count);

    
    return 0;
}
