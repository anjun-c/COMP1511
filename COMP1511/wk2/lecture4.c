#include <stdio.h>


int main(void){
    int countrow, countcolumn, rowmax, columnmax, result;
    char operation;
    printf("Insert first integer that you would like to create a table with:");
    scanf(" %d", &rowmax);
    printf("Insert second integer that you would like to create a table with:");
    scanf(" %d", &columnmax);
    printf("What operation would you like to use? \n");
    printf("Addition: a, Subtraction: s, Multiplication: m, Division: d \n");
    scanf(" %c", &operation);
    while (operation != 'a' && operation != 's' && operation != 'm' && operation != 'd'){
        printf("The operation is invalid. \n");
        printf("What operation would you like to use? \n");
        printf("Addition: a, Subtraction: s, Multiplication: a, Division: d \n");
        scanf(" %c", &operation);
    }
    countrow = 1;
    countcolumn = 1;
    result = 0;
    printf(" ");
    while (countrow <= rowmax){
        printf("%d", countrow);
        while(countcolumn <= columnmax){
            if (operation == 'a'){
                result = countcolumn + countrow;
            }
            else if (operation == 's'){
                result = countcolumn - countrow;
            }
            else if (operation == 'm'){
                result = countcolumn * countrow;
            }
            else if (operation == 'd'){
                result = countcolumn / countrow;
            }
            printf(" %d", result);
            countcolumn = countcolumn + 1;
        }
        countcolumn = 1;
        printf("\n");
        
        countrow = countrow + 1;
    }

    return 0;
}

/*
int poppin = 0;
    char response = 'n';
    while (response != 'g'){
        printf("whats poppin g \n");
        scanf(" %c", &response);
    }
    
*/