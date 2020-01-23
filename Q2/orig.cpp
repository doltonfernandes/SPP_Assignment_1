#include <bits/stdc++.h>
using namespace std;

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
	struct timespec ts;
	printf("Running Program\n");
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double st=ts.tv_nsec/(1e9)+ts.tv_sec;
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		ret[i] = arr[i];
	}
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double en=ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("Program ended\nTime = %Lf\n",en-st);
	
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
	return 0;
}