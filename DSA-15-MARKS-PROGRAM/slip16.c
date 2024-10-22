/*
There are lists where insertion should ensure the ordering of data elements.Since the 
elements are in ascending order the search can terminate once equal or greater element is 
found .Implement a doubly linked list of ordered integers (ascending/descending) with 
insert, search,and display operations.   
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next,*prev;
};
struct node*create(struct node*head)
{
    int i,limit;
    struct node*newnode,*temp;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE IN ORDER:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
            head->prev=NULL;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node*head)
{
    struct node*temp;
    printf("\nLINKED LIST IS:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}

void search(struct node*head)
{
    struct node*temp;
    int num;
    printf("\nENTER A NUM TO SEARCH:");
    scanf("%d",&num);
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        if(temp->data==num)
        {
            printf("\nNUMBER IS FOUND");
            return;
        }
        else
        {
            if(temp->data>num)
            break;
        }
    }
    printf("\nNUMBER IS NOT FOUND");
    return;
}

struct node*insert(struct node*head)
{
    struct node*newnode,*temp,*temp1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nENTER A VALUE:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    if(head==NULL|| head->data>=newnode->data)
    {
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    }
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        if(temp->next->data>=newnode->data)
        break;
    }
    if(temp->next==NULL)
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        return head;
    }
    else
    {
            temp1=temp->next;
            newnode->next=temp1;
            temp1->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            return head;
    }
}

int main()
{
    int choice;
    struct node*head=NULL;
    do{
        printf("\n1:CREATE\n2:DISPALY\n3:INSERT\n4:SEARCH:");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=create(head);break;
            case 2:display(head);break;
            case 3:head=insert(head);break;
            case 4:search(head);break;
            default:printf("\nINVALID CHOICE");
        }
    }while(choice>=1&&choice<=4);
}
