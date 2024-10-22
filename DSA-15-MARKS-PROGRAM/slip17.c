/*
 There are lists where new elements are always appended at the end of the list. The list 
can be implemented as a circular list with the external pointer pointing to the last element 
of the list. Implement singly linked circular list of integers with append and display 
operations. The operation append(L, n),appends to the end of the list, n integers accepted 
from user.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node*create(struct node*head)
{
    struct node*temp,*newnode;
    int i,limit;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENETR VALUE:");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;
            newnode->next=head;
        }
        else
        {
            temp->next=newnode;
            newnode->next=head;
            temp=newnode;
        }
    }
    return head;
}

struct node*append(struct node*head,int num)
{
    struct node*temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    for(temp=head;temp->next!=head;temp=temp->next);
    newnode->data=num;
    temp->next=newnode;
    newnode->next=head;
    temp=newnode;
    return head;
}

void display(struct node*head)
{
    struct node*temp=head;
    printf("\nLINKED LIST IS:");
    do
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }while(temp!=head);
} 

int main()
{
    int choice,num;
    struct node*head=NULL;
    do
    {
        printf("\n1:CREATE\n2:DISPLAY\n3:APPEND");
        printf("\nENTER A CHOICE:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:head=create(head);
            break;
        case 2:display(head);break;
        case 3:printf("\nENTER A VALUE:");
                scanf("%d",&num);
               head=append(head,num);
               break;
        default:printf("\nINVALID CHOICE");
            break;
        }
    }while(choice>=1&&choice<=3);
}
