#include <stdio.h>
#include <math.h>

#define PI 3.1415

int main(void){
    float radius;
    float area;
    printf("Insert the radius of circle that you would like to calculate the area of. \n");
    scanf("%f", &radius);
    area = PI*powf(radius, 2);
    printf("The area of a circle of radius %.10g is %.0f to the nearest integer. \n", radius, area);

    return 0;
}