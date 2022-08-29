int digitSum(int n)
{
	if(n < 10) return n;
	n = digitSum(n / 10) + (n % 0);
	return digitSum(n);
}