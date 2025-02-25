// PROGRAM NAME
//
// Written 11/03/2024
// By Adrian Chen
// z5592060
// stores and prints 2d coordinates
//

#include <stdio.h>

#define MAX_POINTS 10

struct point {
    // TODO: fill this in so that the struct can hold an x and y position
    //
    // i.e. This struct should contain:
    //      the x-coordinate and y-coordinate (doubles).
    double x_coordinate, y_coordinate;
};

// Prints a point out.
void print_point(int point_no, double x, double y);

int main(void) {
    // TODO: Declare an array of points of size MAX_POINTS
    struct point points[MAX_POINTS];
    printf("How many points in the shape? ");
    // TODO: scan in number of points in the shape
    int number_of_points;
    scanf(" %d", &number_of_points);
    printf("Enter points:\n");
    // TODO: scan in the details of each point into the array
    int i = 0;
    while (i < number_of_points) {
        scanf(" %lf %lf", &points[i].x_coordinate, 
        &points[i].y_coordinate);
        i++;
    }
    printf("\nShape Points:\n");
    // TODO: print all the points
    i = 0;
    while (i < number_of_points) {
        printf("%d: x = %.3lf, y = %.3lf \n", i + 1, 
        points[i].x_coordinate, points[i].y_coordinate);
        i++;
    }

    return 0;
}

//  Prints a single point in the correct format.
//
// Parameters:
// - `point_no` -- The point number
// - `x`        -- The x-coordinate of the point
// - `y`        -- The y-coordinate of the point
//
// Returns: nothing.
void print_point(int point_no, double x, double y) {
    printf("%2d: x = %.3lf, y = %.3lf\n", point_no, x, y);
}
