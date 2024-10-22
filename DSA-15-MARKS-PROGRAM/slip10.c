/*
)Write a program that copies the content of one stack into another.Use stack library to 
perform basic stack operations. The order of two stacks must be identical.(Hint:Use a 
temporary stack to preserve the order).
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int a[MAX];
    int top;
}s,s1,s2;
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
int isimpty(struct stack *s)
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
    }
}

int pop(struct stack *s)
{
    int val;
    if(isimpty(s))
    {
        printf("\nSTACK IS UNDERFLOW");
        return -1;
    }
    else
    {
        val=s->a[s->top];
        s->top--;
        return val;
    }
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
    init(&s);
    init(&s1);
    init(&s2);
    do
    {
        printf("\n1:PUSH \n2:POP \n3:DISPLAY\n4:COPY");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nENTER A NUMBER TO PUSH:");
                   scanf("%d",&num);
                   push(&s,num);
                   break;
            case 2:num=pop(&s);
                    if(num!=-1)
                    printf("\nPOPED VALUE IS:%d",num);
                    break;
            case 3:disp(&s);break;
            case 4:while(!isimpty(&s))
                    {
                        num=pop(&s);
                        push(&s1,num);
                    }
                    while(!isimpty(&s1))
                    {
                        num=pop(&s1);
                        push(&s,num);
                        push(&s2,num);
                    }
                    disp(&s2);
                    break;
            default:printf("\nINVALID CHOICE");
                    break;
        }
    }while(choice>=1&&choice<=4);
}
