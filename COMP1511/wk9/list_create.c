// Create a list from Command Line Arguments
// list_create.c
//
// This program was written by adrian chen (z5592060)
// in april 2024
//
// A program which creates and prints a linked list 
// from command line arguments!

#include <stdio.h>
#include <stdlib.h>

struct node {
    char *data;
    struct node *next;
};

struct node *arguments_to_list(int argc, char *argv[]);
void free_list(struct node *head);
void print_list(struct node *head);

int main(int argc, char **argv) {
    struct node *head = arguments_to_list(argc, argv);
    print_list(head);
    free_list(head);

    return 0;
}

// Create linked list from argument values
struct node *arguments_to_list(int argc, char *argv[]) {
    // TODO: Complete this function and change the line below
    int i = argc - 1;
    struct node *head = NULL;
    while (i > 0) {
        struct node *n = malloc(sizeof(struct node));
        n->next = head;
        n->data = argv[i];
        head = n;
        i -= 1;
    }
    return head;
}

// Free the linked list from memory
void free_list(struct node *head) {
    // TODO: Complete this 
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Print the values of the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("X\n");
}