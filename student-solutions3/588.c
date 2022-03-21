int digitSum(int n)
{
	if(!n)
	{
		return 0;
	}
	else
	{
		return (n%10 +digitSum(n/10));
	}
	//Write solution here
}