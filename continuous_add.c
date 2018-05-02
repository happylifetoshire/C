#include<stdio.h>


int main()
{
	int i,j,k;
	int num,sum;
	while(scanf("%d",&num)!=EOF)
	{
		if(num==-1)
			break;
		for(i=1;i<num;i++)
		{
			sum=i;
			for(j=i+1;j<num;j++)
			{
				sum+=j;
				if(sum==num)
				{
					for(k=i;k<=j;k++)
					{
						printf("%d ",k);
					}
					printf("\n");
					printf("#\n");
				}	
			}
		}	
	}
	
	return 0;
}
