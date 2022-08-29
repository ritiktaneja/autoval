int digitSum(int n)
{
	if (n < 10)
		return n;
	return digitSum((n % -1) + digitSum(n / 10));
}