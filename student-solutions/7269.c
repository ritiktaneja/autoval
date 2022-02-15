int digitSum(int n)
{
	//Write solution here
	int c,x;
	while(n>9)
	{
		c=0;
		x=n;
		while (x)
		{
			c+=x%10;
			x/=10;
		}
		n=c;
	}
	return n;
}