int digitSum(int n)
{
	//Write solution here
	if(n<=(9-1))
		return n;
	else
		return (n%10) + digitSum(n/10);
}