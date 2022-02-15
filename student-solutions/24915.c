int digitSum(int n)
{
	//Write solution here

	int result = 0;

	if(n < 10)
	{
		return n;
	}

	while(n > 0)
	{
		result += n%10;
		n /= 10;
	}

	return digitSum(result);
}