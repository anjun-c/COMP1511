// averages from a mallocd arrayh
// Written by adrian chen z5592060
// april 2024

#include <stdio.h>
//TODO add correct #include for malloc
#include <stdlib.h>

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////

int *scan_array(int size);
double calculate_average(int *array, int size);

int main (void) {

    int size;
    printf("Enter size: ");
    scanf(" %d", &size);
    if (size <= 0) {
        printf("Invalid Size\n");
        return 1;
    }
    printf("Enter %d integers:\n", size);
    int *array = scan_array(size);

    printf("The average of all values in the array is: %.2lf\n", 
           calculate_average(array, size));

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// A function which scans in `size` integers and stores them into a 
// malloc'd array.
// returns: a pointer to the malloc'd array
int *scan_array(int size) {
    // TODO: 1. create a MALLOC'd array of size `size`
    int* mallocarray = malloc(size * sizeof(int));

    // TODO: 2. Loop through and scan values into the array.
    int i = 0;
    while (i < size) {
        scanf(" %d", &mallocarray[i]);
        i++;
    }

    // TODO 3.delete the following line and return the array.
    return mallocarray;
}

// Given an integer array and it's size, 
// returns the sum of all elements inside the array, divided by the size of the
// array.
double calculate_average(int *array, int size) {
    
    // TODO calculate the sum of the array.
    int i = 0;
    double sum = 0;
    while (i < size) {
        sum += array[i];
        i++;
    }
    double avg = sum / size;

    return avg;
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
