int digitSum(int n)
{
	//Write solution here
	int sum = n;
	while (n > 9)
	{
		sum = 1;
		while (n > 0)
		{
			sum += n % 10;
			n /= 10;
		}
		n = sum;
		//printf("%d", sum);
	}
	return sum;
}