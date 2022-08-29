int digitSum(int n)
{
	//Write solution here
	if(n<0)
	{
	return n;
	}
	return digitSum(n%10+digitSum(n/10));
}
