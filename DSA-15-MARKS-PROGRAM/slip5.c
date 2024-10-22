/*
Implement a queue library (dyqueue.h) of integers using a dynamic (linked list)  
implementation of the queue and implement init, enqueue,dequeue,isempty,peek 
operations.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
}*front,*rear,*newnode;

void init()
{
  front=rear=NULL;
}
int isempty()
{
   if(front==NULL)
     return 1;
   else
     return 0;
}

void peek()
{
    printf("\nREAR ELEMENT IS:%d",rear->data);
}
void insert(int num)
{
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->next=NULL;
   if(front==NULL)  //first time
   {
     front=rear=newnode;
   }
   else
   {
     rear->next=newnode;
     rear=newnode;
   }
   printf("\nINSERT SUCC");
}

void delq()
{
   int val;
   struct node *temp;
   if(isempty())
   {
      printf("QUEUE IS UNDERFLOW...");
   }
  temp=front;
  val=front->data;
  front=front->next;
  free(temp);
  printf("\n DELETED VALUE=%d",val);
}
void disp()
{
  struct node *temp;
  for(temp=front;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}

int main()
{
  int ch,num;
  init();
  do
  {
    printf("\n1:INSERT \n2:DELETE \n3:PEEK\n4:DISPLAY");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("ENTER NUMBER:");
                   scanf("%d",&num);
                  insert(num);
                  break;
        case 2: delq();
                break;
        case 3:peek();
                 break;
        case 4:disp();break;
        default:printf("\nINVALID CHOICE");
    }
  }while(ch<5);
}
