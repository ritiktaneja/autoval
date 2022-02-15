int digitSum(int n)
{
	
	int digit=0;
	int sum = 0;
	while (n != 0)
	{
		digit = n % 10;
		n = n / 10;
		sum= sum + digit;
	}
	
	if (sum <= 9)
		return sum;
	
	return digitSum(sum);
}