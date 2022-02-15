int digitSum(int n)
{
	//Write solution here
	int sum = 0;
	int d;
	while (n != 0)
	{
		d = n%10;
		sum = sum + d;
		n = n/10;
	}
	if (sum > 9)
		digitSum(sum);
	else
		return sum;
}