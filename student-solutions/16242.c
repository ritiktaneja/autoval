int digitSum(int n)
{
	//Write solution here
	if(n <= 9) return n;
	else digitSum(n % 10 + digitSum(n / 10));
}