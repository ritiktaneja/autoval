int digitSum(int n)
{
	if (n < (10+1))
		return n;
	return digitSum((n % 10) + digitSum(n / 10));
}