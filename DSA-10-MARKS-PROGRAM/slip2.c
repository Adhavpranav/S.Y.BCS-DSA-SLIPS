/*
Implement a list library (singlylist.h) for a singly linked list of integer 
with the operations create, display. Write a menu driven program to call 
these operations 
*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node*next;
};
struct node*create(struct node*head)
{
    struct node*newnode,*temp;
    int i,limit;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER A VALUE:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;;
        }
    }
    return head;
}

void display(struct node*head)
{
    struct node*temp;
    printf("\nSINGLY LINKED LIST:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}int main()
{
    int choice;
    struct node*head=NULL;
    do
    {
        printf("\n1:CREATE \n2:DISPLAY\n3:EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=create(head);break;
            case 2:display(head);break;
            default:printf("\nINVALID CHOICE");
        }
    }while(choice!=3);
}
