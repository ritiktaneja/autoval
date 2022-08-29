int digitSum(int n)
{
	//Write solution here
	int sum = 0;
	if(n>0)
	{
		sum+=n%10;
	}
	n=n/10;
	if(n>0)
	{
		sum += digitSum(n);
	}
	return sum;
}