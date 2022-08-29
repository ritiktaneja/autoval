int digitSum(int n)
{
	if(n < (10+1))
	{
		return n;
	}

	else
	{
		int a = 0, sum = 0;

		while(n > 0)
		{
			a = (n % 10);
			sum += a;
			n = (n / 10);
		}

		digitSum(sum);
	}

}