/*
 Sort a random array of n integers (accept the value of n from user) in ascending 
       order by using quick sort algorithm.
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
int partition(int array[],int lb,int ub)
{
    int temp;
    int pivot=array[lb];
    int i=lb;
    int j=ub;

    while(i<j)
    {
        while(array[i]<=pivot && i<=ub-1)
        i++;
        while(array[j]>=pivot && j>=lb+1)
        j--;
        if(i<j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    temp=array[lb];
    array[lb]=array[j];
    array[j]=temp;
    return j;
}

void quicksort(int array[],int lb, int ub)
{
    int j;
    if(lb<ub)
    {
        j=partition(array,lb,ub);
        quicksort(array,lb,j-1);
        quicksort(array,j+1,ub);
    }
}

int main()
{
      int arr[100],limit;
      printf("\nENTER A LIMIT:");
      scanf("%d",&limit);
      accept(arr,limit);
      printf("\nBEFORE SORTING:");
      display(arr,limit);
      printf("\nAFTER SORTING:");
      quicksort(arr,0,limit-1);
      display(arr,limit);
}
