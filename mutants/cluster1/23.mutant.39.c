#include<stdio.h>
int digitSum(int n)
{
	int sum=0;
	while(n!=0)
	{
		sum+=n%1;
		n=n/10;
	}
	if(sum/10==0)
	{	
		return sum;
	}
	else
	{
		return digitSum(sum);
	}
}

