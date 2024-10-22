/*Q.2)Write a C program to evaluate postfix expression.*/

#include<stdio.h>
#define MAX 10
struct stack
{
    int a[MAX];
    int  top;
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

void push(int num)
{
    if(isfull(s))
    {
        printf("\nStack is full...");
    }
    else
    {
        s.top++;
        s.a[s.top]=num;
    }
}

int pop()
{
    if(isempty())
      printf("\nStack is empty......");

    else
    {
        int x=s.a[s.top];
        s.top--;
        return x;
    }  
}
int peek()
{
    return s.a[s.top];
}
void display()
{
    while(!isempty())
    {
        printf("%d ",pop());
    }
}

int main()
{
    init();
    char postfix[100],val;
    int a,b,c,d,i;
    int val1,val2,result;
    printf("\nENTER POSTFIX EXP:");
    gets(postfix);
    printf("\nENTER VALUE OF A,B,C,D:");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(i=0;postfix[i]!='\0';i++)
    {
        val=postfix[i];
        if(val=='A')
        push(a);
        else if(val=='B')
        push(b);
        else if(val=='C')
        push(c); 
        else if(val=='D')
        push(d);
        else
        {
            val1=pop();
            val2=pop();
            switch(val)
            {
                case '+':result=val2+val1;
                        push(result);break;
                case '-':result=val2-val1;
                        push(result);
                         break;
                case '*':result=val2*val1;
                        push(result);
                        break;
                case '/':result=val2/val1;
                        push(result);
                        break;
            }
        }
    }
    printf("\nRESULT:%d",pop());
}
