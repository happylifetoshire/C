#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	二维矩阵在传递、计算的时候转化为一维矩阵，在c语言内是这样，除非起始的时候申请的是二维矩阵，否则转化为[][]这种形式会报错.
*/

void matrix_show(int *a,int r,int c)
{	
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf(" %d",*((a+i*c)+j));
		}
		printf("\n");
	}
	
}
void matrix_set(int *a,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			*(a+i*c+j)=0;
		}
	}
}

int **matrix_mult(int *a,int *b,int r1,int c1,int r2,int c2)
{
	int i,j,k;
	if(c1!=r2)
		return NULL;
	int **c=(int**)malloc(sizeof(int*)*c2);
	for(i=0;i<c2;i++)
	{
		*(c+i)=(int*)malloc(sizeof(int)*r1);
	}
	//int *c=(int *)malloc(sizeof(int)*r1*c2);
	matrix_set((int *)c,r1,c2);
	//matrix_show((int *)c,r1,c2);
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			for(k=0;k<c1;k++)
			{
				*((int *)c+i*c2+j)+=(*(a+i*c1+k))*(*(b+k*c2+j));
			
			}
		}
	}
	//matrix_show((int *)c,r1,r2);
	return (int **)c;
	 
}


int main()
{
	int a[2][3]={
				 {1,2,3},
				 {4,5,6}
				};
	matrix_show((int *)a,2,3);
	int b[3][1]={
				  {3},{2},{1}
				};
	//matrix_show((int *)b,3,1);
	int **cl=matrix_mult((int *)a,(int *)b,2,3,3,1);	
	matrix_show((int *)cl,2,1);
}





