int digitSum(int n)
{
	if (n < 0)
		return n;
	return digitSum((n % 10) + digitSum(n / 10));
}