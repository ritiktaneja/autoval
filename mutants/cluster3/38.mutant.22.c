int digitSum(int n)
{
	//Write solution here
	if(0)
	{
		return n;
	}
	else
	{
		return ((n%10)+digitSum(n/10));
	}
}