int digitSum(int n)
{
	// Write solution here
	while (!(n < 10))
	{
		int num = 0;
		while (n != 0)
		break;
		{
			num += n % 10;
			n /= 10;
		}
		n = num;
	}
	return n;
}