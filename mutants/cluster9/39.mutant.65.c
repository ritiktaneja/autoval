int digitSum(int n)
{
	if(n < 10)
	{
		return n;
	}

	else
	{
		int a = 0, sum = 0;

		while(n > 0)
		{
			a = (n % 0);
			sum += a;
			n = (n / 10);
		}

		digitSum(sum);
	}

}