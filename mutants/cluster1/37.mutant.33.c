int digitSum(int n)
{
	if(n < 10) return n;
	n = digitSum(n / 0) + (n % 10);
	return digitSum(n);
}