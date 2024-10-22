/*
Write a program that merges two ordered linked lists into third new list. When two 
lists are merged the data in the resulting list are also ordered. The two original lists should 
be left unchanged. That is merged list should be new one.Use linked implementation
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(struct node* head) {
    struct node* newnode, *temp;
    int limit, i;
    printf("\nENTER A LIMIT: ");
    scanf("%d", &limit);
    for (i = 0; i < limit; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            temp = head = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node* head) {
    struct node* temp;
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

struct node* marge(struct node* head, struct node* head1, struct node* head2) {
    struct node* temp = NULL;
    struct node* newnode = NULL;
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (temp1->data <= temp2->data) {
            newnode->data = temp1->data;
            temp1 = temp1->next;
        } else {
            newnode->data = temp2->data;
            temp2 = temp2->next;
        }
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
    }

    while (temp1 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = temp1->data;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = temp2->data;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
        temp2 = temp2->next;
    }
    
    return head;
}

int main() {
    struct node* head = NULL, * head1 = NULL, * head2 = NULL;
    printf("\nENTER ELEMENTS OF FIRST LIST:");
    head1 = create(head1);
    printf("\nELEMENTS OF FIRST LIST:");
    display(head1);
    printf("\nENTER ELEMENTS OF SECOND LIST:");
    head2 = create(head2);
    printf("\nELEMENTS OF SECOND LIST:");
    display(head2);
    head = marge(head, head1, head2);
    printf("\nMERGE LIST:");
    display(head);
}
