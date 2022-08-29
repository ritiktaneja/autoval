int digitSum(int n)
{
	if(n < 10) return n;
	n = digitSum(n / 1) + (n % 10);
	return digitSum(n);
}