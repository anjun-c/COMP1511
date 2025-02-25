#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

int main(void) {
    int loop_run = 1, number = 0, i = 0;
    struct node *head = malloc(sizeof(struct node));
    scanf(" %d", &number);
    head->next = NULL;
    head->data = number;
    struct node *prev = head;
    while (loop_run != 0) {
        scanf(" %d", &number);
        if (number != 0) {
            struct node *curr = malloc(sizeof(struct node));
            prev->next = curr;
            curr->data = number;
            curr->next = NULL;
            prev = prev->next;
        }
        else {
            loop_run = 0;
        }
    }
    struct node *temp = head;
    while (temp != NULL) {
        if (i % 2 == 0) {
        printf("%d ", temp->data);
        }
        temp = temp->next;
        i++;
    }
    temp = head;
    i = 0;
    while (temp != NULL) {
        if (i % 2 == 1) {
            printf("%d ", temp->data);

        }
        temp = temp->next;
        i++;
    }
    printf("\n");
} 