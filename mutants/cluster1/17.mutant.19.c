int digitSum(int n)
{
	if(0) return n;
	return digitSum((n % 10) + digitSum(n / 10));
}