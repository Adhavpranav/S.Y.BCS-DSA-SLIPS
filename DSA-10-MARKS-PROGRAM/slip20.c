/*
Sort a random array of n integers (accept the value of n from user) in ascending order 
by using bubble sort algorithm.
*/
#include<stdio.h>
#include<stdlib.h>
void accept(int array[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
      array[i]=rand()%100;
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
void bubble_sort(int array[],int limit)
{
    int pass,i,temp;
    for(pass=0;pass<limit-1;pass++)
    {
        for(i=0;i<limit-pass-1;i++)
        {
            if(array[i]>array[i+1])
            {
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
}

int main()
{
    int array[100],limit;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    printf("\nARRAY BEFORE SORTING:");
    display(array,limit);
    bubble_sort(array,limit);
    printf("\nARRAY AFTER SORTING:");
    display(array,limit);
    return 0;
}
