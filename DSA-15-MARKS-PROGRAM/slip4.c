/*
 Write a program to reverse the elements of a queue using queue library. 
Implement basic queue operations init,enqueue,dequeue,isempty,peek
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
    int a[MAX];
    int front,rear;
}*q;

int isfull()
{
    if(q->rear==MAX-1)
    return 1;
    else
    return 0;
}

int isempty()
{
    if(q->front==-1)
    return 1;
    else
    return 0;
}


void initq()
{
    q = (struct queue*) malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
}

void insert(int num)
{
     if(isfull())
    {
        printf("\nQUEUE IS OVERFLOW");
    }
    else
    {
        if(q->front==-1)
        {
            q->front=0;
        }
        q->rear=q->rear+1;
        q->a[q->rear]=num;
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
        val=q->a[q->front];
        q->front++;
        printf("\nDELETED VALUE %d",val);
    }
}

void peek()
{
    printf("\nREAR VALUE:",q->a[q->front]);
}

void display()
{
    int i;
    printf("\nELEMENTS OF QUEUE:");
    for(i=q->front;i<=q->rear;i++)
    {
        printf("\t%d",q->a[i]);
    }
}

void reverse()
{
    int start,end,temp;
    start=q->front;
    end=q->rear;
    while(start<end)
    {
        temp=q->a[start];
        q->a[start]=q->a[end];
        q->a[end]=temp;
        start++;
        end--;
    }
}


int main()
{
  int ch,num;
  initq();
  do
  {
    printf("\n1:INSERT \n2:DELETE \n3:PEEK\n4:DISPLAY\n5:REVERSE");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("ENTER NUMBER:");
                   scanf("%d",&num);
                  insert(num);
                  break;
        case 2: delete();
                break;
        case 3:peek();
                 break;
        case 4:display();break;
        case 5:reverse();break;
        default:printf("\nINVALID CHOICE");
    }
  }while(ch<6);
}
