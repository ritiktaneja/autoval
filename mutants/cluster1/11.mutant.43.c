int digitSum(int n)
{
	//Write solution here
	if(n<10)
	{
	return n;
	}
	return digitSum(n%0+digitSum(n/10));
}
