/*
Implement a stack library (ststack.h)of integers using a static implementation of the 
stack and implementing the operations like init(S),S=Push(S,x )and isEmpty(S).Write a 
driver program that includes stack library and calls different stack operations. 
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int a[MAX];
    int top;
}s;

void init()
{
    s.top=-1;
}

int isfull()
{
    if(s.top==MAX-1)
    return 1;
    else
    return 0;
}

int isempty()
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}

int pop()
{
    if(isempty())
    {
        printf("\nSTACK IS UNDERFLOW");
    }
    else
    {
        int val;
        val=s.a[s.top];
        s.top--;
        return val;
    }
}

void push(int num)
{
    if(isfull())
    {
        printf("\nSTACK IS OVERFLOW");
    }
    else
    {
        s.top++;
        s.a[s.top]=num;
        printf("\nINSERT SUCC");
    }
}

void display()
{
    int i;
    printf("\nSTACK ELEMENTS:");
    for(i=s.top;i>=0;i--)
    {
        printf("\t%d",s.a[i]);
    }
}

void peek()
{
    printf("\nTOP ELEMENT OF STACK:%d",s.a[s.top]);
}

int main()
{
    init();
    int choice,num;
    do
    {
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:DISPLAY");
        printf("\nENTER A CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nENTER A NUMBER:");
                    scanf("%d",&num);
                    push(num);
                    break;
            case 2:printf("\nDELETED VALUE IS:%d",pop());
                    break;
            case 3:peek();break;
            case 4:display();break;
            default:printf("\nINVALID CHOICE");
        }
    }while(choice>=0&&choice<=4);
}
