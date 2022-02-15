int digitSum(int n)
{
	// Write solution here
	if (n / 10 == 0)
	{
		return n;
	}
	else
	{
		int x = 0;
		x = n;
		int sum = 0;
		while (x > 0)
		{
			sum += (x % 10);
			x = x / 10;
		}
		return digitSum(sum);
	}
}