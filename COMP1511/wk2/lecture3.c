#include <stdio.h>

#define PI 3.14

int main(void){

    int number;
    int scanf_return;
    scanf("%d", &number);

    if (number == 0){
        printf("number is 0 \n");
    }
    else if (number % 2 == 0){
        printf("even \n");
    }
    else {
        printf("odd \n");
    }
    
    return 0;
}