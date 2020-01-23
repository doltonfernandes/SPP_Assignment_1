#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Matrix
{
	int matrix[1000][1000];
}Matrix;

void mult_matr(Matrix *ans,Matrix *a,Matrix *b,int x,int y,int sizel,int sizer,int q)
{
	for(int i=x;i<x+sizel;i++)
	{
		for(int k=0;k<q;k++)
		{
			for(int j=y;j<y+sizer;j++)
			{
				ans->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
			}
		}
	}
}

Matrix *matrix_multiply(Matrix *a,Matrix *b,int p,int q,int r)
{
	Matrix *result;
	result=malloc(sizeof(Matrix));
	/*
	size of matrix a is pxq
	size of matrix b is qxr
	Maximum value of p,q or r can be 1000.
	Your Code goes here. The output of their matrix multiplication
	should be stored in result and returned. Just code this function,
	no need to write anything in main(). This function will be called directly.
	We are dealing with pointers so use result->matrix and not result.matrix

	Also note you can write any other function that you might need.
	*/

// 
	struct timespec ts;
	printf("Running Program\n");
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double st=ts.tv_nsec/(1e9)+ts.tv_sec;
// 
	int block = r;

	for(int i=0;i<p;i+=block)
	{
		for(int j=0;j<r;j+=block)
		{
			mult_matr(result,a,b,i,j,(i+block-1<p? block:p - i),(j+block-1<r? block:r - j),q);
		}
	}

// 
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double en=ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("Program ended\nTime = %Lf\n",en-st);
// 
	return result;
}

Matrix *mat1,*mat2,*ans;

int main()
{
	int p,q,r;
	scanf("%d %d %d",&p,&q,&r);
	mat1 = (Matrix *)malloc(sizeof(Matrix));
	mat2 = (Matrix *)malloc(sizeof(Matrix));
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			scanf("%d",&mat1->matrix[i][j]);
		}
	}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d",&mat2->matrix[i][j]);
		}
	}
	ans = matrix_multiply(mat1,mat2,p,q,r);
	// for(int i=0;i<p;i++)
	// {
	// 	for(int j=0;j<r;j++)
	// 	{
	// 		printf("%d ",ans->matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}