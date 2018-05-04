#include<stdio.h>

/*
	根据当前值就可以获得从0起到此值的想获得的数的累加值:
从 1 至 10，在它们的个位数中，任意的 x 都出现了 1 次
从 1 至 100，在它们的十位数中，任意的 x 都出现了 10 次
从1至1000，在它们的百位数中，任意的x都出现了100次
依次类推，从 1 至 10^i，在它们的左数第二位(右数第 i 位)，任意的 x 都出现了 (10^i-1)次

取第 i位左边(高位)的数字，乘以 10i-1，得到基础值 a

取第 i 位数字，计算修正值

如果大于 x , 则结果为 a + 10i-1

如果小于 x，则结果为 a

如果等于 x，则取第 i 位右边(低位)数字，设为 b，最后结果为 a + b + 1
*/

int count_num_one(int a)
{
	int res=0;
	int i=1;
	int remain=0;
	while(a/i)
	{
		i*=10;
		remain=(a%i)/(i/10);
		if(remain<1)
		{			
			res+=(a/i)*(i/10);
		}
		else if(remain==1)
		{
			res+=(a/i)*(i/10)+(a%i)%(i/10)+1;
		}
		else
		{
			res+=(a/i+1)*(i/10);
		}		
	}
	return res;
}

int main()
{
	
	int b=count_num_one(99)-count_num_one(31-1);
	printf("%d\n",b);
}
