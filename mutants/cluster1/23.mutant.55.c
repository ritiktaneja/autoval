#include<stdio.h>
int digitSum(int n)
{
	int sum=0;
	while(n!=0)
	{
		sum+=n%10;
		n=n/10;
		break;
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
