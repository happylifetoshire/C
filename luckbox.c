#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


/*
	  骰子求和的问题，利用递归方法，从1开始，把每一个骰子的值上所有可能的值加一次，获得一次相同的值
	在其相应的位置上加一。最后将各值除以总次数6的num次方。
*/


void probability(int st,int cur,int sum,int *v)
{
	int i;
	if(cur==1)
	{
		v[sum-st]++;
	}
	else
	{
		for(i=1;i<=6;i++)
			probability(st,cur-1,i+sum,v);
	}
		
}
void start(int n,int *v)
{
	int i;
	for(i=1;i<=6;i++)
	{
		probability(n,n,i,v);		
	}
}

int main()
{
	int num,i,j;
	double ratio;
	scanf("%d",&num);
	
	
	int *p = (int*)malloc(sizeof(int)*(5*num+1));
	memset(p,0,5*num+1);
	fflush(stdin);
	if(num==0)
	{
		printf("please input a number,idiots!\n");
	}

	start(num,p);
	
	double total = pow((double)6,num);
	for(i=0;i<5*num+1;i++)
	{
		ratio=(double)p[i]/total;
		printf("%d : %e\n",i+num,ratio);
	}
	return 0;
}
