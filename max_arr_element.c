#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int largest(int arr[], int n)
{
	int i;
	int max = arr[0]; //initialize maximum element
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}

int main()
{
	int *arr,n,i;
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max = largest(arr,n);
	printf("%d",max);
	return 0;
}
