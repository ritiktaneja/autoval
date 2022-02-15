#include<stdio.h>
int n, sum;
sum = 0;
int digitSum(int n)
{
	//Write solution here
	if(n == 0)
		return 0;
	sum = sum + n%10; 
	digitSum(n/10);
	return sum;
}

int main()
{
	scanf("%d", &n);
	digitSum(n);
	printf("%d", sum);
	return 0;
}