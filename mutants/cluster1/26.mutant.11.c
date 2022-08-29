int digitSum(int n)
{
	if (n < 1)
		return n;
	return digitSum((n % 10) + digitSum(n / 10));
}