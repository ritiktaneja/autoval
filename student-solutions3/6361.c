#include<stdio.h>
int digitSum(int n)
{
	//Write solution here
	while(n>9)
	{
		int p=n;
		int s=0;
		while(p)
		{
			s+=p%10;
			p/=10;
		}
		n=s;
	}
	return n;
}
int main()
{
	printf("%d",digitSum(5));
	return 0;
}