// stellar_information.c
//
// This program simulates a star system in space
//
// Written by YOUR-NAME, YOUR-ZID
// on TODAYS-DATE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CONVERSION_CONSTANT 9.461e12
#define LIGHT_SPEED 299792.458
#define MAX_LENGTH 50

// TODO: TASK 1

struct star {
    char name[50];
    double distance;
    char spectral_type;
    double time;
};

void print_star_information(struct star *star);
void input_star_information(struct star *star);
void time_travel(struct star *star);

int main() {
    // TODO: TASK 2
    struct star star_ptr;
    input_star_information(&star_ptr);
    time_travel(&star_ptr);
    print_star_information(&star_ptr);

    return 0;
}

// Takes in the stars information
void input_star_information(struct star *star) {
    // TODO: TASK 3
    printf("Enter the star's name: ");
    fgets(star->name, MAX_LENGTH, stdin);
    int len = strlen(star->name);
    star->name[len - 1] = '\0';
    printf("Enter the star's distance from Earth (in light-years): ");
    scanf(" %lf", &star->distance);
    printf("Enter the star's spectral type: ");
    scanf(" %c", &star->spectral_type);
}

// Estimate travel time from Earth to the star based on star's distance
void time_travel(struct star *star) {
    // TODO: TASK 4
    double distance = star->distance * CONVERSION_CONSTANT;
    star->time = distance / LIGHT_SPEED;
}

// Prints the stars information
void print_star_information(struct star *star) {
    // TODO: TASK 5
    printf("\nStar's Information: \n");
    printf("Name: %s \n", star->name);
    printf("Distance: %lf light-years\n", star->distance);
    printf("Spectral Type: %c\n", star->spectral_type);
    printf("Estimated travel time from Earth: %.2lf seconds\n", star->time);
}
