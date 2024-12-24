#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct Node {
    int data;
    struct Node *next;
} *newnode, *head, *temp;

void creation() {
    newnode = malloc(sizeof(struct Node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    count++;
}

void display() {
    if (head == NULL) {
        printf("the list is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("->%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL");

        printf("\nthe count is %d\n", count);
    }
}

void insertbeg() {
    creation();
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insertend() {
    creation();
    if (head == NULL) {
        insertbeg();
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertpos() {
    int pos;
    printf("enter the position: ");
    scanf("%d", &pos);
    if (pos > 0 && pos <= count + 1) {
        if (pos == 1) {
            insertbeg();
        } else if (pos == count + 1) {
            insertend();
        } else {
            creation();
            temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    } else {
        printf("\n invalid entry");
    }
}

int main() {
    int choice, ch = 1;

    while (ch) {
        printf("\n1.Beginning\n2.End\n3.At specific position\n4.Display\n5.Stop\nEnter the operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertbeg();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertpos();
                break;
            case 4:
                display();
                break;
            case 5:
                ch = 0;
                break;
            default:
                printf("invalid choice");
                break;
        }
    }

    return 0;
}
