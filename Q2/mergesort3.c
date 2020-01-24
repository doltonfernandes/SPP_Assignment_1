#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
	int a,b;
};

struct node *arr1;

int *tmparr;

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

void mergeSort(int *arr, int l, int r) 
{ 
	if(l + 5 > r)
	{
		for(int i=l;i<=r;i++)
		{
			for(int j=i+1;j<=r;j++)
			{
				if(arr[i]>arr[j])
				{
					int t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}
		return ;
	}
    if (l < r) 
    {
        int m = l + ( ( r - l ) >> 1 );

        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r);
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
	int *ret;
	ret=(int *)malloc(sizeof(int)*n);

	/*
	Maximum value of n can be 10^6.
	Your Code goes here. The sorted array should be stored in ret
	and returned. Just code this function, no need to write anything in main().
	This function will be called directly.
	
	Also note you can write any other function that you might need.
	*/
// 
	struct timespec ts;
	printf("Running Program\n");
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double st=ts.tv_nsec/(1e9)+ts.tv_sec;
// 

	// Cache Size
	int C = 16000;

	// arr1 stores starting indices of blocks of size C and size
	arr1 = (struct node *)malloc(n*sizeof(struct node));
	// temporary array for merge()
	tmparr = (int *)malloc(n*sizeof(int));

	// size of arr1
	int size = 0;
	
	// Divide array into blocks of size <= C and sort them
	// Store index and size in arr1,arr2 respectively
	for(int i=0;i<n;i+=C)
	{
		arr1[size].a = i;
		arr1[size++].b = (i+C-1>=n? n - i:C);
		mergeSort(arr,i,(i+C-1>=n? n-1:i+C-1));
	}

	// Take 2 blocks at a time and merge untill only 1 block of size n is remaining which is the sorted array
	while(size>1)
	{
		for(int i=0;i<size-1;i+=2)
		{
			merge(arr,arr1[i].a,arr1[i].a+arr1[i].b-1,arr1[i+1].a+arr1[i+1].b-1);
		}
		int k = 0;
		for(int i=0;i<size-1;i+=2)
		{
			arr1[k].a = arr1[i].a;
			arr1[k++].b = arr1[i].b + arr1[i+1].b;
		}
		if(size%2)
		{
			arr1[k++] = arr1[size-1];
		}
		size = k;
	}
	
	// Copy array arr into ret to return
	for(int i=0;i<n;i++)
	{
		ret[i] = arr[i];
	}
// 
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double en=ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("Program ended\nTime = %Lf\n",en-st);
// 
	return ret;
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
	merge_sort(arr,n);
	// checktime(arr,n);
	// printArray(arr,n);
	return 0;
}