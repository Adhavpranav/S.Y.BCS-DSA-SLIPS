/*
Write a C program to check whether the contents of two stacks are identical. Use 
stack library to perform basic stack operations. Neither stack should be changed.
*/
#include<stdlib.h>
#include<stdio.h>
#define MAX 5
struct stack
{
    int a[MAX];
    int top;
}s1,s2;
void init(struct stack *s)
{
    s->top=-1;
}
int isfull(struct stack *s)
{
    if(s->top==MAX-1)
    return 1;
    else
    return 0;
}

int isempty(struct stack *s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

void push(struct stack *s,int num)
{
    if(isfull(s))
    {
        printf("\nSTACK IS OVERFLOW");
    }
    else
    {
        s->top++;
        s->a[s->top]=num;
        printf("\nINSERT SUCC");
    }
}

int identical(struct stack *s1,struct stack *s2)
{
    int i;
    if(s1->top!=s2->top)
    {
        return 0;
    }
    for(i=0;i<=s1->top;i++)
    {
        if(s1->a[i]!=s2->a[i])
        {
            return 0;
        }
    }
    return 1;
}
void disp(struct stack *s)
{
    int i;
    printf("\nSTACK IS:");
    for(i=s->top;i>=0;i--)
    {
        printf("\t%d",s->a[i]);
    }
}

int main()
{
    int num,choice;
    init(&s1);
    init(&s2);
    do
    {
        printf("\n1:PUSH STACK 1\n2:PUSH STACK 2\n3:DISPLAY STACK 1\n4:DISPLAY STACK 2 \n5:IDENTICAL");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nENTER A NUMBER TO PUSH:");
                   scanf("%d",&num);
                   push(&s1,num);
                   break;
             case 2:printf("\nENTER A NUMBER TO PUSH:");
                   scanf("%d",&num);
                   push(&s2,num);
                   break;
            case 3:disp(&s1);break;
            case 4:disp(&s2);break;
            case 5:if(identical(&s1,&s2))
                    printf("\nBOTH STACKS ARE IDENTICAL");
                    else
                    printf("\nBOTH STACKS ARE NOT IDENTICAL");
            default:printf("\nINVALID CHOICE");
                    break;
        }
    }while(choice>=1&&choice<=5);
}
