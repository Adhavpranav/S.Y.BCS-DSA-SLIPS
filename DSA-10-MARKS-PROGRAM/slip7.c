/*
Implement a list library (singlylist.h) for a singly linked list of integer With the 
operations create, delete specific element and display. Write a menu driven program to 
call these operations. 
*/
#include<stdio.h>
#include<stdlib.h>
    struct node
    {
        int data;
        struct node * next; 
    };

    struct node *create(struct node *head)
    {
        struct node *newnode,*temp;
        int limit,i;
        printf("\nENTER LIMIT:");
        scanf("%d",&limit);
        for(i=0;i<limit;i++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("ENTER VALUE:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
                if(head==NULL)
                {
                    head=newnode;
                    temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
        }
        return head;
    }

    void display(struct node* head)
    {
        struct node *temp=head;
        printf("\nOUTPUT:");
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }

    struct node*delete(struct node*head)
    {
        struct node*temp,*temp1;
        int num;
        printf("\nENTER A NUMBER:");
        scanf("%d",&num);
        if(head->data==num)
        {
            temp=head;
            head=head->next;
            free(temp);
            return head;
        }
        for(temp=head;temp->next!=NULL;temp=temp->next)
        {
            if(temp->next->data==num)
            {
                temp1=temp->next;
                temp->next=temp1->next;
                free(temp1);
                break;
            }
        }
        return head;
    }

     int main()
{
    int choice;
    struct node*head=NULL;
    do
    {
        printf("\n1:CREATE \n2:DISPLAY\n3:DELETE\n4:EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=create(head);break;
            case 2:display(head);break;
            case 3:head=delete(head);break;
            default:printf("\nINVALID CHOICE");
        }
    }while(choice!=4);
}
