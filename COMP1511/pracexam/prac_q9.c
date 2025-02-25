#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define ALPHBT 26
#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *next;
};

int check_same(char check1, char check2, struct node *head);
void debug(struct node *head);

int main(void) {
    char str1[MAX_CHAR],
    str2[MAX_CHAR],
    check1, check2;
    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    fgets(str1, MAX_CHAR, stdin);
    fgets(str2, MAX_CHAR, stdin);
    int len1 = strlen(str1),
    len2 = strlen(str2),
    i = 0, j = 0, count = 0;
    while (i < len1 - 1) {
        check1 = str1[i];
        while (j < len2 - 1) {
            check2 = str2[j];
            if (check_same(check1, check2, head) == TRUE) {
                count++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    //debug(head);
    //printf("\n");
    printf("%d\n", count);
}

void debug(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int check_same(char check1, char check2, struct node *head) {
    int no1, no2;
    if (check1 == ' ' || check2 == ' ') {
        return FALSE;
    }
    if (check1 >= 'a') {
        no1 = check1 - 96;
    }
    else {
        no1 = check1 - 64;
    }
    if (check2 >= 'a') {
        no2 = check2 - 96;
    }
    else {
        no2 = check2 - 64;
    }

    if (no1 == no2) {
        struct node *temp = head;
        while (temp != NULL) {
            if (temp->data == no1) {
                return FALSE;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        struct node *new = malloc(sizeof(struct node));
        new->data = no1;
        new->next = NULL;
        temp->next = new;
        return TRUE;
    }
    else {
        return FALSE;
    }
}