int digitSum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}

	if (sum > 9)
		return digitSum(sum);
	return sum;
}