#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *arr1,*arr2,*tmparr;
// int arr1[1000000],arr2[1000000],tmparr[1000000];

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
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
	ret=malloc(sizeof(int)*n);

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
	arr1 = (int *)malloc(n*sizeof(int));
	arr2 = (int *)malloc(n*sizeof(int));
	tmparr = (int *)malloc(n*sizeof(int));

	int C = 32000;

	int size = 0;
	
	for(int i=0;i<n;i+=C)
	{
		arr1[size] = i;
		if(i+C-1>=n)
		{
			arr2[size++] = n - i;
			mergeSort(arr,i,n - 1);
		}
		else
		{
			arr2[size++] = C;
			mergeSort(arr,i,i+C-1);
		}
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
			if(i==size-1)
			{
				arr2[k++] = arr2[i];
			}
			else
			{
				arr2[k++] = arr2[i] + arr2[i+1];
			}
		}
		size = k;
	}
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