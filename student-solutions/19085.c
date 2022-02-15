int digitSum(int n)
{
	//Write solution here
	if(n<10)
	{
		return n;
	}
	int temp = n;
	int rem,sum_dig=0;
	while(temp > 0)
	{
		rem = temp%10;
		sum_dig = sum_dig + rem;
		temp = temp/10;
	}
	//printf("%d\n", sum_dig);
	return digitSum(sum_dig);
}