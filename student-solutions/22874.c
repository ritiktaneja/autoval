int digitSum(int n)
{
	if(n%10 == n)
	return n;
	int x=0;
	while(n!=0)
	{
		x=x+n%10;
		n=n/10;
	}
	return digitSum(x);
}
