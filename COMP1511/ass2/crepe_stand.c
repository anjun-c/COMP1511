// Assignment 2 24T1 COMP1511: Crepe Stand
// crepe_stand.c
//
// This program was written by z5592060
// on 2024-04
//
// Version 1.0.0: Assignment released.
//
// DESCRIPTION OF YOUR PROGRAM HERE
// make a crepe stand

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "crepe_stand.h"

#define SIG_STRAWBERRY 's'
#define SIG_MATCHA 'm'
#define SIG_CHOCOLATE 'c'
#define NO_SIG_SOLD 'n'
#define NO_SIG_MOST_POP 'N'

// Add any extra #includes your code needs here.

#include <math.h>

// Your enums go here:


// Add your own #defines here:

#define CUSTOM 'u'


////////////////////////////////////////////////////////////////////////////////

// A single crepe
//      Stores all the information about a single crepe.
//      Forms a linked list of crepes by pointing to the next one (or NULL).
struct crepe {
    // Name of the customer who ordered the crepe
    char customer_name[MAX_STR_LEN];

    // The batter the crepe will be made out of
    // ORIGINAL, CHOCOLATE or MATCHA
    enum batter_type batter;

    // There can be no topping or one topping
    // NO_TOPPING, BANANA, STRAWBERRY, NUTELLA
    enum topping_type topping;

    // Whether or not the crepe is gluten free;
    // Can be 1 or 0
    int is_gluten_free;

    // Size of the crepe in centimeters
    int diameter_cm;

    // what type of signature crepe is it
    char signature_type;

    // A pointer to the next crepe in the orders list
    // Is NULL if this crepe is the tail of the list.
    struct crepe *next;
};

// A particular day’s list of orders
struct day {
    // Date of the day as a struct day, with fields year, month, day
    struct date date;

    // A pointer to the start of the list of this day's orders
    struct crepe *orders;

    // The total income for the day
    // i.e. the total summed price of all crepes
    double income;

    // A pointer to the next day's orders
    // Is NULL if this day is the tail of the list.
    struct day *next;
};

// Add any other structs you define here.

////////////////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.

// Stage 1


// Creates a new custom crepe
//
// Parameters:
//      customer_name - name of customer ordering
//      batter - batter base of crepe
//      topping - topping for the crepe
//      is_gluten_free - 1 if it is GF, 0 if not
//      diameter_cm - how large crepe is in cm
// Returns:
//      pointer to newly created struct crepe
//
struct crepe *create_crepe(char *customer_name,
                           enum batter_type batter,
                           enum topping_type topping,
                           int is_gluten_free,
                           int diameter_cm,
                           char signature_type);

int append_check_valid_crepe(enum batter_type batter,
                        enum topping_type topping,
                        int is_gluten_free,
                        int diameter_cm);

// Stage 2

int get_list_length(struct day *current_day);

int insert_check_valid_crepe(int position, int length, enum batter_type batter,
                        enum topping_type topping,
                        int is_gluten_free,
                        int diameter_cm);

struct crepe *create_signature_crepe(char *customer_name, char *crepe_type);

// Stage 3

int compare_dates(struct date date1, struct date date2);

char count_signature_crepe(struct day *day);

int count_days(struct day *day_one);

void delete_all_crepes(struct day *day);

struct day *overdeep_cycle_days(char command,
                       struct day *day_one,
                       struct day *current_day);

// Stage 4

int week_day_end(struct date date);

// You need to implement the following functions.
// You can find descriptions of what each function
// should do in crepe_stand.h

//////////////////////////////////////////////////////////////////////
//                        Stage 1 Functions                         //
//////////////////////////////////////////////////////////////////////

// Provided Function stubs:

// creates a new day (using malloc) and 
// initialises all the fields within struct day
struct day *create_day(struct date new_date) {
    struct day *new_day = malloc(sizeof(struct day));
    new_day->date = new_date;
    new_day->orders = NULL;
    new_day->income = 0;
    new_day->next = NULL;
    return new_day;
}

// creates a new crepe (using malloc) and 
// initialises all the fields within struct crepe
// to the input given
struct crepe *create_crepe(char *customer_name,
                           enum batter_type batter,
                           enum topping_type topping,
                           int is_gluten_free,
                           int diameter_cm, 
                           char signature_type) {

    struct crepe *new_crepe = malloc(sizeof(struct crepe));
    strcpy(new_crepe->customer_name, customer_name);
    new_crepe->batter = batter;
    new_crepe->topping = topping;
    new_crepe->is_gluten_free = is_gluten_free;
    new_crepe->diameter_cm = diameter_cm;
    new_crepe->next = NULL;
    new_crepe->signature_type = signature_type;
    return new_crepe;
}

// adds a custom crepe to the end of the list
int append_crepe_custom(struct day *current_day,
                        char *customer_name,
                        enum batter_type batter,
                        enum topping_type topping,
                        int is_gluten_free,
                        int diameter_cm) {
    int check = append_check_valid_crepe(batter, 
    topping, is_gluten_free, diameter_cm);
    // checks that all inputs are valid
    if (check != 0) {
        return check;
    }
    // cases for whether list is empty or not
    if (current_day->orders == NULL) {
        struct crepe *new_crepe = create_crepe(customer_name, 
        batter, topping, is_gluten_free, diameter_cm, 'u');
        current_day->orders = new_crepe;
    }
    else {
        struct crepe *p = current_day->orders;
        while (p->next != NULL) {
            p = p->next;
        }
        struct crepe *new_crepe = create_crepe(customer_name, 
        batter, topping, is_gluten_free, diameter_cm, 'u');
        p->next = new_crepe;
    }
    return 0;
}

// adds a signature crepe to the end of the list
int append_crepe_signature(struct day *current_day,
                           char *customer_name,
                           char *crepe_type) {
    // different cases for each signature crepe
    if (strcmp(crepe_type, "matcha") == 0) {
        if (current_day->orders == NULL) {
            struct crepe *new_crepe = create_crepe(customer_name, 
            MATCHA, STRAWBERRY, 0, 25, 'm');
            current_day->orders = new_crepe;
        }
        else {
            struct crepe *p = current_day->orders;
            while (p->next != NULL) {
                p = p->next;
            }
            struct crepe *new_crepe = create_crepe(customer_name, 
            MATCHA, STRAWBERRY, 0, 25, 'm');
            p->next = new_crepe;
        }
    }
    else if (strcmp(crepe_type, "strawberry") == 0) {
        if (current_day->orders == NULL) {
            struct crepe *new_crepe = create_crepe(customer_name, 
            ORIGINAL, STRAWBERRY, 1, 25, 's');
            current_day->orders = new_crepe;
        }
        else {
            struct crepe *p = current_day->orders;
            while (p->next != NULL) {
                p = p->next;
            }
            struct crepe *new_crepe = create_crepe(customer_name, 
            ORIGINAL, STRAWBERRY, 1, 25, 's');
            p->next = new_crepe;
        }
    }
    else if (strcmp(crepe_type, "chocolate") == 0) {
        if (current_day->orders == NULL) {
            struct crepe *new_crepe = create_crepe(customer_name, 
            CHOCOLATE, NUTELLA, 0, 25, 'c');
            current_day->orders = new_crepe;
        }
        else {
            struct crepe *p = current_day->orders;
            while (p->next != NULL) {
                p = p->next;
            }
            struct crepe *new_crepe = create_crepe(customer_name, 
            CHOCOLATE, NUTELLA, 0, 25, 'c');
            p->next = new_crepe;
        }
    }
    return VALID_CREPE;
}

// simple loop to print out all crepes in the list
void print_crepes(struct day *current_day) {
    struct crepe *print = current_day->orders;
    int i = 1;
    // cases for whether the list is empty or not
    if (print == NULL) {
        print_no_crepes();
    }
    else {
        print_single_crepe(print, i);
        while (print->next != NULL) {
            print = print->next;
            i++;
            print_arrow();
            print_single_crepe(print, i);
        }
    }
}

// counts the number of crepes in a certain day
int count_crepes(struct day *current_day) {
    struct crepe *count = current_day->orders;
    int i = 0;
    if (count == NULL) {
        return 0;
    }
    else {
        while (count != NULL) {
            count = count->next;
            i++;
        }
    }
    return i;
}

// Your functions go here (include function comments):

// checks whether each property of the crepe is valid
int append_check_valid_crepe(enum batter_type batter,
                        enum topping_type topping,
                        int is_gluten_free,
                        int diameter_cm) {
    if (batter != ORIGINAL && batter != CHOCOLATE && batter != MATCHA) {
        return INVALID_BATTER;
    }
    else if (topping != NO_TOPPING && topping != BANANA 
    && topping != STRAWBERRY && topping != NUTELLA) {
        return INVALID_TOPPING;
    }
    else if (is_gluten_free != 0 && is_gluten_free != 1) {
        return INVALID_GFO;
    }
    else if (diameter_cm < 10 || diameter_cm >= 40) {
        return INVALID_SIZE;
    }
    else {
        return VALID_CREPE;
    }
}

//////////////////////////////////////////////////////////////////////
//                        Stage 2 Functions                         //
//////////////////////////////////////////////////////////////////////

// Provided function stubs:

// insters a custom crepe at specifies position
int insert_crepe_custom(struct day *current_day,
                        int position,
                        char *customer_name,
                        enum batter_type batter,
                        enum topping_type topping,
                        int is_gluten_free,
                        int diameter_cm) {
    //gets the length of the list
    int length = get_list_length(current_day), 
    i = 1,
    // checks that values are valid
    check = insert_check_valid_crepe(position, length, 
    batter, topping, is_gluten_free, diameter_cm);
    if (check != 0) {
        return check;
    }
    // case for inserting at the beginning of the list
    if (position == 1) {
        struct crepe *new_crepe = create_crepe(customer_name, 
        batter, topping, is_gluten_free, diameter_cm, 'u');
        if (current_day->orders != NULL) {
            new_crepe->next = current_day->orders;
            current_day->orders = new_crepe;
        }
        else {
            current_day->orders = new_crepe;
            new_crepe->next = NULL;
        }
    }
    // if position ofr inserting is greater than list length
    else if (position > length) {
        append_crepe_custom(current_day, customer_name, 
        batter, topping, is_gluten_free, diameter_cm);
    }
    // inserting crepe in specified position
    else {
        struct crepe *temp = current_day->orders;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        struct crepe *new_crepe = create_crepe(customer_name, 
        batter, topping, is_gluten_free, diameter_cm, 'u');
        new_crepe->next = temp->next;
        temp->next = new_crepe;
    }
    return check;
}

// inserts a signature crepe at position
int insert_crepe_signature(struct day *current_day,
                           int position,
                           char *customer_name,
                           char *crepe_type) {
    // very similar code to inserting custom crepe, 
    // but we do not need to check whether inputs are valid
    int length = get_list_length(current_day), 
    i = 1;
    if (position == 1) {
        struct crepe *new_crepe = create_signature_crepe(customer_name, 
        crepe_type);
        if (current_day->orders != NULL) {
            new_crepe->next = current_day->orders;
            current_day->orders = new_crepe;
        }
        else {
            current_day->orders = new_crepe;
            new_crepe->next = NULL;
        }
    }
    else if (position > length) {
        append_crepe_signature(current_day, customer_name, 
        crepe_type);
    }
    else {
        struct crepe *temp = current_day->orders;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        struct crepe *new_crepe = create_signature_crepe(customer_name, 
        crepe_type);
        new_crepe->next = temp->next;
        temp->next = new_crepe;
    }
    return 0;
}

// gets the statistics of crepe orders in a day
struct stats get_stats(struct day *current_day) {
    struct crepe *count = current_day->orders;
    // initialises the struct
    struct stats stats;
    stats.total_crepes = 0;
    stats.original = 0;
    stats.chocolate = 0;
    stats.matcha = 0;
    stats.gluten_free = 0;
    stats.popular_topping = NO_TOPPING;
    stats.small = 0;
    stats.medium = 0;
    stats.large = 0;
    int no_topping = 0, banana_topping = 0, 
    strawberry_topping = 0, nutella_topping = 0;
    // if list is empty then return
    if (count == NULL) {
        return stats;
    }
    // many if statements within the loop to count 
    // each occurence
    else {
        while (count != NULL) {
            stats.total_crepes++;
            if (count->batter == ORIGINAL) {
                stats.original++;
            }
            else if (count->batter == CHOCOLATE) {
                stats.chocolate++;
            }
            else {
                stats.matcha++;
            }

            if (count->is_gluten_free == 1) {
                stats.gluten_free++;
            }

            if (count->topping == NO_TOPPING) {
                no_topping++;
            }
            else if (count->topping == BANANA) {
                banana_topping++;
            }
            else if (count->topping == STRAWBERRY) {
                strawberry_topping++;
            }
            else {
                nutella_topping++;
            }

            if (count->diameter_cm < 20 && count->diameter_cm >= 10) {
                stats.small++;
            }
            else if (count->diameter_cm < 30 && count->diameter_cm >= 20) {
                stats.medium++;
            }
            else if (count->diameter_cm < 40 && count->diameter_cm >= 30) {
                stats.large++;
            }
            count = count->next;
        }
        // determine which is the most occuring topping
        if (banana_topping > no_topping 
        && banana_topping > strawberry_topping 
        && banana_topping > nutella_topping) {
            stats.popular_topping = BANANA;
        }
        else if (strawberry_topping > banana_topping 
        && strawberry_topping > no_topping 
        && strawberry_topping > nutella_topping) {
            stats.popular_topping = STRAWBERRY;
        }
        else if (nutella_topping > banana_topping 
        && nutella_topping > strawberry_topping 
        && nutella_topping > no_topping) {
            stats.popular_topping = NUTELLA;
        }
        else {
            stats.popular_topping = NO_TOPPING;
        }
    }
    return stats;
}

// calculates the price of a single crepe
double calculate_price(struct day *current_day, int position) {
    struct crepe *temp = current_day->orders;
    int i = 1;
    double price = 0;
    if (position < 0 || temp == NULL) {
        return INVALID_POSITION;
    }
    // goes to position of crepe
    while (i < position) {
        temp = temp->next;
        if (temp == NULL) {
            return INVALID_POSITION;
        }
        i++;
    }
    // if statements to add prices
    if (temp->batter == ORIGINAL) {
        price += 8;
    }
    else if (temp->batter == CHOCOLATE) {
        price += 8;
    }
    else {
        price += 9.5;
    }

    if (temp->is_gluten_free == 1) {
        price += 0.6;
    }

    if (temp->topping == BANANA) {
        price += 2;
    }
    else if (temp->topping == STRAWBERRY) {
        price += 2;
    }
    else if (temp->topping == NUTELLA) {
        price += 3.5;
    }

    if (temp->diameter_cm < 40 && temp->diameter_cm >= 30) {
        price += 3.5;
    }
    else if (temp->diameter_cm < 30 && temp->diameter_cm >= 20) {
        price += 2.5;
    }
    return price;
} 

// adds the prices of all the crepes in a list
double total_income(struct day *current_day) {
    struct crepe *temp = current_day->orders;
    int i = 1;
    double total = 0;
    if (temp == NULL) {
        return 0;
    }
    while (temp != NULL) {
        total += calculate_price(current_day, i);
        temp = temp->next;
        i++;
    }
    return total;
}

// adds the prices of all crepes with the same name
struct bill customer_bill(struct day *current_day, char *customer_name) {
    struct crepe *temp = current_day->orders;
    int i = 1;
    struct bill bill;
    bill.total_price = 0;
    bill.crepe_count = 0;
    while (temp != NULL) {
        if (strcmp(temp->customer_name, customer_name) == 0) {
            bill.total_price += calculate_price(current_day, i);
            bill.crepe_count += 1;
        }
        temp = temp->next;
        i++;
    }
    return bill;
}

// Your functions go here (include function comments):

// returns the length of a crepe list
int get_list_length(struct day *current_day) {
    struct crepe *temp = current_day->orders;
    int i = 0;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

// cheks that all the values of a crepe struct are valid
int insert_check_valid_crepe(int position, int length, enum batter_type batter,
                        enum topping_type topping,
                        int is_gluten_free,
                        int diameter_cm) {
    // different cases return specific errors 
    if (position < 0) {
        return INVALID_POSITION;
    }
    if (batter != ORIGINAL && batter != CHOCOLATE && batter != MATCHA) {
        return INVALID_BATTER;
    }
    else if (topping != NO_TOPPING && topping != BANANA 
    && topping != STRAWBERRY && topping != NUTELLA) {
        return INVALID_TOPPING;
    }
    else if (is_gluten_free != 0 && is_gluten_free != 1) {
        return INVALID_GFO;
    }
    else if (diameter_cm < 10 || diameter_cm >= 40) {
        return INVALID_SIZE;
    }
    else {
        return VALID_CREPE;
    }
}

// creates a signature crepe and returns it
struct crepe *create_signature_crepe(char *customer_name, char *crepe_type) {
    if (strcmp(crepe_type, "matcha") == 0) {
        struct crepe *new_crepe = create_crepe(customer_name, 
        MATCHA, STRAWBERRY, 0, 25, 'm');
        return new_crepe;
    }
    else if (strcmp(crepe_type, "strawberry") == 0) {
        struct crepe *new_crepe = create_crepe(customer_name, 
        ORIGINAL, STRAWBERRY, 1, 25, 's');
        return new_crepe;
    }
    else if (strcmp(crepe_type, "chocolate") == 0) {
        struct crepe *new_crepe = create_crepe(customer_name, 
        CHOCOLATE, NUTELLA, 0, 25, 'c');
        return new_crepe;
    }
    else {
        return NULL;
    }
    
}
//////////////////////////////////////////////////////////////////////
//                        Stage 3 Functions                         //
//////////////////////////////////////////////////////////////////////

// Provided function stubs:

// creates a new day
struct day *new_day(struct day *day_one, struct date date) {
    struct day *new_day = create_day(date);
    // checks whether the date already exists
    // if so, return null
    if (compare_dates(new_day->date, day_one->date) == 0) {
        return NULL;
    }
    // inserting date at the beginning
    if (compare_dates(new_day->date, day_one->date) == -1) {
        new_day->next = day_one;
        day_one = new_day;
        return day_one;
    }
    // inserting date in other position within list
    else {
        struct day *temp = day_one;
        while (temp->next != NULL) {
            // compare dates function to place in chronological order
            if (compare_dates(new_day->date, temp->next->date) == 0) {
                return NULL;
            }
            else if (compare_dates(new_day->date, temp->next->date) == -1) {
                new_day->next = temp->next;
                temp->next = new_day;
                return day_one;
            }
            temp = temp->next;
        }
        new_day->next = NULL;
        temp->next = new_day;

    }
    return day_one;
}

// print out the days with some other information
void display_days(struct day *day_one, struct day *current_day) {
    struct day *temp = day_one;
    int is_current_day = 0;
    double income;
    char most_pop;
    if (compare_dates(temp->date, current_day->date) == 0) {
        is_current_day = 1;
    }
    // functions to determine no. of sig crepes and
    // total income
    most_pop = count_signature_crepe(temp);
    income = total_income(temp);
    print_single_day(is_current_day, temp->date, most_pop, income);
    is_current_day = 0;
    temp = temp->next;
    // loops through all dates
    while (temp != NULL) {
        if (compare_dates(temp->date, current_day->date) == 0) {
            is_current_day = 1;
        }
        most_pop = count_signature_crepe(temp);
        income = total_income(temp);
        print_arrow();
        print_single_day(is_current_day, temp->date, most_pop, income);
        temp = temp->next;
        is_current_day = 0;
    }
}

// cycles through days - changes current_day
struct day *cycle_days(char command,
                       struct day *day_one,
                       struct day *current_day) {
    // going forward
    if (command == '>') {
        // goes back to beginning if at the end
        if (current_day->next == NULL) {
            current_day = day_one;
        }
        else {
            current_day = current_day->next;
        }
    }
    // going back
    else {
        if (current_day != day_one) {
            current_day = overdeep_cycle_days(command, day_one, current_day);
        }
        // goes to the end if at beginning
        else {
            struct day *temp = day_one;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            current_day = temp;
        }
    }
    return current_day;
}

// frees a specific crepe
int remove_crepe(struct day *current_day, int position) {
    struct crepe *temp = current_day->orders;
    int i = 1;
    // finds length
    int length = get_list_length(current_day);
    if (position <= 0 || position > length) {
        return INVALID_POSITION;
    }
    // case for if crepe is at beginning
    if (position == 1) {
        struct crepe *delete = temp;
        if (temp->next != NULL) {
            current_day->orders = temp->next;
        }
        else {
            current_day->orders = NULL;
        }
        free(delete);
        return VALID_CREPE;
    }
    // goes to where the crepe is
    while (i < position - 1) {
        temp = temp->next;
        i++;
    }
    // deletes the crepe
    struct crepe *delete = temp->next;
    if (temp->next->next != NULL) {
        temp->next = temp->next->next;
        free(delete);
    }
    else {
        temp->next = NULL;
        free(delete);
    }
    return VALID_CREPE;
}

// remove a specific day
struct day *remove_day(struct day *day_one,
                       struct day **current_day,
                       struct date date) {
    int no_days = count_days(day_one);
    struct day *temp = day_one;
    // if there is no other days, replaces it with enw day
    // with date 2024-01-01
    if (no_days == 1) {
        struct day *delete = temp;
        struct date start_date;
        start_date.year = 2024;
        start_date.month = 01;
        start_date.day = 01;
        struct day *start_day = create_day(start_date);
        day_one = start_day;
        *current_day = day_one;
        delete_all_crepes(delete);
        free(delete);
        return day_one;
    }
    // case for removing the first date
    if (compare_dates(temp->date, date) == 0) {
        struct day *delete = temp;
        temp = temp->next;
        day_one = temp;
        if (delete == *current_day) {
            // moves current day
            struct day *new_curr = *current_day;
            new_curr = new_curr->next;
            *current_day = new_curr;
        }
        // frees all crepes within the day
        delete_all_crepes(delete);
        free(delete);
        return day_one;
    }
    // delete other day within list
    while (temp->next != NULL) {
        if (compare_dates(temp->next->date, date) == 0) {
            struct day *delete = temp->next;
            if (delete == *current_day) {
                // moving current day if it is the same
                // as the day to be deleted
                struct day *new_curr = *current_day;
                new_curr = new_curr->next;
                *current_day = new_curr;
            }
            if (temp->next->next != NULL) {
                temp->next = temp->next->next;
                delete_all_crepes(delete);
                free(delete);
                return day_one;
            }
            else {
                temp->next = NULL;
                delete_all_crepes(delete);
                free(delete);
                return day_one;
            }
        }
        temp = temp->next;
    }
    return day_one;
}
    
// removes every day and crepe
void free_crepe_stand(struct day *day_one) {
    
    struct day *temp = day_one;
    while (temp != NULL) {
        struct day *delete_day = temp;
        temp = temp->next;
        delete_all_crepes(delete_day);
        free(delete_day);
    }
}

// Your functions here (include function comments):

// goes to the end of list of 
// days when cycling backwardds
struct day *overdeep_cycle_days(char command,
                       struct day *day_one,
                       struct day *current_day) {
    struct day *temp = day_one;
    int loop = 1;
    while (temp->next != NULL && loop == 1) {
        if (compare_dates(temp->next->date, current_day->date) == 0) {
            loop = 0;
        }
        else {
            temp = temp->next;
        }
    }
    return temp;
}

// compares dates
int compare_dates(struct date date1, struct date date2) {
    // returns int compare
    // compare = -1 means date1 < date2
    // compare = 0 means date1 = date2
    // compare = 1 means date1 > date2
    // compare = 2 means error
    int compare = 2;
    if (date1.year < date2.year) {
        compare = -1;
    }
    else if (date1.year == date2.year) {
        if (date1.month < date2.month) {
            compare = -1;
        }
        else if (date1.month == date2.month) {
            if (date1.day < date2.day) {
                compare = -1;
            }
            else if (date1.day == date2.day) {
                compare = 0;
            }
            else if (date1.day > date2.day) {
                compare = 1;
            }
        }
        else if (date1.month > date2.month) {
            compare = 1;
        }
    }
    else if (date1.year > date2.year) {
        compare = 1;
    }
    return compare;
}

// counts the number of signature crepes
char count_signature_crepe(struct day *day) {
    struct crepe *temp = day->orders;
    int chocolate = 0, strawberry = 0, matcha = 0;
    while (temp != NULL) {
        if (temp->signature_type == 'c') {
            chocolate++;
        }
        else if (temp->signature_type == 's') {
            strawberry++;
        }
        else if (temp->signature_type == 'm') {
            matcha++;
        }
        temp = temp->next;
    }
    // returns respective values for each case
    if (chocolate == 0 && strawberry == 0
    && matcha == 0) {
        return NO_SIG_SOLD;
    }
    else if (chocolate > strawberry
    && chocolate > matcha) {
        return SIG_CHOCOLATE;
    }
    else if (strawberry > chocolate
    && strawberry > matcha) {
        return SIG_STRAWBERRY;
    }
    else if (matcha > chocolate
    && matcha > strawberry) {
        return SIG_MATCHA;
    }
    else {
        return NO_SIG_MOST_POP;
    }
}

// counts no. of days
int count_days(struct day *day_one) {
    struct day *count = day_one;
    int i = 0;
    while (count != NULL) {
        count = count->next;
        i++;
    }
    return i;
}

// loops through and deletes all crepes in a day
void delete_all_crepes(struct day *day) {
    struct crepe *temp = day->orders;
    while (temp != NULL) {
        struct crepe *delete = temp;
        temp = temp->next;
        free(delete);
    }
}

//////////////////////////////////////////////////////////////////////
//                        Stage 4 Functions                         //
//////////////////////////////////////////////////////////////////////

// Provided function stubs:

// adds up profits from weekends and weekdays
struct profits compare_weekday_end(struct day *day_one) {
    struct day *temp = day_one;
    double weekday_profit = 0;
    double weekend_profit = 0;
    while (temp != NULL) {
        int day_of_week = week_day_end(temp->date);
        if (day_of_week >= 1 && day_of_week <= 5) {
            weekday_profit += total_income(temp) - 35;
        }
        else if {
            weekend_profit += total_income(temp) - 50;
        }
        temp = temp->next;
    }
    struct profits profit;
    profit.weekday = weekday_profit;
    profit.weekend = weekend_profit;
    return profit;
}

struct max_profit max_profit_period(struct day *day_one, int year) {
    // TODO: implement this function
    printf("Max Profit Period not yet implemented.\n");
    exit(1);
}

// Your functions here (include function comments):

// calculate whether it is wekend or weekday
int week_day_end(struct date date) {
    int final = 0;
    double calc1;
    double calc2;
    int calc3;
    int year = date.year;
    double century = year;
    int form_year = year % 100;
    int month = date.month;
    int day = date.day;
    while (century > 100) {
        century /= 10;
    }
    // uses gauss's algorithm to calc weekends & weekdays
    // different calc variables for double / int conversion
    calc1 = (month + 9) % 12 + 1;
    calc2 = 2.6 * (calc1) - 0.2;
    calc3 = floor(century / 4);
    final = day + floor(calc2) - 2 * century + form_year + floor(form_year / 4) + calc3;
    final = final % 7;
    return final;
}

//////////////////////////////////////////////////////////////////////
//                         Helper Functions                         //
//////////////////////////////////////////////////////////////////////

void print_single_crepe(struct crepe *crepe, int position) {
    printf("---------------------\n");
    printf("%d. %s's crepe\n", position, crepe->customer_name);

    if (crepe->batter == ORIGINAL) {
        printf("Original flavour\n");
    } else if (crepe->batter == MATCHA) {
        printf("Matcha flavour\n");
    } else {
        printf("Chocolate flavour\n");
    }

    printf("Toppings: ");
    if (crepe->topping == NO_TOPPING) {
        printf("none\n");
    } else if (crepe->topping == BANANA) {
        printf("bananas\n");
    } else if (crepe->topping == STRAWBERRY) {
        printf("strawberries\n");
    } else if (crepe->topping == NUTELLA) {
        printf("nutella\n");
    }

    printf("gluten free? ");
    if (crepe->is_gluten_free) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    printf("Size: %dcm\n", crepe->diameter_cm);
    printf("---------------------\n");
}

void print_arrow(void) {
    printf("\t|\n\tv\n");
}

void print_no_crepes(void) {
    printf("No crepes have been ordered yet!\n");
}

void print_single_day(int is_current_day,
                      struct date date,
                      char most_pop,
                      double income) {
    printf("---------------------\n");
    if (is_current_day) {
        printf("!CURRENT DAY!\n");
    }
    printf("Date: %04d-%02d-%02d\n", date.year, date.month, date.day);
    if (most_pop == SIG_STRAWBERRY) {
        printf("Most popular signature crepe: Strawberry Special\n");
    } else if (most_pop == SIG_MATCHA) {
        printf("Most popular signature crepe: Matcha Madness\n");
    } else if (most_pop == SIG_CHOCOLATE) {
        printf("Most popular signature crepe: Chocolate Connoisseur\n");
    } else if (most_pop == NO_SIG_SOLD) {
        printf("There were no signature crepes sold!\n");
    } else if (most_pop == NO_SIG_MOST_POP) {
        printf("No signature crepe was more popular than another!\n");
    } else {
        printf("ERROR: %c, unknown most popular character\n", most_pop);
    }
    printf("Total income: $%.2lf\n", income);
    printf("---------------------\n");
}
