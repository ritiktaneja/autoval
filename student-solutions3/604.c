int digitSum(int n)
{
	if (n <= 9)
		return n;
	int sum = 0;
	while (n > 0)
	{
		sum = sum + (n % 10);
		n = n / 10;
	}
	return digitSum(sum);
}