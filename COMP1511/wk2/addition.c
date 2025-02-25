// part2_constants
//
// This program was written by Adrian Chen, z5592060
// on 19/02/24
// 
// This program sums together the number of students and tutors
// in a class

#include <stdio.h>

int main(void) {
    int students, tutors, total;
    printf("Please enter the number of students and tutors: ");
    scanf("%d %d", &students, &tutors);
    total = students + tutors;
    printf("%d + %d = %d\n", students, tutors, total);

    return 0;
}