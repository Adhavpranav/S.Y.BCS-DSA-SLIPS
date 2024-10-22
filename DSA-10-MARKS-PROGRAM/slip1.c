/*
Implement a list library (doublylist.h) for a doubly linked list of integers                               
with the create, display operations. Write a menu driven program to  call these                             
operations.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next,*prev;
};
struct node*create(struct node*head)
{
    struct node*newnode,*temp;
    int limit,i;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
            head->prev=NULL;
        }
        else
        {
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node*head)
{
    struct node*temp;
    printf("\nDOUBLY LINKED LIST:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}
int main()
{
    int choice;
    struct node*head=NULL;
    do
    {
        printf("\n1:CREATE \n2:DISPLAY");
        printf("\nENTER A CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=create(head);break;
            case 2:display(head);break;
            default:printf("\nINVALID CHOICE:");break;
        }
    }while(choice>=1&&choice<=2);
    free(head);
}
