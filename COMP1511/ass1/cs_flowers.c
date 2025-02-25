// cs_flowers
//
// This program was written by Adrian Chen z5592060
// on 16/03/2024
//
// Runs a game about flowers

#include <stdio.h>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

#define MAX_ROW 11
#define MAX_COL 11
#define TRUE 1
#define FALSE 0


//------------------------------------------------------------------------------
// Struct & Enum
//------------------------------------------------------------------------------

enum flower_state {
    NONE,
    DORMANT,
    DISTURBED,
    AWAKENED,
    ANXIOUS,
    ENERGETIC
};

struct flower {
    enum flower_state state;
    int tick;
    int roots;
};

enum tile_type {
    EMPTY,
    BUSH,
    BRANCH,
    DANGER,
    ROOT,
    POLLEN,
    SEEDLING,
    FLOWER,
};

struct tile {
    enum tile_type type;
    struct flower flower;
};

//------------------------------------------------------------------------------
// Your Function Prototypes
//------------------------------------------------------------------------------

void alert_flowers(struct tile map[MAX_ROW][MAX_COL], int player_cut_row, int player_cut_col);

void weak_point_protection(struct tile map[MAX_ROW][MAX_COL], int i, int j, int player_row, int player_col);

int check_flowers_near_player(int player_row, int player_col, int i, int j);

void root_attack(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col, int i, int j);

int danger_to_root(struct tile map[MAX_ROW][MAX_COL], int player_cut_row, int player_cut_col);

void player_spawn(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col);

void add_foilage(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col);

void add_flowers(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col, int *flower_number);

void move_w(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col);

void move_a(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col);

void move_s(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col);

void move_d(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col);

void cut_w(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col);

void cut_a(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col);

void cut_s(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col);

void cut_d(struct tile map[MAX_ROW][MAX_COL], int player_row, int player_col);

void roots_loop(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col, int *player_alive);

void count_flower_loop(struct tile map[MAX_ROW][MAX_COL], int *flower_number);

void game_end_check(int player_alive, int *game_running, char *player_command, int flower_number);

void roots_loop_cont(struct tile map[MAX_ROW][MAX_COL], int *player_row, int *player_col, int *player_alive, int i, int j);

//------------------------------------------------------------------------------
// Provided Function Prototypes
//------------------------------------------------------------------------------

void initialise_map(struct tile map[MAX_ROW][MAX_COL]);
void print_map(
    struct tile map[MAX_ROW][MAX_COL], 
    int player_row, 
    int player_col
);

void print_tile(struct tile tile);
void print_flower(struct flower flower);

//------------------------------------------------------------------------------
// Main Function
//------------------------------------------------------------------------------

int main(void) {
    struct tile map[MAX_ROW][MAX_COL];
    int flower_number = 0;
    initialise_map(map);

    printf("Welcome to CS Flowers!\n");

    // Stage 1.1 - Scan in the player position and print out the map
    int player_row, player_col;
    printf("Player's starting position: ");
    scanf(" %d %d", &player_row, &player_col);
    
    // Stage 1.2
    player_spawn(map, &player_row, &player_col);

    // Stage 1.3
    add_foilage(map, player_row, player_col);

    // Stage 2.1
    add_flowers(map, player_row, player_col, &flower_number);
    

    // Stage 2.2

    char player_command = 'n', cut_command;
    int player_alive = TRUE,
    game_running = TRUE;
    // start game
    printf("Game Started! \n");
    // first command
    printf("Enter command: ");
    if (scanf(" %c", &player_command) != 1) {
        game_running = FALSE;
    }
    //game loop
    while (game_running == TRUE) {
        if (player_command == 'w' && player_row - 1 >= 0) {
            // move functions
            move_w(map, &player_row, &player_col);
        }
        else if (player_command == 'a' && player_col - 1 >= 0) {
            move_a(map, &player_row, &player_col);
        }
        else if (player_command == 's' && player_row + 1 <= 10) {
            move_s(map, &player_row, &player_col);
        }
        else if (player_command == 'd' && player_col + 1 <= 10) {
            move_d(map, &player_row, &player_col);
        }

        // Stage 2.3
        
        else if (player_command == 'c') {
            scanf(" %c", &cut_command);
            if (cut_command == 'w' && player_row - 1 >= 0) {
                //cut funcitons
                cut_w(map, player_row, player_col);
            }
            else if (cut_command == 'a' && player_col - 1 >= 0) {
                cut_a(map, player_row, player_col);
            }
            else if (cut_command == 's' && player_row + 1 <= 10) {
                cut_s(map, player_row, player_col);
            }
            else if (cut_command == 'd' && player_col + 1 <= 10) {
                cut_d(map, player_row, player_col);
            }
        }

        // Stage 3.2 & 3.3
        // other game functions
        roots_loop(map, &player_row, &player_col, &player_alive);
    

        // Stage 3.1 

        count_flower_loop(map, &flower_number);
        print_map(map, player_row, player_col);

        game_end_check(player_alive, &game_running, &player_command, flower_number);
    }



    return 0;
}

//------------------------------------------------------------------------------
// Your Function
//------------------------------------------------------------------------------

// Stage 2.4
// Alerts all flowers around
void alert_flowers(struct tile map[MAX_ROW][MAX_COL], 
int player_cut_row, int player_cut_col) {
    int i = 0, j = 0;
    //printf(" %d %d", player_cut_row, player_cut_col);
    // Iterates through a 5x5 grid around the alert area
    while (i < 5) {
        // Verifies that it does not check a position outside of array
        if (player_cut_row - 2 + i >= 0 && player_cut_row - 2 + i <= 10) {
            while (j < 5) {
                // Verifies that it is inside array again
                if (player_cut_col - 2 + j >= 0 && player_cut_col - 2 + j <= 10) {
                    if (
                    // If there is a flower on that position, 
                    //then it increases its alert level and roots
                    map[player_cut_row - 2 + i][player_cut_col - 2 + j].type == FLOWER
                    && map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.state 
                    == DORMANT) {
                        map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.state 
                        = DISTURBED;
                        map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.roots 
                        += 1;
                    }
                    else if (
                    map[player_cut_row - 2 + i][player_cut_col - 2 + j].type == FLOWER
                    && map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.state 
                    == DISTURBED) {
                        map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.state 
                        = AWAKENED;
                        map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.roots 
                        += 2;
                    }
                    else if (
                    map[player_cut_row - 2 + i][player_cut_col - 2 + j].type == FLOWER
                    && map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.state 
                    == AWAKENED) {
                        map[player_cut_row - 2 + i][player_cut_col - 2 + j].flower.roots 
                        += 2;
                    }
                }
                j++;
            }
        }
        j = 0;
        i++; 
    }
}

// Stage 3.1
// Spawns bushes when flowers are defending
void weak_point_protection(struct tile map[MAX_ROW][MAX_COL], 
int i, int j, int player_row, int player_col) {
    int k = 0;
    // Modulus so that every second tick it adds a bush, but not when it is zero
    if (map[i][j].flower.tick % 3 == 2) {
        while (k < 1) {
            // Verifies that the tile to place bush is empty
            if ((map[i + 1][j].type == EMPTY || map[i + 1][j].type == BRANCH)
            && (i + 1 != player_row || j != player_col)) {
                // If it places does not place it on branch, 
                //then it does not run the loop again
                if (map[i + 1][j].type != BRANCH) {
                    k++;
                }
                map[i + 1][j].type = BUSH;
            }
            // Same code but for each different direction of bush placement
            else if ((map[i][j + 1].type == EMPTY || map[i][j + 1].type == BRANCH)
            && (i != player_row || j + 1 != player_col)) {
                if (map[i][j + 1].type != BRANCH) {
                    k++;
                }
                map[i][j + 1].type = BUSH;
            }
            else if ((map[i - 1][j].type == EMPTY || map[i - 1][j].type == BRANCH)
            && (i - 1 != player_row || j != player_col)) {
                if (map[i - 1][j].type != BRANCH) {
                    k++;
                }
                map[i - 1][j].type = BUSH;
            }
            else if ((map[i][j - 1].type == EMPTY || map[i][j - 1].type == BRANCH)
            && (i != player_row || j - 1 != player_col)) {
                if (map[i][j - 1].type != BRANCH) {
                    k++;
                }
                map[i][j - 1].type = BUSH;
            }
            else {
                k++;
            }
        }
        // Resets the tick timer for defensive moves
        map[i][j].flower.tick = 3;
    }
}

// Stage 3.3
// Checks if there are flowers right next to the player for root attack
int check_flowers_near_player(int player_row, int player_col, int i, int j) {
    int k = 0, l = 0, flower_near = FALSE;
    // Iterates through the tiles right next to the flower
    while (k < 3) {
        while (l < 3) {
            if (i - 1 + k == player_row && j - 1 + l == player_col) {
                flower_near = TRUE;
            }
            l++;
        }
        l = 0;
        k++;
    }
    return flower_near;
}

void root_attack(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col, int i, int j) {
    map[i][j].flower.roots -= 1;
    map[player_row][player_col].type = DANGER;
}

// Converting danger tiles to roots function
int danger_to_root(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col) {
    int i = 0, j = 0, player_alive = TRUE;
    // While loop to scan through every tile
    while (i < 10) {
        while (j < 10) {
            // Convert danger to root
            if (map[i][j].type == DANGER) {
                map[i][j].type = ROOT;
                if (i == player_row && j == player_col) {
                    // If tile converts to root while player is on it, it ends the game
                    player_alive = FALSE;
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
    return player_alive;
}

// Function to scan in player spawn position
void player_spawn(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col) {

    // Stage 1.2 - Validate the player's spawn and re-scan if invalid
    // verification that the tile is valid
    if (!(*player_row == 0 || *player_row == 10) 
    && !(*player_col == 0 || *player_col == 10)) {
        // keeps prompting for a new input if the input is constantly invalid
        while (!(*player_row == 0 || *player_row == 10) 
        && !(*player_col == 0 || *player_col == 10)) {
            printf("Invalid starting position!\n");
            printf("Re-enter starting position: ");
            scanf(" %d %d", &*player_row, &*player_col);
        }
    }     
    // prints map
    print_map(map, *player_row, *player_col);
}

// Stage 1.3 - Add foliage onto the map, starting with branches
void add_foilage(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col) {

    

    int foilage_number, foilage_row, foilage_col, length; 
    char foilage_type, orientation;
    int i = 0, j = 0;
    printf("How many tiles of foliage: ");
    // scans in number of foilage
    scanf(" %d", &foilage_number);
    // loop for number of foilages that need to be scanned in
    while (i < foilage_number) {
        scanf(" %c %d %d", &foilage_type, &foilage_row, &foilage_col);
        // if foilage is branch
        if (foilage_type == 'b' && 
        (foilage_col > 0 && foilage_col < 10) 
        && (foilage_row > 0 && foilage_row < 10)) {
            // add branch to map array
            map[foilage_row][foilage_col].type = BRANCH;
            printf("Branch added!\n");
        }
        // if foilage is bush
        else if (foilage_type == 'u') {
            scanf(" %c %d", &orientation, &length);
            // checks that bush is in bounds
            if ((foilage_col > 0 && foilage_col < 10) 
            && (foilage_row > 0 && foilage_row < 10)) {
                // check orientation
                if (orientation == 'v' && foilage_row + length <= 10) {
                    while (j < length) {
                        map[foilage_row + j][foilage_col].type = BUSH;
                        j++;
                    }
                    printf("Bush added!\n");
                    // adds bush
                }
                else if (orientation == 'h' && foilage_col + length <= 10) {
                    while (j < length) {
                        map[foilage_row][foilage_col + j].type = BUSH;
                        j++;
                    }
                    printf("Bush added!\n");
                }
                // if any of the verification fails, 
                //then invalidate the foilage submission
                else {
                    printf("Invalid foliage position!\n");
                }
            }
            else {
                printf("Invalid foliage position!\n");
            }
        }
        else {
            printf("Invalid foliage position!\n");
        }
        j = 0;
        i++;
    }
    print_map(map, player_row, player_col);
}

// adds flowers to the grid
void add_flowers(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col, int *flower_number) {
    int flower_col, flower_row;
    // scan no. of flowers
    printf("How many flowers: ");
    scanf(" %d", &*flower_number);
    int i = 0, j = 1;
    // adds in flowers at said positions
    if (*flower_number < 25) {
        while (i < *flower_number) {
            scanf(" %d %d", &flower_row, &flower_col);
            if ((flower_row > 0 && flower_row < 10 && flower_row % 2 == 1) 
            && (flower_col > 0 && flower_col < 10 && flower_col % 2 == 1)
            && map[flower_row][flower_col].type == EMPTY) {
                map[flower_row][flower_col].type = FLOWER;
                map[flower_row][flower_col].flower.state = DORMANT;
            }
            else {
                printf("Invalid flower position!\n");
            }
            i++;
        }
    }
    // if number is greater than 25, fill in all positions with flowers
    else {
        i = 1;
        while (i <= 9) {
            while (j <= 9) {
                if (map[i][j].type == EMPTY) {
                    map[i][j].type = FLOWER;
                    map[i][j].flower.state = DORMANT;
                }
                j += 2;
            }
            j = 1;
            i += 2;
        }
    }
    print_map(map, player_row, player_col);
}

// Functions for moving
// Function for moving up
void move_w(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col) {
    // check that there is no object in direction of movement
    if (map[*player_row - 1][*player_col].type != BUSH
    && map[*player_row - 1][*player_col].type != FLOWER
    && map[*player_row - 1][*player_col].type != ROOT) {
        *player_row -= 1;
        // moves player
        // if branch, then alert flowers
        if (map[*player_row][*player_col].type == BRANCH) {
            alert_flowers(map, *player_row, *player_col);
        }
        map[*player_row][*player_col].type = EMPTY;
    }
}

// same code, different direction
void move_a(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col) {
    if (map[*player_row][*player_col - 1].type != BUSH
    && map[*player_row][*player_col - 1].type != FLOWER
    && map[*player_row][*player_col - 1].type != ROOT) {
        *player_col -= 1;
        if (map[*player_row][*player_col].type == BRANCH) {
            alert_flowers(map, *player_row, *player_col);
        }
        map[*player_row][*player_col].type = EMPTY;
    }
}

void move_s(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col) {
    if (map[*player_row + 1][*player_col].type != BUSH
    && map[*player_row + 1][*player_col].type != FLOWER
    && map[*player_row + 1][*player_col].type != ROOT) {
        *player_row += 1;
        if (map[*player_row][*player_col].type == BRANCH) {
            alert_flowers(map, *player_row, *player_col);
        }
        map[*player_row][*player_col].type = EMPTY;
    }
}

void move_d(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col) {
    if (map[*player_row][*player_col + 1].type != BUSH
    && map[*player_row][*player_col + 1].type != FLOWER
    && map[*player_row][*player_col + 1].type != ROOT) {
        *player_col += 1;
        if (map[*player_row][*player_col].type == BRANCH) {
            alert_flowers(map, *player_row, *player_col);
        }
        map[*player_row][*player_col].type = EMPTY;
    }
}

// Function for cutting up
void cut_w(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col) {
    // checks that there is a valid object to cut
    int player_cut_row, player_cut_col;
    if (map[player_row - 1][player_col].type == BUSH
    || map[player_row - 1][player_col].type == FLOWER
    || map[player_row - 1][player_col].type == ROOT) {
        if (map[player_row - 1][player_col].type == FLOWER) {
            // if there is a flower to cut, then alert nearby flowers
            player_cut_row = player_row - 1;
            player_cut_col = player_col;
            alert_flowers(map, player_cut_row, player_cut_col);
            // empty the tile cut
            map[player_row - 1][player_col].type = EMPTY;
            map[player_row - 1][player_col].flower.state = NONE;
        }
        // if root, changes it to branch
        else if (map[player_row - 1][player_col].type == ROOT) {
            map[player_row - 1][player_col].type = BRANCH;
            map[player_row - 1][player_col].flower.state = NONE;
        }
        else {
            map[player_row - 1][player_col].type = EMPTY;
            map[player_row - 1][player_col].flower.state = NONE;
        }
    }
}

// Function for cutting left - same code
void cut_a(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col) {
    int player_cut_row, player_cut_col;
    if (map[player_row][player_col - 1].type == BUSH
    || map[player_row][player_col - 1].type == FLOWER
    || map[player_row][player_col - 1].type == ROOT) {
        if (map[player_row][player_col - 1].type == FLOWER) {
            player_cut_row = player_row;
            player_cut_col = player_col - 1;
            alert_flowers(map, player_cut_row, player_cut_col);
            map[player_row][player_col - 1].type = EMPTY;
            map[player_row][player_col - 1].flower.state = NONE;
        }
        else if (map[player_row][player_col - 1].type == ROOT) {
            map[player_row][player_col - 1].type = BRANCH;
            map[player_row][player_col - 1].flower.state = NONE;
        }
        else {
            map[player_row][player_col - 1].type = EMPTY;
            map[player_row][player_col - 1].flower.state = NONE;
        }
    }
}

// Function for cutting down
void cut_s(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col) {
    int player_cut_row, player_cut_col;
    if (map[player_row + 1][player_col].type == BUSH
    || map[player_row + 1][player_col].type == FLOWER
    || map[player_row + 1][player_col].type == ROOT) {
        if (map[player_row + 1][player_col].type == FLOWER) {
            player_cut_row = player_row + 1;
            player_cut_col = player_col;
            alert_flowers(map, player_cut_row, player_cut_col);
            map[player_row + 1][player_col].type = EMPTY;
            map[player_row + 1][player_col].flower.state = NONE;
        }
        else if (map[player_row + 1][player_col].type == ROOT) {
            map[player_row + 1][player_col].type = BRANCH;
            map[player_row + 1][player_col].flower.state = NONE;
        }
        else {
            map[player_row + 1][player_col].type = EMPTY;
            map[player_row + 1][player_col].flower.state = NONE;
        }
    }
}

// Function for cutting right
void cut_d(struct tile map[MAX_ROW][MAX_COL], 
int player_row, int player_col) {
    int player_cut_row, player_cut_col;
    if (map[player_row][player_col + 1].type == BUSH
    || map[player_row][player_col + 1].type == FLOWER
    || map[player_row + 1][player_col].type == ROOT) {
        if (map[player_row][player_col + 1].type == FLOWER) {
            player_cut_row = player_row;
            player_cut_col = player_col + 1;
            alert_flowers(map, player_cut_row, player_cut_col);
            map[player_row][player_col + 1].type = EMPTY;
            map[player_row][player_col + 1].flower.state = NONE;
        }
        else if (map[player_row][player_col + 1].type == ROOT) {
            map[player_row][player_col + 1].type = BRANCH;
            map[player_row][player_col + 1].flower.state = NONE;
        }
        else {
            map[player_row][player_col + 1].type = EMPTY;
            map[player_row][player_col + 1].flower.state = NONE;
        }
    }
}

// creates a loop for creating roots
void roots_loop(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col, int *player_alive) {
    int i = 0, j = 0;
    // checks whether player is alive or not still and converts danger to roots
    if (danger_to_root(map, *player_row, *player_col) == FALSE) {
        *player_alive = FALSE;
        *player_row = 11;
        *player_col = 11;
    }
    // places roots
    while (i <= 10) {
        while (j <= 10) {
            if (map[i][j].flower.state == DISTURBED 
            || map[i][j].flower.state == AWAKENED) {
                roots_loop_cont(map, &*player_row, 
                &*player_col, &*player_alive, i, j);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

// continued roots function
void roots_loop_cont(struct tile map[MAX_ROW][MAX_COL], 
int *player_row, int *player_col, int *player_alive, int i, int j) {
    if (map[i][j].flower.roots > 0 
    // checks whether there is a flower that has roots to attack player near
    && check_flowers_near_player(*player_row, *player_col, i, j) == TRUE) {
        // flower attacks
        root_attack(map, *player_row, *player_col, i, j);
    }
    // if no flower / no roots, then protect instead
    else {  
        weak_point_protection(map, i, j, *player_row, *player_col);
        if (map[i + 1][j].type == BUSH && map[i - 1][j].type == BUSH
        && map[i][j + 1].type == BUSH && map[i][j - 1].type == BUSH) {
            map[i][j].flower.tick = 0;
        }
        else if ((i + 1 == *player_row && j == *player_col)
        || (i - 1 == *player_row && j == *player_col)
        || (i == *player_row && j + 1 == *player_col)
        || (i == *player_row && j - 1 == *player_col)) {
            // managing flower tick so that it places protection at the correct time
            map[i][j].flower.tick = 1;
        }
        else if (map[i][j].flower.tick == 0) {
            map[i][j].flower.tick = 1;
        }
        map[i][j].flower.tick += 1;
    }
}


// just checks through the entire grid and counts the number of flowers
void count_flower_loop(struct tile map[MAX_ROW][MAX_COL], 
int *flower_number) {
    int i = 0, j = 0, count = 0;
    while (i < 10) {
        while (j < 10) {
            if (map[i][j].type == FLOWER) {
                count += 1;
            }
            j++;
        }
        j = 0;
        i++;
    }
    *flower_number = count;
}

// checks whether the game has ended. if not, then continue by scanning new input
void game_end_check(int player_alive, 
int *game_running, char *player_command, 
int flower_number) {
    if (player_alive == FALSE) {
        printf("The flowers have beaten us, and UNSW is lost forever!\n");
        *game_running = FALSE;
    }
    else if (flower_number == 0) {
        printf("All flowers are eradicated and UNSW has been saved!\n");
        *game_running = FALSE;
    }
    else {
        printf("Enter command: ");
        if (scanf(" %c", &*player_command) == 1 && *player_command != 'n') {
            *game_running = TRUE;
        }
        else {
            *game_running = FALSE;
        }
    }
}

//------------------------------------------------------------------------------
// Provided Functions
//------------------------------------------------------------------------------

/**
 * Initialises the game map with empty tiles, setting the type of each tile to 
 * `EMPTY` and initialising flower-related properties.
 *
 * @param map: The 2D array of `struct tile` representing the game map 
 *
 * @returns None
 *
**/
void initialise_map(struct tile map[MAX_ROW][MAX_COL]) {
    for (int row = 0; row < MAX_ROW; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            map[row][col].type = EMPTY;
            map[row][col].flower.state = NONE;
            map[row][col].flower.tick = 0;
            map[row][col].flower.roots = 0;
        }
    }
}

/**
 * Prints the game map 
 * 
 * @param map: The 2D array of `struct tile` representing the game map.
 * @param player_row: The row coordinate of the player.
 * @param player_col: The column coordinate of the player.
 *
 * @returns None
**/
void print_map(
    struct tile map[MAX_ROW][MAX_COL], 
    int player_row, 
    int player_col
) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            printf("+---");
        }
        printf("+\n");

        for (int j = 0; j < MAX_COL;j++) {
            printf("|");
            if (player_row != i || player_col != j) {
                print_tile(map[i][j]);
            } else if (map[i][j].type == EMPTY) {
                printf(" P ");
            } else if (map[i][j].type == DANGER) {
                printf("<P>");
            }
        }

        printf("|\n");
    }

    for (int j = 0; j < MAX_COL; j++) {
        printf("+---");
    }
    printf("+\n");
}

/**
 * Helper function which prints the representation of a single tile 
 * based on its type. 
 *
 * @params tile: The `struct tile` to be printed.
 *
 * @returns None
**/
void print_tile(struct tile tile) {
    if (tile.type == EMPTY) {
        printf("   ");
    } else if (tile.type == BUSH) {
        printf("###");
    } else if (tile.type == BRANCH) {
        printf("_/-");
    } else if (tile.type == DANGER) {
        printf("< >");
    } else if (tile.type == ROOT) {
        printf("<^>");
    } else if (tile.type == POLLEN) {
        printf(":::");
    } else if (tile.type == FLOWER) {
        print_flower(tile.flower);
    }
}

/**
 * Helper function which prints a visual representation of the 
 * flower face based on its state.
 *
 * @params flower: The `struct flower` containing the state of the flower.
 *
 * @returns None
 *
**/
void print_flower(struct flower flower) {
    if (flower.state == DORMANT) {
        printf("uwu");
    } else if (flower.state == DISTURBED) {
        printf("uwo");
    } else if (flower.state == AWAKENED) {
        printf("owo");
    } else if (flower.state == ANXIOUS) {
        printf("o~o");
    } else if (flower.state == ENERGETIC) {
        printf("*w*");
    }
}

