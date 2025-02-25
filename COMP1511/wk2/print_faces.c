// by z5592060

#include <stdio.h>

int main(void) {
    char pos1, pos2, pos3, pos4;
    printf("How do you want to build a face?: ");
    scanf(" %c", &pos1);
    scanf(" %c", &pos2);
    scanf(" %c", &pos3);
    scanf(" %c", &pos4);

    if (pos1 == 'a') {
        printf("_");
    }
    else if (pos1 == 'b') {
        printf("~");
    }
    else if (pos1 == 'c') {
        printf("%c", 92);
    }
    else {
        printf("/");
    }

    if (pos2 <= 'd') {
        if (pos2 == 'a') {
            printf(" _ \n");
        }
        else if (pos2 == 'b') {
            printf(" ~ \n");
        }
        else if (pos2 == 'c') {
            printf(" %c \n", 92);
        }
        else {
            printf(" / \n");
        }

        printf("O O\n");

        if (pos3 == 'e') {
            printf(" ^ \n");
        }
        else {
            printf(" ~ \n");
        }

        if (pos4 == 'g') {
            printf("%c_/ \n", 92);
        }
        else if (pos4 == 'h') {
            printf("/-%c\n", 92);
        }
        else {
            printf(" o\n");
        }
    }

    else {
        if (pos1 == 'a') {
            printf(" _\n");
        }
        else if (pos1 == 'b') {
            printf(" ~\n");
        }
        else if (pos1 == 'c') {
            printf(" %c\n", 92);
        }
        else {
            printf(" /\n");
        }

        printf("O O\n");

        if (pos2 == 'e') {
            printf(" ^ \n");
        }
        else {
            printf(" ~ \n");
        }

        if (pos3 == 'g') {
            printf("%c_/ \n", 92);
        }
        else if (pos3 == 'h') {
            printf("/-%c\n", 92);
        }
        else {
            printf(" o\n");
        }
    }

    return 0;
}