/*
Accept number from user and search inarray using linear serach algorithm.        
*/
#include<stdio.h>
void accept(int array[],int limit)
{
    int i;
    printf("\nENTER ELEMENTS OF AN ARRAY:");
    for(i=0;i<limit;i++)
    {
        scanf("%d",&array[i]);
    }
}

int linear_search(int array[],int limit)
{
    int num,i;
    printf("\nENTER A NUMBER TO SEARCH:");
    scanf("%d",&num);
    for(i=0;i<limit;i++)
    {
        if(array[i]==num)
        return i;
    }
    return -1;
}

int main()
{
    int array[100],limit,result;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    result=linear_search(array,limit);
    if(result==-1)
    {
        printf("\nNUMBER IS NOT FOUND");
    }
    else
    {
        printf("\nNUMBER IS FOUND AT %d POSITION",result);
    }
    return 0;
}
