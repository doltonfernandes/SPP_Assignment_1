#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *arr1,*arr2,*tmparr,size=0;
// int arr1[1000000],arr2[1000000],tmparr[1000000],size=0;

void merge(int arr[], int l, int m, int r) 
{
	if(arr[m]<=arr[m+1])
	{
		return ;
	}

    int i = l, j = m + 1, k = 0;

    while(i<=m && j<=r)
    {
    	if(arr[i] <= arr[j])
    	{
    		tmparr[k++] = arr[i++];
    	}
    	else
    	{
    		tmparr[k++] = arr[j++];
    	}
    }

    while(i<=m)
    {
    	tmparr[k++] = arr[i++];
    }

    while(j<=r)
    {
    	tmparr[k++] = arr[j++];
    }

    k = 0;
    for(i=l;i<=r;i++)
    {
    	arr[i] = tmparr[k++];
    }
}

void printArray(int A[], int size) 
{ 
    for (int i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
}

int* merge_sort(int *arr, int n)
{
	/*
	Maximum value of n can be 10^6.
	Your Code goes here. The sorted array should be stored in ret
	and returned. Just code this function, no need to write anything in main().
	This function will be called directly.
	
	Also note you can write any other function that you might need.
	*/

	for(int i=0;i<n;i+=1)
	{
		arr1[size] = i;
		arr2[size++] = 1;
	}

	while(size>1)
	{
		for(int i=0;i<size-1;i+=2)
		{
			merge(arr,arr1[i],arr1[i]+arr2[i]-1,arr1[i+1]+arr2[i+1]-1);
		}
		int k = 0;
		for(int i=0;i<size;i+=2)
		{
			arr1[k] = arr1[i];
			arr2[k++] = arr2[i];
		}
		size = k;
	}

	return arr;
}

void checktime(int *arr,int n)
{
	struct timespec ts;
	printf("Running Program\n");
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double st=ts.tv_nsec/(1e9)+ts.tv_sec;
	// Call Funcn Here
	merge_sort(arr,n);
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double en=ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("Program ended\nTime = %Lf\n",en-st);
}

int arr[1000000];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	checktime(arr,n);
	// printArray(arr,n);
	return 0;
}