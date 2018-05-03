#include<stdio.h>


#define ison(n,i) ((n)&(1<<i))

/*
	找出三个只重复一次的数，解决此问题的核心是先找到其中的一个，利用异或去重的思想
*/

int find_one_number(int *vec,int len)
{
	int tmp1=0,tmp2=0,count1=0,count2=0,i,j;
	
	for(i=0;i<32;i++)
	{
		tmp1=tmp2=count1=count2=0;
		for(j=0;j<len;j++)
		{
			if(ison(vec[j],i))
			{
				tmp1^=vec[j];
				count1++;
			}
			else
			{
				tmp2^=vec[j];
				count2++;
			}
		}
		if(count1 & 0x01)
		{
			if(0==tmp2)
				continue;
			else
				return tmp1;
		}
		else 
		{	
			if(0==tmp1)
				continue;
			else
				return tmp2;
		}

	}
}

void find_two_number(int *vec,int len,int *num1,int *num2)
{
	int i;
	for(i=0;i<len;i++)
	{
		
	}	
}

int isbit1(int xor)
{
	int index=0;
	while((xor&0x01)==0 && index<32)
	{
		xor>>=1;
		index++;
	}
	return index;
}

int main()
{
	int i,a=0,b=0,c=0;
	int vec[11]={1,2,3,1,3,4,6,8,8,5,5};
	int len=sizeof(vec)/sizeof(int);
	a=find_one_number(vec,sizeof(vec)/sizeof(int));

	int xor=0;
	xor^=a;
	for(i=0;i<len;i++)
		xor^=vec[i];
	int res=isbit1(xor);
	if(a>>res&0x01)
		b^=a;
	else
		c^=a;
	for(i=0;i<len;i++)
	{
		if(vec[i]>>res&0x01)
			b^=vec[i];
		else
			c^=vec[i];
	}
	
	printf("%d %d %d\n",a,b,c);	
}





