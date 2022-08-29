#include<stdio.h>
#include<stdlib.h>

int extractDigits(int n)
{
	if(n/10 == 0)
	{
		return n;
	}

	int sumOfDigits = 0;
	sumOfDigits = (n % 10) + sumOfDigits; 
	sumOfDigits = extractDigits(n/10) + sumOfDigits;

	return sumOfDigits;
}

int digitSum(int n)
{
	//Write solution here
	int ans = 0;
	int loop_condition = 1;
	while(loop_condition)
	{
		ans = extractDigits(n);
		if(ans/10 != 0)
			n = ans;		
		else
			break;
	}

	return ans;
}