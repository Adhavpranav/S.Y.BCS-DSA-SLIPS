/*
Sort a random array of n integers (accept the value of n from user) in ascending 
       order by using count sort algorithm. 
*/
#include<stdio.h>
#include<stdlib.h>
void accept(int array[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
        array[i]=rand()%10;
    }
}
void display(int array[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
        printf("\t%d",array[i]);
    }
}

void count_sort(int array[],int limit,int max)
{
    int count[20]={0},b[20],i,j;
    for(i=0;i<limit;i++)
    {
        count[array[i]]++;
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=limit-1;i>=0;i--)
    {
        b[--count[array[i]]]=array[i];
    }
    for(i=0;i<limit;i++)
    {
        array[i]=b[i];
    }
}

int main()
{
    int array[100],limit,i,max;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    printf("\nARRAY BEFORE SORTING:");
    display(array,limit);
    max=array[0];
    for(i=1;i<limit;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    count_sort(array,limit,max);
    printf("\nARRAY AFTER SORTING:");
    display(array,limit);
    return 0;
}
