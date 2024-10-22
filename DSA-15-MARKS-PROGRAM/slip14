/*
Implement a linear queue library (st_queue.h) of integers using a static 
implementation of the queue and implementing the operations like init (Q),AddQueue(Q,x) 
and X=Delete Queue(Q).Write a program that includes queue library and calls different 
queue operations.   
*/

#include<stdio.h>
#define MAX 5
struct queue
{
    int a[MAX];
    int front,rear;
}q;

int isfull()
{
    if(q.rear==MAX-1)
    return 1;
    else
    return 0;
}

int isempty()
{
    if(q.front==-1)
    return 1;
    else
    return 0;
}

void initq()
{
    q.front=-1;
    q.rear=-1;
}

void insert(int num)
{
     if(isfull())
    {
        printf("\nQUEUE IS OVERFLOW");
    }
    else
    {
        if(q.front==-1)
        {
            q.front=0;
        }
        q.rear++;
        q.a[q.rear]=num;
        printf("\nINSERT SUCCESSFULLY");
    }
}


void delete()
{
    int val;
    if(isempty())
    {
        printf("\nQUEUE IS UNDERFLOW");
    }
    else
    {
        val=q.a[q.front];
        q.front++;
        printf("\nDELETED VALUE %d",val);
    }
}

void peek()
{
    printf("\nREAR VALUE:%d",q.a[q.front]);
}

void display()
{
    int i;
    printf("\nELEMENTS OF QUEUE:");
    for(i=q.front;i<=q.rear;i++)
    {
        printf("\t%d",q.a[i]);
    }
}

int main()
{
    initq();
    int choice,num;
    do
    {
        printf("\n1:INSERT\n2:DELETE\n3:PEEK\n4:DISPLAY");
        printf("\nENTER YOUR CHOICE");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nENTER A NUMBER:");
                    scanf("%d",&num);
                    insert(num);
                    break;
            case 2:delete();break;
            case 3:peek();break;
            case 4:display();break;
            default:printf("\nINVALID CHOICE");
        }
    }while(choice>=1&&choice<=4);
}
