// Name of Exercise
// street_fighter.c
//
// This program was written by YAdrian Chen(z5592060)
// on 26/02/2024
//
// One line summary of what this exercise does.
// Play a street fighter game

#include <stdio.h>

#define MAX_HEALTH 50.0
#define MAX_ATTACK 10

// Provided fighter struct
struct fighter {
    double attack;
    double health;
    char attack_command;
    double attack_low;
};

int main(void) {
    
    printf("Welcome to Street Fighter!\n");
    printf("\n");
    ////////////////////////////////////////////////////////////////////////////
    ///////////////////////// Fighter 1 Creation ///////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    struct fighter fighter1;

    // TODO: prompt and scan for fighter1's attack power and command. 
    //       Initialise fighter1's health to MAX_HEALTH

    printf("Enter Fighter 1's attack power (1-10): ");
    scanf(" %lf", &fighter1.attack);
    printf("Enter an ascii character for Fighter 1's attack command: ");
    scanf(" %c", &fighter1.attack_command);
    fighter1.attack_low = fighter1.attack * 1.5;
    fighter1.health = MAX_HEALTH;
    ////////////////////////////////////////////////////////////////////////////
    ///////////////////////// Fighter 2 Creation ///////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    // TODO: declare fighter2's struct and repeat the above for fighter2
    printf("\n");
    struct fighter fighter2;
    printf("Enter Fighter 2's attack power (1-10): ");
    scanf(" %lf", &fighter2.attack);
    printf("Enter an ascii character for Fighter 2's attack command: ");
    scanf(" %c", &fighter2.attack_command);
    fighter2.attack_low = fighter2.attack * 1.5;
    fighter2.health = MAX_HEALTH;

    ////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// Fight Loop ////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    // TODO: create a loop until one of the fighters loses all their health
    //       prompt the fighter to attack and print remaining health after 
    //       each round
    printf(" \n");
    printf("FIGHT! \n");
    printf(" \n");

    while (fighter1.health > 0 && fighter2.health > 0) {
        printf("Fighter 1, press %c to attack: ", fighter1.attack_command);
        scanf(" %c", &fighter1.attack_command);
        printf("Fighter 1 attacks! \n");
        fighter2.health = fighter2.health - fighter1.attack;
        if (fighter2.health < 25) {
            fighter2.attack = fighter2.attack_low;
        }
        printf("Fighter 2, press %c to attack: ", fighter2.attack_command);
        scanf(" %c", &fighter2.attack_command);
        printf("Fighter 2 attacks! \n");
        fighter1.health = fighter1.health - fighter2.attack;
        if (fighter1.health < 25) {
            fighter1.attack = fighter1.attack_low;
        }
        printf("\n");
        printf("Fighter 1's health: %.1lf\n", fighter1.health);
        printf("Fighter 2's health: %.1lf\n", fighter2.health);
    }
    printf("\n");
    if (fighter1.health <= 0 && fighter2.health <= 0) {
        printf("It's a draw!\n");
    }
    else if (fighter1.health <= 0) {
        printf("Fighter 2 wins!\n");
    }
    else {
        printf("Fighter 1 wins!\n");
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////// Fight Results ///////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    //  TODO: Print the results of the fight

    printf("GAME OVER\n");
    return 0;
}