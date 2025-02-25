#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int seed, rand1, rand2, nosize;
    int count;
    int answer;
    int useransw;
    // int numberofnumbers;
    // time_t time1;
    printf("Enter seed \n");
    scanf("%d", &seed);
    srand(seed);
    /* 
    printf("How many numbers? /n");
    scanf("%d", numberofnumbers);
    */
    printf("Random limit? \n");
    scanf("%d", &nosize);
    printf("\n");

    for (count = 1; count <= 1; ++ count){
        rand1 = rand() % nosize;
        printf("%d \n", rand1);
        rand2 = rand() % nosize;
        printf("%d \n", rand2);
    }
    
    printf("Type the answer to %d x %d: \n", rand1, rand2);
    answer = rand1 * rand2;
    scanf("%d", &useransw);
    
    if (useransw == answer){
        printf("Correct! \n");
    }
    else {
        printf("u dumb fuck \n");
    }

    return 0;
}