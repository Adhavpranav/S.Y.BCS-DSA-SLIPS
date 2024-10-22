/*
Write a c program that search a number in  integers array using binary search 
algorithm. 
*/
#include<stdio.h>
void accept(int array[],int limit)
{
    int i;
    printf("\nENTER ARRAY ELEMENTS:");
    for(i=0;i<limit;i++)
    {
        scanf("%d",&array[i]);
    }
}
int binary_search(int array[],int limit,int key)
{
    int top,mid,bottom;
    top=0;
    bottom=limit-1;
    while(top<=bottom)
    {
    mid=(top+bottom)/2;
    if(array[mid]==key)
    return mid;
    else if(array[mid]<key)
    top=mid+1;
    else
    bottom=mid-1;
    }
    return -1;
}

int main()
{
    int num,array[100],limit,result;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    printf("\nENTER A NUMBER:");
    scanf("%d",&num);
    result=binary_search(array,limit,num);
    if(result==-1)
    {
        printf("\nNUMBER IS NOT FOUNT");
    }
    else
    {
        printf("\nNUMBER IS FOUND AT %d POSITION",result);
    }
}
