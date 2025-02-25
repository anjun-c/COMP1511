#include <stdio.h>

int main(void) {
    double divisor, dividend;
    double result;
    printf("Enter the dividend: ");
    scanf("%lf", &dividend);
    printf("Enter the divisor: ");
    scanf("%lf", &divisor);
    if (divisor == 0){
        printf("Don't be silly! \n");
    }
    else{
        printf("%.lf divided by %.lf \n", dividend, divisor);
        result = dividend/divisor;
        printf("To the nearest integer: %.lf \n", result);
        printf("To 1 decimal place: %.1lf \n", result);
        printf("To 5 decimal places: %.5lf \n", result);
        printf("To 20 decimal places: %.20lf \n", result);
    }

    return 0;
}