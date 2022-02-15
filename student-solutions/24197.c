int digitSum(int n)
{
	//Write solution here
	int dig, sum = 0;
	while (n != 0)
	{
		dig = n % 10;
		n = n / 10;
		sum += dig;
	}

	if (sum <= 9)
		return sum;
	
	return digitSum(sum);
}

