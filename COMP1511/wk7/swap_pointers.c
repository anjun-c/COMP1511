// adrian chen z5592060 april 2024

#include <stdio.h>

void swap_pointers(int *a, int *b);

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int a = 1;
    int b = 2;
    
    swap_pointers(&a, &b);
    
    printf("%d, %d\n", a, b);
    return 0;
}

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    // PUT YOUR CODE HERE
    int first, second;
    first = *b;
    second = *a;
    *b = second;
    *a = first;
}
