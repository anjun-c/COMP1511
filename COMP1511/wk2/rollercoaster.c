#include <stdio.h>

#define MINHEIGHT 100
#define RIDEALONEHEIGHT 160

int main(void) {
    int userheight;
    int validheight = 0;

    while (validheight == 0){
        printf("What is your height in centimetres? \n");
        scanf("%d", &userheight);

        
        else if (userheight <= 0) {
            printf("Invalid height. Please enter a valid height. \n");
        }
        else {
            validheight = 1;
        }
    }



    if (userheight < MINHEIGHT){
        printf("Unfortunately, you are below the minimum height. You cannot ride. \n");
    }
    else if (userheight > MINHEIGHT && userheight < RIDEALONEHEIGHT){
        printf("Your height is insufficient to ride alone. You may ride only if accompanied by an adult above 160cm. \n");
    }
    else if (userheight > RIDEALONEHEIGHT){
        printf("You may ride alone. \n");
    }

    return 0;
}