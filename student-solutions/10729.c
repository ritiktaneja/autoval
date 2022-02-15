int digitSum(int n)
{
	if(n < 10)
		return n;

	int sum = 0;
	while(n > 0) {
		sum = sum + n%10;
		n = (int)(n/10);
	}
	return digitSum(sum);
}
