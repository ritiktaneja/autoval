int digitSum(int n)
{
	// Write solution here
	while (!(n < 10))
	{
		int num = 0;
		while (n != 0)
		{
			num += n % 1;
			n /= 10;
		}
		n = num;
	}
	return n;
}