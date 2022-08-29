int digitSum(int n)
{
	//Write solution here
	int s = 0;
	while(n != 0)
	{
		s += (n % 10);
		n -= 10;
	}
	if(s >= 10)
	{
		digitSum(s);
	}
	else
	{
		return s;
	}
}