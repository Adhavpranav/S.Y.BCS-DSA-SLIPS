/*
 Sort a random array of n integers (accept the value of n from user)  in 
ascending order by using insertion sort algorithm.
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

void insertionsort(int arr[],int limit)
{
    int i,j,temp;
    for(i=1;i<limit;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
}

int main()
{
    int limit,arr[100];
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    accept(arr,limit);
    printf("\nBEFORE SORTING:");
    display(arr,limit);;
    insertionsort(arr,limit);
    printf("\nAFTER SORTING:");
    display(arr,limit);
    return 0;
}
