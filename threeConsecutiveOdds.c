#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
bool threeConsecutiveOdds(int *, int);
int main()
{
	int *a,x,i;
	bool b;
	printf("Enter the size of the array: ");
	scanf("%d",&x);
	a=(int *)malloc(x*sizeof(int));
	printf("Enter the elements:\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&a[i]);
	}
	b=threeConsecutiveOdds(a,x);
	if(b)
        printf("The array have 3 consecutive odd terms\n");
    else
    	printf("The array doesn't have 3 consecutive odd terms\n");
    return 0;
}
bool threeConsecutiveOdds(int* arr, int arrSize)
{
    int i,count=0;
    for (i = 0; i < arrSize; i++)
	{
        if (arr[i] % 2 != 0)
		{
            count++;
            if (count == 3)
            {
                return true;
            }
        } 
        else
            count = 0;
    }
    return false;
}