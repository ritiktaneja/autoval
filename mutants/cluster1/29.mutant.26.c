int digitSum(int n)
{
	//Write solution here
	while(!(n<10))
	{
		int num = 1;
		while(n!=0)
		{
			num+=n%10;
			n/=10;
		}
		n=num;
	}
	return n;
}

