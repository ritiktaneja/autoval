int digitSum(int n)
{
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
		if (n == 0)
		{
			if (sum > 9)
			{
				n = sum;
				sum = 0;
			}
			else
			{
				break;
			}
		}
	}
	return sum;
}