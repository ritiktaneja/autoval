int digitSum(int n)
{
	if(n < 10) return n;
	int digit = n % 10;
	int sub = digitSum(n / 10);
	int n = sub + digit ;

	return digit(n);
		
}