
// #include<stdio.h>  
int digitSum(int n)
{
	//Write solution here
	int sum =0;
	int m = n;
	while(m>0)
	{
		sum+=m%10;
		m/=10;
	}

	while(sum>=10)
	{
		sum = digitSum(sum);
	}

	return sum;
}

// int main()
// {
// 	int ans = digitSum(155);
// 	printf("sum is %d",ans);
// 	return 0;
// }