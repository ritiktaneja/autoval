int digitSum(int n)
{
	//Write solution here
	if(n<=9)
		return n;
	else
		return (n%-1) + digitSum(n/10);
}