/*
 Sort a random array of n integers (accept the value of n from user) in ascending order 
by using selection sort algorithm. 
*/

#include<stdio.h>
#include<stdlib.h>
void accept(int arr[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
	{
		arr[i]=rand()%100;
	}	
}
void display(int arr[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
        printf("\t%d",arr[i]);
    }
}

void selectionsort(int arr[],int limit)
{
    int index,min,i,j;
    for(i=0;i<limit-1;i++)
    {
        min=arr[i];
        index=i;
       for(j=i+1;j<limit;j++)
       {
        if(arr[j]<min)
        {
            min=arr[j];
            index=j;
        }
       }
       arr[index]=arr[i];
       arr[i]=min;
    }
}

int main()
{
    int limit,arr[100];
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    accept(arr,limit);
    printf("\nBEFORE SORTING:");
    display(arr,limit);
    selectionsort(arr,limit);
    printf("\nAFTER SORTING:");
    display(arr,limit);
    return 0;
}
