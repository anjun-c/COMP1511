// adrian chen z5592060 april 2024

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i = 1, sum = 0, number;
    while (i < argc) {
        number = atoi(argv[i]);
        sum += number;
        i++;
    }
    printf("Sum: %d\n", sum);
    
    return 0;
}